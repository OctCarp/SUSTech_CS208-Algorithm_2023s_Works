#include <iostream>
#include <queue>
#include <algorithm>

using namespace std;

#define ll long long
#define rep(i, a, b) for (int i = (a); i <= (b); ++i)
#define dwn(i, a, b) for (int i = (a); i >= (b); --i)

#define MAX_SIZE 10005

int T, n, k;
int st[MAX_SIZE];

ll get_max();

ll get_min();

int main() {
    cin >> T;
    while (T--) {
        cin >> n >> k;
        rep(i, 1, n) cin >> st[i];

        sort(st + 1, st + 1 + n);
        cout << get_max() << ' ' << get_min() << endl;
    }

    return 0;
}

ll get_max() {
    ll max = 0;
    max += st[n] * (n - 1);
    dwn(i, n - 1, 1) max += st[i] * i;

    return max;
}

ll get_min() {
    ll min = 0;
    priority_queue<int, vector<int>, greater<>> pq;
    rep(i, 1, n) pq.push(st[i]);

    int first = n % (k - 1);
    int times = n / (k - 1);

    int sum = 0;
    switch (first) {
        case 1:
            sum += pq.top();
            pq.pop();
        case 0:
            rep(i, 1, times) {
                rep(j, 1, k - 1) {
                    sum += pq.top();
                    pq.pop();
                }
                pq.push(sum);
                min += sum;
                sum = 0;
            }
            if (times > 1) min += pq.top();
            break;

        default:
            rep(j, 1, first) {
                sum += pq.top();
                pq.pop();
            }
            pq.push(sum);
            min += sum;
            sum = 0;

            rep(i, 1, times) {
                rep(j, 1, k - 1) {
                    sum += pq.top();
                    pq.pop();
                }
                pq.push(sum);
                min += sum;
                sum = 0;
            }
            if (times > 0) min += pq.top();
    }

    return min;
}
