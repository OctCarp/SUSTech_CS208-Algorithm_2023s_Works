#include <cstdio>
#include <vector>
#include <algorithm>

using namespace std;

#define rep(i, a, b) for (int i = (a); i <= (b); ++i)
#define pb push_back

const int MAX_N = 1e5 + 10;

struct vertex {
    int fa = 0;
    vector<int> adj;
} vs[MAX_N];

int n, k, ans;

int read();

int dfs(int cur);

int main() {
    n = read();
    k = read();

    int u, v;
    rep(i, 1, n - 1) {
        u = read();
        v = read();
        vs[u].adj.pb(v);
        vs[v].adj.pb(u);
    }

    int root = 1;
    rep(i, 1, n) {
        if (vs[i].adj.size() > 1) {
            root = i;
            break;
        }
    }

    vs[root].fa = 0;
    dfs(root);

    printf("%d\n", ans + 1);
    return 0;
}

int dfs(int cur) {
    if (vs[cur].adj.size() == 1) { return 0; }

    vector<int> t;
    for (int a: vs[cur].adj) {
        if (a != vs[cur].fa) {
            vs[a].fa = cur;
            int d = dfs(a);

            t.pb(d + 1);
        }
    }

    sort(t.begin(), t.end());

    int len = t.size();
    while (--len) {
        if (t[len] + t[len - 1] <= k) {
            break;
        } else {
            ++ans;
        }
    }

    return t[len];
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
