#include <cstdio>
#include <cstring>
#include <vector>
#include <algorithm>

using namespace std;
using pii = pair<int, int>;

#define rep(i, a, b) for (int i = (a); i <= (b); ++i)
#define eb emplace_back
#define s first
#define e second

const int MAX_S = 1e5 + 10;
const int MAX_F = 1e4 + 10;

int n, sl;
char S[MAX_S];
vector<pii> is;

bool cmp(pii a, pii b) {
    if (a.e != b.e) return a.e < b.e;
    return a.s < b.s;
}

void find_once();

int main() {
    scanf("%s %d", S + 1, &n);
    sl = strlen(S + 1);

    while (n--) {
        find_once();
    }

    int ans = 0;
    if (!is.empty()) {
        sort(is.begin(), is.end(), cmp);

        ans = 1;
        int START = is[0].e;
        for (pii interval: is) {
            if (interval.s > START) {
                ++ans;
                START = interval.e;
            }
        }
    }

    printf("%d", ans);

    return 0;
}

void find_once() {
    char f[MAX_F];
    int fn[MAX_F];
    scanf("%s", f + 1);

    int fl = strlen(f + 1);

    int p = 0;
    fn[1] = 0;
    rep(i, 2, fl) {
        while (p > 0 && f[i] != f[p + 1]) {
            p = fn[p];
        }
        if (f[i] == f[p + 1]) ++p;

        fn[i] = p;
    }

    p = 0;
    rep(i, 1, sl) {
        while (p > 0 && S[i] != f[p + 1]) {
            p = fn[p];
        }
        if (S[i] == f[p + 1]) ++p;

        if (p == fl) {
            is.eb(i - fl + 1, i);
            p = fn[p];
        }
    }
}
