#include <cstdio>
#include <cstring>
#include <vector>

using namespace std;

#define rep(i, a, b) for (int i = (a); i <= (b); ++i)
#define pb push_back

const int MAX_N = 2100;

int n = 0;

int d[MAX_N];
int fa[MAX_N];
bool v[MAX_N];
vector<int> g_adj[MAX_N];

int read();

void write(int x);

void init();

int check_circle();

int main() {
    int T = read();
    while (T--) {
        init();

        write(check_circle());
        putchar('\n');
    }

    return 0;
}

void init() {
    rep(i, 1, n << 1) g_adj[i].clear();
    n = read();

    int m = read();
    while (m--) {
        int x = read(), y = read();
        y += n;
        g_adj[x].pb(y);
        g_adj[y].pb(x);
    }
}


int check_circle() {
    int ans = MAX_N;

    rep(i, 1, n) {
        memset(v, false, sizeof v);
        int q[MAX_N], front = 0, rear = 0;

        q[++rear] = i;
        d[i] = 0;
        fa[i] = -1;
        v[i] = true;

        int p;
        while (front != rear) {
            p = q[++front];
            for (int a: g_adj[p]) {
                if (a != fa[p]) {
                    if (v[a]) {
                        int sum = d[p] + d[a] + 1;
                        if (sum < ans) {
                            if (sum == 4) return 4;
                            ans = sum;
                        }
                    } else {
                        d[a] = d[p] + 1;
                        fa[a] = p;
                        v[a] = true;
                        q[++rear] = a;
                    }
                }
            }
        }
    }

    return ans == MAX_N ? -1 : ans;
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