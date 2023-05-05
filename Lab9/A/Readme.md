### Candy

#### Description

Recently, Andrea received $n$ piles of candy. The $i$-th pile contains $a_i$ candies. She would perform $m$ operations on these piles as follows:

1. Change the number of candies in pile $x$ to $v$
2. Find the sum of the number of candies in the given interval

#### Input Format

The first line contains two integers $n$, representing the number of piles, and $m$, representing the number of operations.

The second line contains $n$ integers, the $i$-th integer represents the $a_i$.

The following $m$ lines each contain three integers representing the operations. The format are:

1. `0 x v`: change the number of $a[x]$ to $v$
2. `1 l r`: print the sum of the number of candies in the interval $[l,r]$.

#### Output Format

Print several lines. Each line contains one integer representing the result of operation 2.

#### Sample

##### Input

```mathematica
5 4
3 6 1 8 5
1 2 5
0 3 4
1 1 4
1 2 5
```

##### Output

```mathematica
20
21
23
```

#### Range

For 30% testcases:

$1≤n≤5000$

For all testcases:

$1≤n≤10^5,0≤a_i,v≤1000,1≤l≤r≤n$