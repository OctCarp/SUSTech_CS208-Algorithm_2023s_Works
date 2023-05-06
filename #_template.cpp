#include <iostream>

using namespace std;
using ll = long long;
using pii = pair<int, int>;

#define rep(i, a, b) for (int i = (a); i <= (b); ++i)
#define dwn(i, a, b) for (int i = (a); i >= (b); --i)
#define pb push_back
#define eb emplace_back

// C++ disables the io synchronization
inline void disable_syn() { std::ios_base::sync_with_stdio(false), std::cin.tie(0), std::cout.tie(0); }

//fast
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

//fast long
ll readL() {
    ll s = 0, f = 1;
    char ch = getchar();
    while (ch < '0' || ch > '9') {
        if (ch == '-') f = -f;
        ch = getchar();
    }
    while (ch >= '0' && ch <= '9') s = (s << 1) + (s << 3) + (ch ^ '0'), ch = getchar();
    return s * f;
}

void writeL(ll x) {
    if (x < 0) putchar('-'), x = -x;
    if (x > 9) writeL(x / 10), putchar(x % 10 + '0');
    else putchar(x + '0');
}

// fast generic & varargs read
template<typename T>
inline void readT(T &x) {
    T s = 0, f = 1;
    T ch = getchar();
    while (!std::isdigit(ch)) {
        if (ch == '-') f = -f;
        ch = getchar();
    }
    while (std::isdigit(ch)) s = (s << 1) + (s << 3) + (ch ^ '0'),ch = getchar();
    x = s * f;
}

template<typename T, typename ...Args>
inline void readTs(T &x, Args &...args) {
    readT(x);
    readTs(args...);
}

