#include <iostream>
#include <algorithm>

using namespace std;

#define rep(i, a, b) for (int i = (a); i <= (b); ++i)

const int MAX_T = 10000;

struct task {
    int time;
    int ddl;
    int punish;
} ts[MAX_T];

int n, d;
int f[MAX_T][MAX_T];

bool cmp(task &t1, task &t2) { return (t1.ddl < t2.ddl); }

void dynamic();

int main() {
    cin >> n;

    rep(i, 1, n) cin >> ts[i].time;
    rep(i, 1, n) cin >> ts[i].ddl;
    rep(i, 1, n) cin >> ts[i].punish;

    sort(ts + 1, ts + 1 + n, cmp);

    d = ts[n].ddl;

    rep(i, 1, n) {
        rep(j, 0, d) {
            f[i][j] = MAX_T;
        }
    }

    dynamic();

    cout << f[n][d] << endl;
}

void dynamic() {
    rep(i, 0, d) {
        f[1][i] = i >= ts[1].time ? 0 : ts[1].punish;
    }

    rep(i, 2, n) {
        rep(j, 0, d) {
            int jj = min(ts[i].ddl, j);

            if (ts[i].time <= jj) {
                f[i][j] = min(f[i - 1][j] + ts[i].punish, f[i - 1][jj - ts[i].time]);
            } else {
                f[i][j] = f[i - 1][j] + ts[i].punish;
            }
        }
    }
}
