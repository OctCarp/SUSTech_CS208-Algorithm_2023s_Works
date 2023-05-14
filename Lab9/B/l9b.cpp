#include <cstdio>
#include <algorithm>

using namespace std;

const int MAX_N = 5e4 + 10;

struct room {
    int l, r;
    int ll, rl, ml;
    int len;
    int tag;

    void init(int l_in, int r_in) {
        l = l_in, r = r_in;
        ll = rl = ml = len = r - l + 1;;
        tag = 0;
    }

    void lazy(int opt) {
        tag = opt;
        ll = rl = ml = (opt == 1 ? 0 : len);
    }

    inline int partial() const { return r - rl + 1; }

    inline bool full() const { return ml == len; }
} h[MAX_N << 2];

int n, m;

int read();

void write(int x);

void build_tree(int rt, int l, int r);

int ck_in_id(int rt, int x);

void upd_tree(int rt, int l, int r, int opt);

int main() {
    n = read(), m = read();
    build_tree(1, 1, n);

    int opt;
    while (m--) {
        opt = read();
        if (opt == 1) {
            int x = read();
            int id = ck_in_id(1, x);
            write(id);
            putchar('\n');

            if (id) upd_tree(1, id, id + x - 1, 1);
        } else {
            int l = read(), r = read();
            upd_tree(1, l, r, 2);
        }
    }

    return 0;
}

void build_tree(int rt, int l, int r) {
    h[rt].init(l, r);
    if (l < r) {
        int mid = l + ((r - l) >> 1);
        build_tree(rt << 1, l, mid);
        build_tree(rt << 1 | 1, mid + 1, r);
    }
}

int ck_in_id(int rt, int x) {
    if (x == 1 && h[rt].len == 1) { return h[rt].l; }

    int lc = rt << 1, rc = rt << 1 | 1;

    if (h[rt].tag) {
        h[lc].lazy(h[rt].tag);
        h[rc].lazy(h[rt].tag);
        h[rt].tag = 0;
    }

    if (h[lc].ml >= x) {
        return ck_in_id(lc, x);
    } else if (h[lc].rl + h[rc].ll >= x) {
        return h[lc].partial();
    } else if (h[rc].ml >= x) {
        return ck_in_id(rc, x);
    } else return 0;
}

void upd_tree(int rt, int l, int r, int opt) {
    if (h[rt].l > r || h[rt].r < l) { return; }
    if (l <= h[rt].l && h[rt].r <= r) {
        h[rt].lazy(opt);
        return;
    }

    int lc = rt << 1, rc = rt << 1 | 1;

    if (h[rt].tag) {
        h[lc].lazy(h[rt].tag);
        h[rc].lazy(h[rt].tag);
        h[rt].tag = 0;
    }

    l = max(h[rt].l, l);
    r = min(h[rt].r, r);
    upd_tree(lc, l, r, opt);
    upd_tree(rc, l, r, opt);

    h[rt].ll = h[lc].full() ? (h[lc].len + h[rc].ll) : h[lc].ll;
    h[rt].rl = h[rc].full() ? (h[lc].rl + h[rc].len) : h[rc].rl;
    h[rt].ml = max(max(h[lc].ml, h[rc].ml), h[lc].rl + h[rc].ll);
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
