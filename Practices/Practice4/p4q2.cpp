#include <iostream>
#include <vector>
#include <algorithm>

#define MAX_SIZE 10000

using namespace std;

int n;
vector<string> ans;

struct interval {
    int start = 0;
    int end = 0;
    string name;
} is[MAX_SIZE];

bool cmp(const interval &a, const interval &b) {
    return a.end < b.end;
}

void init();

void check();

int main() {
    init();
    check();

    for (string print: ans) {
        cout << print << ' ';
    }

    return 0;
}

void init() {
    string in;
    cin >> in;

    //Type "-1" to QUIT
    while (in != "-1") {
        is[++n].name = in;
        cin >> is[n].start >> is[n].end >> in;
    }
}

void check() {
    sort(is + 1, is + 1 + n, cmp);

    int p = 1;
    int ed = is[p].end;
    ans.push_back(is[p].name);

    while (++p <= n) {
        if (is[p].start >= ed) {
            ans.push_back(is[p].name);
            ed = is[p].end;
        }
    }
}

