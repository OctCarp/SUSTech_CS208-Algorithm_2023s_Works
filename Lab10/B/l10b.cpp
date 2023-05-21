#include <cstdio>
#include <cstring>
#include <algorithm>

using namespace std;

#define s1 s[l]
#define s2 s[l + 1]
#define s3 s[r - 1]
#define s4 s[r]

const int MAX_N = 2010;

int T, n;

char s[MAX_N];

int dfs(int l, int r);

int main() {
    scanf("%d", &T);

    while (T--) {
        scanf("%s", &s);

        n = strlen(s);

        switch (dfs(0, n - 1)) {
            case 0:
                printf("Draw\n");
                break;
            case 1:
                printf("Alice\n");
                break;
            case -1:
                printf("Bob\n");
                break;
            default:
                printf("Alice\n");
        }
    }

    return 0;
}

int dfs(int l, int r) {
    if (r - l == 1) { return s1 == s4 ? 0 : 1; }

    if (s1 < s4) {
        if (s1 < s2) {
            return 1;
        } else if (s1 > s2) {
            return -1;
        } else {
            return dfs(l + 2, r);
        }
    } else if (s4 < s1) {
        if (s4 < s3) {
            return 1;
        } else if (s4 > s3) {
            return -1;
        } else {
            return dfs(l, r - 2);
        }
    } else {
        if (s1 > s2 && s4 > s3) {
            return -1;
        } else {
            if (s1 == s2 && s2 > s3) {
                return min(dfs(l + 2, r), dfs(l + 1, r - 1));
            } else if (s3 == s4 && s2 < s3) {
                return min(dfs(l, r - 2), dfs(l + 1, r - 1));
            } else {
                return dfs(l + 1, r - 1);
            }
        }
    }
}
