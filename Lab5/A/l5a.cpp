#include <cstdio>
#include <queue>
#include <algorithm>

using namespace std;
using ll = long long;

#define rep(i, a, b) for (int i = (a); i <= (b); ++i)

const int MAX_N = 1e5 + 10;

struct store {
    int pr;
    int w;
} ss[MAX_N];

int n, m;

int read();

void init();

ll buy();

int main() {
    init();

    printf("%lld", buy());

    return 0;
}

void init() {
    n = read();
    m = read();
    rep(i, 1, n) ss[i].pr = read();
    rep(i, 1, n) ss[i].w = read();
}

ll buy() {
    ll ans = 0;
    priority_queue<ll, vector<ll>, greater<>> pq;

    int sub, change;
    rep(i, 1, n) {
        sub = ss[i].pr % 100;
        change = 100 - sub;

        if (m < sub) {
            m += change;
            pq.push(ss[i].w * change);
            ans += pq.top();
            pq.pop();
        } else {
            m -= sub;
            if (sub != 0) pq.push(ss[i].w * change);
        }
    }

    return ans;
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
