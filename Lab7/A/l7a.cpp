#include <iostream>

using namespace std;
using ll = long long;

ll N, L, R;

ll get_len();

ll prefix(ll len, ll n, ll i);

int main() {
    cin >> N >> L >> R;
    ll length = get_len();
    cout << prefix(length, N, R) - prefix(length, N, L - 1) << endl;

    return 0;
}

ll get_len() {
    ll tem = N;
    ll len = 1;
    while (tem > 0) {
        tem >>= 1;
        len <<= 1;
    }

    return len - 1;
}

ll prefix(ll len, ll n, ll i) {
    ll mid = (len + 1) >> 1;
    if (i == mid) {
        return (n + 1) >> 1;
    } else {
        if (i < mid) {
            return prefix(mid - 1, n >> 1, i);
        } else {
            return ((n + 1) >> 1) + prefix(mid - 1, n >> 1, i - mid);
        }
    }
}
