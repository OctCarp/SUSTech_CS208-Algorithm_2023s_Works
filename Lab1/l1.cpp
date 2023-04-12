#include <iostream>
#include <string>
#include <unordered_map>
#include <queue>

using namespace std;

#define rep(i, a, b) for (int i = (a); i <= (b); ++i)

const int MAX_N = 1005;

struct man {
    string name;
    int wife = -1;
    int w_rank[MAX_N] = {0};
} ms[MAX_N];

struct woman {
    string name;
    int hb = -1;
    int m_pref[MAX_N] = {0};
} wms[MAX_N];

int n;
unordered_map<string, int> men_map;
unordered_map<string, int> women_map;

inline void disable_syn() { std::ios_base::sync_with_stdio(0), std::cin.tie(0), std::cout.tie(0); }

void read_data();

void init_rank();

void stable_match();

int main() {
    disable_syn();
    read_data();
    init_rank();
    stable_match();

    rep(i, 1, n) {
        cout << ms[i].name << ' ' << wms[ms[i].wife].name << '\n';
    }

    return 0;
}

void read_data() {
    cin >> n;

    rep(i, 1, n) {
        string name_in;
        cin >> name_in;
        ms[i].name = name_in;
        men_map.insert({name_in, i});
    }

    rep(i, 1, n) {
        string name_in;
        cin >> name_in;
        wms[i].name = name_in;
        women_map.insert({name_in, i});
    }
}

void init_rank() {
    rep(i, 1, n) {
        rep(j, 1, n) {
            string name_in;
            cin >> name_in;
            ms[i].w_rank[j] = women_map[name_in];
        }
    }

    rep(i, 1, n) {
        rep(j, 1, n) {
            string name_in;
            cin >> name_in;
            wms[i].m_pref[men_map[name_in]] = j;
        }
    }
}

void stable_match() {
    queue<int> q;
    rep(i, 1, n) q.push(i);

    int offer_time[MAX_N] = {0};

    while (!q.empty()) {
        int m_p = q.front();
        q.pop();

        int w_p = ms[m_p].w_rank[++offer_time[m_p]];
        int ori_hub = wms[w_p].hb;

        if (ori_hub == -1) {
            ms[m_p].wife = w_p;
            wms[w_p].hb = m_p;
        } else {
            if (wms[w_p].m_pref[m_p] < wms[w_p].m_pref[ori_hub]) {
                q.push(ori_hub);
                ms[m_p].wife = w_p;
                wms[w_p].hb = m_p;
            } else {
                q.push(m_p);
            }
        }
    }
}

