#include <cstdio>
#include <cstring>
#include <queue>

using namespace std;

#define rep(i, a, b) for (int i = (a); i <= (b); ++i)

const int MAX_E = 1e6;
const int INF = 0x3f3f3f3f;

struct edge {
    int to;
    int wei;
    int nxt;
} es[MAX_E];

int m, n, sid, tid;
int pro_sum = 0;
int head[MAX_E], tot = 0;
int dis[MAX_E], cur[MAX_E];
bool need[MAX_E] = {false};

int read();

void write(int x);

inline void add_e(int u, int v, int w) {
    es[tot].nxt = head[u];
    es[tot].to = v;
    es[tot].wei = w;
    head[u] = tot++;

    es[tot].nxt = head[v];
    es[tot].to = u;
    es[tot].wei = 0;
    head[v] = tot++;
}

void init();

bool bfs();

int dfs(int u, int ori_f);

int dinic();

void dfs_ans(int u);

int main() {
    init();
    int ans = pro_sum - dinic();
    dfs_ans(sid);

    rep(i, 1, m) {
        if (need[i]) {
            write(i);
            putchar(' ');
        }
    }
    putchar('\n');

    rep(i, 1, n) {
        if (need[i + m]) {
            write(i);
            putchar(' ');
        }
    }
    putchar('\n');

    write(ans);
    putchar('\n');

    return 0;
}


void init() {
    memset(head, -1, sizeof(head));
    m = read();
    n = read();
    sid = n + m + 1;
    tid = n + m + 2;

    rep(villain_id, 1, m) {
        int profit = read();
        pro_sum += profit;

        add_e(sid, villain_id, profit);

        int f_cnt = read();
        int func_id;
        rep(j, 1, f_cnt) {
            func_id = read();
            add_e(villain_id, func_id + m, INF);
        }
    }

    int func_cost;
    rep(func_id, 1 + m, n + m) {
        func_cost = read();
        add_e(func_id, tid, func_cost);
    }
}

bool bfs() {
    memset(dis, -1, sizeof(dis));
    dis[sid] = 0;
    queue<int> que;

    que.push(sid);
    while (!que.empty()) {
        int u = que.front();
        que.pop();

        for (int i = head[u]; i != -1; i = es[i].nxt) {
            int v = es[i].to;
            if (dis[v] == -1 && es[i].wei) {
                dis[v] = dis[u] + 1;
                que.push(v);
            }
        }
    }

    return dis[tid] != -1;
}

int dfs(int u, int ori_f) {
    if (u == tid) { return ori_f; }
    int flow = 0;

    for (int i = cur[u]; i != -1; i = es[i].nxt) {
        cur[u] = es[i].nxt;
        int v = es[i].to;

        if (dis[v] == dis[u] + 1 && es[i].wei > 0) {
            int d = dfs(v, min(ori_f, es[i].wei));

            es[i].wei -= d;
            es[i ^ 1].wei += d;

            ori_f -= d;
            flow += d;

            if (!ori_f) break;
        }
    }

    return flow;
}

int dinic() {
    int ans = 0;
    while (bfs()) {
        rep(i, 1, tid) {
            cur[i] = head[i];
        }

        ans += dfs(sid, INF);
    }

    return ans;
}

void dfs_ans(int u) {
    if (u == tid) { return; }
    need[u] = true;

    for (int i = head[u]; i != -1; i = es[i].nxt) {
        int v = es[i].to;
        if (!need[v] && es[i].wei) {
            dfs_ans(v);
        }
    }
}

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
