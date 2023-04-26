#include <cstdio>
#include <cstring>
#include <cmath>
#include <numeric>

using namespace std;

#define rep(i, a, b) for (int i = (a); i <= (b); ++i)

const int MAX_N = 1e5 + 10;

int n;
int st[MAX_N][30];
int a[MAX_N];

int read();

void init();

inline int query(int l, int r);

int friends();

int main() {
    init();

    printf("%d\n", friends());

    return 0;
}

void init() {
    n = read();
    rep(i, 1, n) a[i] = read();

    memset(st, 0, sizeof(st));
    rep(i, 1, n - 1) st[i][0] = abs(a[i + 1] - a[i]);

    int interval = 1;
    int end_point = n - 1 - interval;
    rep(j, 1, (int) log2(n)) {
        rep(i, 1, end_point) {
            st[i][j] = gcd(st[i][j - 1], st[i + interval][j - 1]);
        }
        interval <<= 1;
        end_point -= interval;
    }
}

int query(int l, int r) {
    int s = (int) log2(r - l + 1);
    return gcd(st[l][s], st[r - (1 << s) + 1][s]);
}

int friends() {
    int ans = 0;
    rep(i, 1, n - 1) {
        if (i + ans > n - 1) break;

        int l = 1, r = n - i + 1;
        int mid;
        while (l < r) {
            mid = l + ((r - l) >> 1);

            if (query(i, i + (mid - 1)) > 1) {
                l = mid + 1;
            } else {
                r = mid;
            }
        }

        ans = max(ans, l - 1);
    }

    return ans + 1;
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
