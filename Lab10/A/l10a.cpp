#include <cstdio>
#include <algorithm>

using namespace std;

#define rep(i, a, b) for (int i = (a); i <= (b); ++i)

const int MAX_NM = 5e3 + 10;

struct item {
    int w;
    int c;
} is[MAX_NM];

int n, m;
int M[MAX_NM][MAX_NM];

int read();

int buy() {
    rep(c, 0, m) M[0][c] = 0;

    rep(i, 1, n) {
        rep(j, 1, m) {
            M[i][j] = is[i].c > j ? M[i - 1][j] : max(M[i - 1][j], is[i].w + M[i - 1][j - is[i].c]);
        }
    }

    return M[n][m];
}

int main() {
    n = read(), m = read();
    rep(i, 1, n) is[i].w = read();
    rep(i, 1, n) is[i].c = read();

    printf("%d\n", buy());

    return 0;
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
