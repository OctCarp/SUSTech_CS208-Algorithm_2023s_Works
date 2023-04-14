#include <stdio.h>

#define int long long

int pow2(int n) {
    int res = 1;
    while (n--) res = res << 1;

    return res;
}

int check(int base, int x, int y) {
    if (base == 0) {
        return 1;
    } else {
        int block, x1, y1;
        if (x <= base) {
            if (y <= base) {
                block = 0;
                x1 = y, y1 = x;
            } else {
                block = 1;
                x1 = x, y1 = y - base;
            }
        } else {
            if (y <= base) {
                block = 3;
                x1 = base + 1 - y, y1 = base + 1 - (x - base);
            } else {
                block = 2;
                x1 = x - base, y1 = y - base;
            }
        }

        return block * base * base + check(base >> 1, x1, y1);
    }
}

signed main() {
    int n, x, y;
    scanf("%lld %lld %lld", &n, &x, &y);
    printf("%lld", check(pow2(n - 1), x, y));

    return 0;
}
