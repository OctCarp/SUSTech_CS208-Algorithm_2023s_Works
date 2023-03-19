#include <iostream>
#include <queue>

#define MAX_SIZE 10000

using namespace std;

int n, es;
vector<int> ans;

struct vertex {
    int in = 0;
    vector<int> adj;
} v[MAX_SIZE];

void init();

bool have_order();

int main() {
    init();

    if (have_order()) {
        for (int print: ans) {
            cout << print << ' ';
        }
    } else {
        cout << "impossible";
    }

    return 0;
}

void init() {
    cin >> n >> es;
    int a, b;
    while (es--) {
        cin >> a >> b;
        v[a].adj.push_back(b);
        ++v[b].in;
    }
}

bool have_order() {
    priority_queue<int, vector<int>, greater<int>> pri;

    for (int i = 1; i <= n; ++i) {
        if (v[i].in == 0) {
            pri.push(i);
        }
    }

    int p;
    while (!pri.empty()) {
        p = pri.top();
        pri.pop();
        ans.push_back(p);

        for (int a: v[p].adj) {
            if (--v[a].in == 0) {
                pri.push(a);
            }
        }
    }

    return ans.size() == n;
}
