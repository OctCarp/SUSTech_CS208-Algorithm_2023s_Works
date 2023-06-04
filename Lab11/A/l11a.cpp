#include <cstdio>
#include <cstring>
#include <vector>
#include <algorithm>

using namespace std;
using ll = long long;

#define rep(i, a, b) for (int i = (a); i <= (b); ++i)
#define dwn(i, a, b) for (int i = (a); i >= (b); --i)
#define pb push_back

const int MAX_N = 2100;
const int MOD = 1e9 + 7;

#define mod(x) ((x) % MOD)

int n, k, cur;
int ws = 0, invws;
bool isv[MAX_N] = {false};

struct client {
    int w;
    int ip;
    int np;
    vector<int> adj;
} c[MAX_N];

int p[MAX_N][MAX_N];

inline int mul_m(ll a, ll b) { return mod(mod(a) * mod(b)); }

inline int plus_m(ll a, ll b) { return mod(mod(a) + mod(b)); }

inline int inv(ll a) {
    int ans = 1;
    int b = MOD - 2;
    a = mod(mod(a) + MOD);
    for (; b; b >>= 1) {
        if (b & 1) ans = mod(a * ans);
        a = mod(a * a);
    }
    return ans;
}

int read();

void init();

int dfs(int root);

int main() {
    int ans = 0;

    init();
    invws = inv(ws);

    rep(i, 1, n) {
        memset(isv, false, sizeof(isv));
        memset(p, 0, sizeof(int) * MAX_N * MAX_N);
        cur = i;

        dfs(i);
        ans = plus_m(ans, p[i][k]);
    }

    printf("%d", ans);

    return 0;
}

void init() {
    n = read();
    k = read();

    int u, v;
    rep(i, 1, n - 1) {
        u = read();
        v = read();
        c[u].adj.pb(v);
        c[v].adj.pb(u);
    }

    int w, a, b;
    rep(i, 1, n) {
        w = read();
        ws += w;
        c[i].w = w;
        a = read();
        b = read();
        int invb = inv(b);

        c[i].ip = mul_m(a, invb);
        c[i].np = mul_m(b - a, invb);
    }
}

int dfs(int root) {
    isv[root] = true;

    int ch_cnt = 1;
    if (root == cur) {
        p[root][1] = mul_m(c[root].w, invws);
        p[root][0] = mul_m(ws - c[root].w, invws);
    } else {
        p[root][0] = c[root].np;
        p[root][1] = c[root].ip;
    }


    for (int a: c[root].adj) {
        if (!isv[a]) {
            int child = dfs(a);

            dwn(i, ch_cnt + child, 1) {
                int unit = 0;
                rep(j, 1, min(j, ch_cnt)) {
                    unit = plus_m(unit, mul_m(p[root][j], p[a][i - j]));
                }
                p[root][i] = unit;
            }

            ch_cnt += child;
        }
    }

    return ch_cnt;
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
