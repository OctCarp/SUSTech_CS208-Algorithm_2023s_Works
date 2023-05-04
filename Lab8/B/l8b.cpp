#include <cstdio>
#include <cstdlib>
#include <algorithm>

using namespace std;

#define rep(i, a, b) for (int i = (a); i <= (b); ++i)

const int MAX_N = 5e4 + 10;

int n, a[MAX_N];

inline int read();

inline void write(int x);

inline void print_b(int lb, int rb) { write(lb), putchar(' '), write(rb), putchar('\n'); }

inline int generate_r(int l, int r) { return (rand() % (r - l + 1)) + l; }

inline bool all_same(int l, int r) {
    int flag = a[l];
    rep(i, l + 1, r - 1) if (a[i] != flag) return false;
    return true;
}

int merge(int l, int mid, int lb, int rb);

int merge_main(int p, int l, int r);

void q_answer(int low, int high);

int main() {
    n = read();
    rep(i, 1, n)a[i] = read();

    if (!all_same(1, n + 1)) { q_answer(1, n + 1); }

    print_b(-1, -1);

    return 0;
}

int merge(int l, int mid, int lb, int rb) {
    int L = l + lb, R = mid + rb;
    if (R - L > 1) {
        print_b(L, R - 1);
        reverse(a + L, a + R);
    }

    return lb + rb;
}

int merge_main(int p, int l, int r) {
    if (r - l <= 1) { return a[l] <= p ? 1 : 0; }

    int mid = l + ((r - l) >> 1);
    int lb = merge_main(p, l, mid);
    int rb = merge_main(p, mid, r);

    return merge(l, mid, lb, rb);
}

void q_answer(int low, int high) {
    int p = a[generate_r(low, high - 1)];
    int bdy = merge_main(p, low, high);

    if (!all_same(low, low + bdy)) { q_answer(low, low + bdy); }
    if (!all_same(low + bdy, high)) { q_answer(low + bdy, high); }
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
