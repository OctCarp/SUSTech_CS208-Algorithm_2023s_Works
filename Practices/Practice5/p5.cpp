#include <iostream>
#include <algorithm>

#define MAX_SIZE 1005

using namespace std;

struct interval {
    int s;
    int e;
} is[MAX_SIZE];

int n;

bool cmp(interval &a, interval &b) {
    if (a.e != b.e) return a.e < b.e;
    return a.s < b.s;
}

int main() {
    cin >> n;

    for (int i = 1; i <= n; ++i) {
        cin >> is[i].s >> is[i].e;
    }

    sort(is, is + n, cmp);

    int ans = 1;
    int START = is[1].e;
    for (int i = 2; i <= n; ++i) {
        if (is[i].s > START) {
            ++ans;
            START = is[i].e;
        }
    }

    cout << ans;

    return 0;
}
