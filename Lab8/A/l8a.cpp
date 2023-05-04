#include <cstdio>
#include <vector>
#include <algorithm>

using namespace std;
using ll = long long;

#define pb push_back
#define rep(i, a, b) for (int i = (a); i <= (b); ++i)

const int MAX_N = 1e5 + 10;
const ll max_d = 1e14 + 10;

int n;

struct point {
    int x;
    int y;

    bool operator<(const point &a) const { return y < a.y; }
} ps[MAX_N];

inline ll dis_sq(point &p1, point &p2) {
    return (ll) (p1.x - p2.x) * (p1.x - p2.x) + (ll) (p1.y - p2.y) * (p1.y - p2.y);
}

bool cmp(const point &p1, const point &p2) { return p1.x < p2.x; }

int read();

ll min_dis(int l, int r);

int main() {
    n = read();
    rep(i, 1, n) {
        ps[i].x = read();
        ps[i].y = read();
    }

    sort(ps + 1, ps + 1 + n, cmp);

    printf("%lld", min_dis(1, n));

    return 0;
}

ll min_dis(int l, int r) {
    ll dis = max_d;

    if (r - l == 0) return dis;
    if (r - l == 1) return dis_sq(ps[l], ps[r]);

    int mid = l + ((r - l) >> 1);
    ll dl = min_dis(l, mid);
    ll dr = min_dis(mid + 1, r);
    dis = min(dl, dr);

    vector<int> rps;

    rep(i, l, r) {
        if (abs(ps[i].x - ps[mid].x) <= dis) rps.pb(i);
    }

    sort(rps.begin(), rps.end());

    int sz = (int) rps.size();
    rep(i, 0, sz - 1) {
        rep(j, i + 1, sz - 1) {
            if ((ps[rps[j]].y - ps[rps[i]].y) <= dis) {
                dis = min(dis, dis_sq(ps[rps[j]], ps[rps[i]]));
            } else break;
        }
    }

    return dis;
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
