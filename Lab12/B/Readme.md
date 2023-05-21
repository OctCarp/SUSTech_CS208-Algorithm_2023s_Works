# Cube

## Description

LYC has a amazing $h×a×b$ cube and plans to cut it into two amazing parts. The cut surface could be considered as a integer-valued function $f(x,y)$ whose domain is $([1,a]×[1,b])∪(\mathbb {Z}×\mathbb {Z})$ and should satisfy conditions below:

- $1≤f(x,y)≤h$
- $∀(x,y),(x',y')$ such that $|x−x'|+|y−y′|=1, |f(x,y)−f(x',y')|≤D$, where $D$ is a non-negative integer given.

There is another function $v(x,y,z) (1≤x≤a,1≤y≤b,1≤z≤h)$ given. Your objective is to help LYC determine $\min∑_{i,j}v(i,j,f(i,j))$.

## Input Format

The first line contains three integers $a, b$ and $h$.

The second line contains an integer $D$.

Then $h$ $a×b$ matrices follow, denoting the values of function $v(x,y,z)$.

## Output Format

A single integer, denoting $\min∑_{i,j}v(i,j,f(i,j))$.

## Sample

### Sample Input

```
2 2 2
1
6 1
6 1
2 6
2 6
```

### Sample Output

```
6
```

## Constraints

For all testcases: $1≤h,a,b≤40, 0≤D≤h, 0≤v(x,y,z)≤1000$.
