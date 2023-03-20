# Flow Control

There are $n$ scenic spots in the scenic area, with entrance as $1$ and exit as $n$. The roads between the scenic spots are directed edges, and the roads in the entire scenic area form a directed acyclic graph (DAG). In order to control the flow of each vertices in the scenic area, the manager hopes to assign a flow value $w_i$ to each point, so that the sum of the flow on all paths from $1$ to $n$ is equal. Can you help him solve this problem?

## Input

The first line contains a positive integer $T(1≤T≤10^4)$, denoting the number of test cases.

For each test cases:

The first line contains two integers $n,m(1≤n≤2⋅10^5,1≤m≤5⋅10^5)$, the number of nodes and edges.

The next $m$ lines contains two integers $u,v$, denoting there is an edge from $u$ to $v$.

It is guaranteed that $∑n≤2⋅10^5,∑m≤5⋅10^5$.

It is guaranteed that the graph has no self-loops, no multiple edges, and no cycles. Besides, all vertices can be reached from $1$ and can reach $n$.

## Output

For each testcase, if there is no solution, then output `No` in a single line.

Otherwise, output `Yes` in the first line, then $n$ positive integers $w_1,w_2,⋯,w_n(1≤w_I≤10^9)$ on the second line.

If there are multiple solutions, you can print any of them.

## Examples

Input

```
2
5 5
1 2
1 3
2 4
3 5
4 5
8 10
1 2
1 3
2 5
2 7
3 4
3 6
5 6
4 7
6 8
7 8
```

Output

```
Yes
1 1 2 1 3
No
```