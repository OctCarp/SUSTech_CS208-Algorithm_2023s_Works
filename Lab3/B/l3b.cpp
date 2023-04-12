#include <cstdio>
#include <queue>
#include <map>

using namespace std;
using pii = pair<int, int>;

#define rep(i, a, b) for (int i = (a); i <= (b); ++i)
#define pb push_back

const int MAX_N = 2e5 + 10;

typedef struct new_vertex {
    int ind;
    int dis;
    vector<int> adj;

    inline void init() {
        ind = 0;
        adj.clear();
    }
} nv;

int T, n, m;

int fa[MAX_N];
vector<int> ig[MAX_N];
vector<int> new_v;
nv ng[MAX_N];

int read();

void write(int x);

inline int find(int x) { return x == fa[x] ? x : (fa[x] = find(fa[x])); }

void init();

bool merge_check();

void find_w();

int main() {
    T = read();
    while (T--) {
        init();
        if (!merge_check()) {
            printf("No\n");
        } else {
            printf("Yes\n");
            find_w();
        }
    }

    return 0;
}

void init() {
    n = read();
    m = read();

    rep(i, 1, n) ng[i].init();
    new_v.clear();

    rep(i, 1, n) {
        fa[i] = i;
        ig[i].clear();
    }

    int a, b;
    while (m--) {
        a = read(), b = read();
        ig[b].pb(a);
    }
}

bool merge_check() {
    rep(i, 1, n) {
        if (ig[i].size() >= 2) {
            int p = find(ig[i][0]);
            for (int a: ig[i]) fa[find(a)] = p;
        }
    }

    map<pii, bool> m_edge;
    int i_f, a_f;
    rep(i, 1, n) {
        i_f = find(i);
        if (i_f == i)new_v.pb(i);

        for (int a: ig[i]) {
            a_f = find(a);
            if (i_f == a_f) {
                return false;
            } else {
                if (!m_edge[{a_f, i_f}]) {
                    m_edge[{a_f, i_f}] = true;
                    ng[a_f].adj.pb(i_f);
                    ++ng[i_f].ind;
                }
            }
        }
    }

    int cnt = 0;
    queue<int> q;
    int p;
    q.push(fa[1]);
    ng[fa[1]].dis = 0;

    while (!q.empty()) {
        p = q.front();
        q.pop();
        ++cnt;

        for (int a: ng[p].adj) {
            if (!--ng[a].ind) {
                q.push(a);
                ng[a].dis = ng[p].dis + 1;
            }
        }
    }

    return cnt == new_v.size();
}

void find_w() {
    write(1);
    putchar(' ');
    rep(i, 2, n) {
        write(ng[fa[i]].dis - ng[fa[ig[i][0]]].dis);
        putchar(' ');
    }
    putchar('\n');
}

int read() {
    int s = 0, f = 1;
    char ch = getchar();
    while (ch < '0' || ch > '9') {
        if (ch == '-') f = -f;
        ch = getchar();
    }
    while (ch >= '0' && ch <= '9') s = (s << 1) + (s << 3) + (ch ^ '0'), ch = getchar();
    return s * f;
}

void write(int x) {
    if (x < 0) putchar('-'), x = -x;
    if (x > 9) write(x / 10), putchar(x % 10 + '0');
    else putchar(x + '0');
}