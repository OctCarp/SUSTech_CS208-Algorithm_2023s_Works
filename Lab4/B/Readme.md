# Fruit

## Description

Little Liu has a plantation where he grows $n$ types of fruits. Each type of fruit can be sold for a certain price $v_i$, but only within a specific time frame from $l_i$ to $r_i$. Little Liu can only sell one type of fruit at a time. Your task is to calculate the maximum amount of money he can earn from his plantation.

## Input Format

The first line contains an integer $n$.

Then $n$ lines follow, each line contains three integers $l_i$, $r_i$ and $v_i$, separated by space.

## Output Format

A single integer, denoting the maximum amount of money Little Liu can earn.

## Sample

### Sample Input

```
5
1 3 4
2 4 5
1 1 2
3 3 1
2 3 3
```

### Sample Output

```
14
```

## Constraints

For 40% testcases: $1≤n≤500, 1≤l_i≤r_i≤50$.

For all testcases: $1≤n≤5000, 1≤l_i≤r_i≤10^9, 1≤v_i≤10^9$.