#include <iostream>
#include <queue>

#define MAX_SIZE 10005

using namespace std;

struct point {
    int d = MAX_SIZE;
    vector<int> adj;
} ps[MAX_SIZE];

int N;

void Dijkstra();

int main() {
    std::ios_base::sync_with_stdio(0), std::cin.tie(0), std::cout.tie(0);
    
    cin >> N;
    int ck_points[N + 1];
    int holes[N + 1];
    for (int i = 1; i <= N; ++i) {
        cin >> ck_points[i];
    }

    for (int i = 1; i <= N; ++i) {
        cin >> holes[i];
    }

    if (N > 1) {
        ps[1].adj.push_back(ck_points[2]);
        ps[N].adj.push_back(ck_points[N - 1]);

        for (int i = 2; i <= N - 1; ++i) {
            ps[i].adj.push_back(ck_points[i - 1]);
            ps[i].adj.push_back(ck_points[i + 1]);
        }

        for (int i = 1; i <= N; ++i) {
            ps[i].adj.push_back(holes[i]);
        }

        Dijkstra();
    } else cout << "0\n";

    return 0;
}

void Dijkstra() {
    queue<int> que;

    que.push(1);
    ps[1].d = 0;
    while (!que.empty()) {
        int p = que.front();
        que.pop();

        for (int a: ps[p].adj) {
            if (ps[p].d + 1 < ps[a].d) {
                ps[a].d = ps[p].d + 1;
                que.push(a);
            }
        }
    }
    for (int i = 1; i <= N; ++i) {
        cout << ps[i].d << ' ';
    }
}