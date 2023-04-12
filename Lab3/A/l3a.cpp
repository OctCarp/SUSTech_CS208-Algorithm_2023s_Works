#include <cstdio>
#include <vector>
#include <numeric>
#include <algorithm>

using namespace std;
using ll = long long;

#define rep(i, a, b) for (int i = (a); i <= (b); ++i)
#define pb push_back

int n, m;
ll b_sum;
vector<int> as;
vector<int> bs;

int read();

void writeL(ll x);

void init();

ll fill_blanks();

ll collect_apples();

int main() {
    init();

    writeL(n < b_sum ? collect_apples() : fill_blanks());

    return 0;
}

void init() {
    n = read();
    m = read();
    rep(i, 1, m) bs.pb(read());
    rep(i, 1, n) as.pb(read());

    b_sum = accumulate(bs.begin(), bs.end(), 0);
    sort(bs.begin(), bs.end());
}

ll fill_blanks() {
    int p_a = -1;
    int p_b = -1;

    ll dis = 0;
    while (++p_b < m) {
        p_a += bs[p_b];
        dis += as[p_a];
    }

    return dis << 1;
}

ll collect_apples() {
    int p_a = n - 1;
    int p_b = m;

    ll dis = 0;
    while (p_a >= 0) {
        dis += as[p_a];
        p_a -= bs[--p_b];
    }

    return dis << 1;
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

void writeL(ll x) {
    if (x < 0) putchar('-'), x = -x;
    if (x > 9) writeL(x / 10), putchar(x % 10 + '0');
    else putchar(x + '0');
}
