#include <cstdio>
#include <queue>
#include <algorithm>

using namespace std;
using ll = long long;
using pii = pair<int, int>;

#define rep(i, a, b) for (int i = (a); i <= (b); ++i)

const int MAX_N = 5e4 + 10;

struct item {
    int p;
    int c;
    int dis;

    inline void set(int p_in, int c_in) {
        p = p_in;
        c = c_in;
        dis = p - c;
    }
} is[MAX_N];

int n, k;
ll m;

bool has[MAX_N] = {false};
priority_queue<int, vector<int>, greater<>> d_que;
priority_queue<pii, vector<pii>, greater<>> p_que, c_que;

int read();

ll readL();

int buy();

int main() {
    n = read();
    m = readL();
    k = read();

    int p, c;
    rep(i, 1, n) {
        p = read();
        c = read();
        is[i].set(p, c);
    }

    printf("%d\n", buy());

    return 0;
}

int buy() {
    ll sum = 0;

    rep(i, 1, k) d_que.push(0);

    rep(i, 1, n) {
        p_que.emplace(is[i].p, i);
        c_que.emplace(is[i].c, i);
    }

    int cnt = 0;
    rep(i, 1, n) {
        while (has[p_que.top().second]) p_que.pop();
        while (has[c_que.top().second]) c_que.pop();

        if (d_que.empty()) {
            d_que.push(2e9);
        }

        int replace = c_que.top().first + d_que.top();
        int direct = p_que.top().first;

        int id;
        if (replace < direct) {
            id = c_que.top().second;
            sum += replace;
            d_que.pop();
            d_que.push(is[id].dis);
        } else {
            id = p_que.top().second;
            sum += direct;
        }

        if (sum > m) break;

        has[id] = true;
        ++cnt;
    }

    return cnt;
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

ll readL() {
    ll s = 0, f = 1;
    char ch = getchar();
    while (ch < '0' || ch > '9') {
        if (ch == '-') f = -f;
        ch = getchar();
    }
    while (ch >= '0' && ch <= '9') s = (s << 1) + (s << 3) + (ch ^ '0'), ch = getchar();
    return s * f;
}
