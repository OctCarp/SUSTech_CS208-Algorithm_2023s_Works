# Cyclops

## Description

As a superhero, you possess a remarkable eye with a range of optional functions labeled from $1$ to $n$. Each function $i$ incurs a cost of $a_i$ yuan when integrated into your eye. Alongside your abilities, there exist $m$ supervillains that you must confront. Each supervillain, denoted as the $j$-th villain, requires a specific subset $S_j$ of eye functions to be installed in order to be defeated. The defeat of each supervillain yields a reward of $b_j$ yuan.

Your objective is not to defeat all the supervillains but rather to strategize in a way that maximizes your profits.

## Input Format

The first line contains two integers $m$ and $n$.

Then $m$ lines follow, the $i+1$ line contains two integers $b_i,s_i$ first and $s_i$ integers that form $S_i$ then, separated by space.

The last line contains $n$ integers $a_1,a_2,⋯,a_n$, separated by space.

## Output Format

The first line contains labels of supervillains to be defeated.

The second line contains labels of functions to be installed.

The last line contains a single integer, denoting the maximized profit.

If there are multiple best strategies, output any.

## Sample

### Sample Input

```
2 3
10 2 1 2
25 2 2 3
5 6 7
```

### Sample Output

```
1 2
1 2 3
17
```

## Constraints

For all testcases: $1≤m,n,a_i,b_j≤50$.
