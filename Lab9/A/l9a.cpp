#include <cstdio>
#include <cstring>

using namespace std;

#define rep(i, a, b) for (int i = (a); i <= (b); ++i)
#define dwn(i, a, b) for (int i = (a); i >= (b); --i)

const int MAX_N = 1e5 + 10;
int n, m;
int a[MAX_N];

int sh;
int tr[MAX_N << 2];

int read();

void write(int x);

void build_tree();

void query();

void change();

int main() {
    n = read(), m = read();
    rep(i, 1, n) a[i] = read();

    build_tree();

    int is_query;
    while (m--) {
        is_query = read();
        is_query ? query() : change();
    }

    return 0;
}

void tree() {
    sh = 1;
    while (sh < n + 2)sh <<= 1;

    memcpy(tr + sh + 1, a + 1, n * sizeof(int));
    dwn(i, sh - 1, 1) tr[i] = tr[i << 1] + tr[i << 1 | 1];
}

void query() {
    int l = read() + sh - 1;
    int r = read() + sh + 1;

    int sum = 0;
    while (l ^ r ^ 1) {
        if (~l & 1) sum += tr[l + 1];
        if (r & 1) sum += tr[r - 1];
        l >>= 1, r >>= 1;
    }

    write(sum);
    putchar('\n');
}

void change() {
    int x = read(), v = read();
    int diff = v - a[x];
    a[x] = v;

    for (int p = x + sh; p > 0; p >>= 1) tr[p] += diff;
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
