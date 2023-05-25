#include <iostream>
#include <algorithm>

using namespace std;
using ll = long long;

#define rep(i, a, b) for (int i = (a); i <= (b); ++i)
#define dwn(i, a, b) for (int i = (a); i >= (b); --i)

const int MAX_N = 1e5;

struct task {
    int ddl;
    int punish;
} ts[MAX_N];

int n;
ll punish_sum;
bool slot[MAX_N] = {false};

bool cmp(task &t1, task &t2) { return (t1.punish > t2.punish); }

int main() {
    cin >> n;

    rep(i, 1, n) cin >> ts[i].ddl;
    rep(i, 1, n) {
        cin >> ts[i].punish;
        punish_sum += ts[i].punish;
    }

    sort(ts + 1, ts + 1 + n, cmp);

    rep(i, 1, n) {
        dwn(j, min(n, ts[i].ddl), 1) {
            if (!slot[j]) {
                slot[j] = true;
                punish_sum -= ts[i].punish;
                break;
            }
        }
    }

    cout << punish_sum << endl;
}
