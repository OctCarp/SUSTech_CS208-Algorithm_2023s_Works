#include <cstdio>
#include <queue>
#include <algorithm>

using namespace std;
using ll = long long;

#define rep(i, a, b) for (int i = (a); i <= (b); ++i)

const int MAX_N = 2e5 + 10;

struct stu {
    int m;
    int c;
} ss[MAX_N];

int T, n;

bool cmp(const stu &s1, const stu &s2) { return s1.m > s2.m; }

int read();

void writeL(ll x);

void init();

ll vote();

int main() {
    T = read();
    while (T--) {
        init();
        writeL(vote());
        putchar('\n');
    }

    return 0;
}

void init() {
    n = read();
    rep(i, 1, n) {
        ss[i].m = read();
        ss[i].c = read();
    }

    sort(ss + 1, ss + 1 + n, cmp);
    ss[n + 1].m = -1;
}

ll vote() {
    ll cost = 0;
    priority_queue<int, vector<int>, greater<>> pq;

    rep(i, 1, n) {
        pq.push(ss[i].c);

        if (ss[i].m != ss[i + 1].m) {
            int need = ss[i].m - (n - pq.size());
            if (need > 0) {
                while (need--) {
                    cost += pq.top();
                    pq.pop();
                }
            }
        }
    }

    return cost;
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
    if (x < 0)putchar('-'), x = -x;
    if (x > 9)writeL(x / 10), putchar(x % 10 + '0');
    else putchar(x + '0');
}
