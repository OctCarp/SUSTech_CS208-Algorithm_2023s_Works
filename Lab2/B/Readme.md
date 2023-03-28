# Simplicity Favors Regularity

### Description

**lhyyy** has a simple directed graph $G(V,E)$, but it's too complex. He wants to remove some vertices and edges to get a simple and regular subgraph.

The graph $G'(V',E')$ is called simple if $k$ is even and $E'=\{(v_1,v_2),(v_3,v_2),(v_3,v_4)...,(v_{k−1},v_k),(v_1,v_k)\} (∀i,v_i∈V)$ (It's nearly a circuit, except that the directions of the edges are related to the parity.)

To make the subgraph simple, **lhyyy** wants to minimize $|V'|$

However, **lhyyy** knows nothing about graph theory, can you help him?

### Input Format

The first line contains an integer $T (1≤T≤10)$, denoting the number of testcases.

For each testcase:

The first line contains two integers $n,m (1≤n≤10^3, 1≤m≤\frac{n(n−1)}{2})$, denoting $|V|$ and $|E|$.

The next $m$ lines, each contains two integers $x,y (x,y∈[1,n])$, denoting a unidirectional edge $(x,y)$.

### Output Format

For each testcase:

If a valid subgraph exists, output the minimal length. Otherwise, output `−1`.

### Sample

#### Sample Input

```
1
6 8
1 2
3 2
3 6
1 6
2 5
3 5
4 6
4 1
```

#### Sample Output

```
4
```

### Hint

The edges in the valid subgraph is $(1,2),(3,2),(3,6),(1,6)$.

For $10\%$ testcases, $n≤10$.

For $30\%$ testcases, $n≤100$.

For $90\%$ testcases, $n≤500$.

For $100\%$ testcases, $n≤1000$.

The input maybe large, fast I/O is highly recommended.