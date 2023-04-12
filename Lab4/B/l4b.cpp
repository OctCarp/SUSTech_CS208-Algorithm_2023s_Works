#include <cstdio>
#include <algorithm>

using namespace std;
using ll = long long;

#define rep(i, a, b) for (int i = (a); i <= (b); ++i)

const int MAX_N =5010;

struct fruit {
    int l;
    int r;
    int v;
    int ts_l;
} fs[MAX_N];

struct slot {
    int num;
    int fid;
    bool idle = true;
} ts[MAX_N];

int n;
ll ans = 0;

bool l_cmp(fruit &f1, fruit &f2) { return f1.l < f2.l; }

bool v_cmp(fruit &f1, fruit &f2) { return f1.v > f2.v; }

int read();

void init();

bool linear_match(int in, int a_val);

int main() {
    init();

    sort(fs + 1, fs + 1 + n, v_cmp);

    rep(i, 1, n) if (linear_match(i, fs[i].ts_l)) ans += fs[i].v;

    printf("%lld", ans);

    return 0;
}

void init() {
    n = read();

    rep(i, 1, n) {
        fs[i].l = read();
        fs[i].r = read();
        fs[i].v = read();
    }

    sort(fs + 1, fs + 1 + n, l_cmp);

    int cur = 0, ts_cnt = 0;
    rep(i, 1, n) {
        cur = max(fs[i].l, cur + 1);
        ts[++ts_cnt].num = cur;
    }

    int ts_p = 0;
    rep(i, 1, n) {
        while (fs[i].l > ts[ts_p].num) ++ts_p;

        fs[i].ts_l = ts_p;
    }
}

bool linear_match(int in, int tx) {
    if (tx > n || ts[tx].num > fs[in].r) return false;

    if (ts[tx].idle) {
        ts[tx].idle = false;
        ts[tx].fid = in;
        return true;
    }

    if (fs[in].r >= fs[ts[tx].fid].r) {
        return linear_match(in, tx + 1);
    } else {
        if (linear_match(ts[tx].fid, tx + 1)) {
            ts[tx].fid = in;
            return true;
        }
    }

    return false;
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
