#include <cstdio>
#include <queue>

using namespace std;

#define rep(i, a, b) for (int i = (a); i <= (b); ++i)
#define pb push_back

const int MAX_N = 3e4 + 10;
const int MAX_K = 1e5 + 10;

struct village {
    int d = -1;
    bool is_v = false;
    vector<int> adj;
} g[MAX_N];

int n, m, p, q;
int ans[MAX_K
] = {
                0};

int read();

void write(int x);

void init();

void bfs();

void query();

int main() {
    init();
    bfs();
    query();

    while (q--) {
        write(ans[read()]);
        putchar(' ');
    }

    return 0;
}

void init() {
    n = read();
    m = read();
    p = read();
    q = read();

    int a, b;
    while (m--) {
        a = read();
        b = read();
        g[a].adj.pb(b);
        g[b].adj.pb(a);
    }
}

void bfs() {
    queue<int> que;

    g[p].is_v = true;
    g[p].d = 0;
    que.push(p);
    while (!que.empty()) {
        int cur = que.front();
        que.pop();

        for (int a: g[cur].adj) {
            if (!g[a].is_v) {
                g[a].is_v = true;
                g[a].d = g[cur].d + 1;
                que.push(a);
            }
        }
    }
}

void query() {
    rep(i, 1, n) {
        if (g[i].d >= 0) {
            ++ans[g[i].d];
        }
    }

    rep(i, 1, MAX_K) ans[i] += ans[i - 1];
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
