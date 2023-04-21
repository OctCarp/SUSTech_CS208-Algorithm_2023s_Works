## Closest

#### Description

Given $n$ points on a two-dimensional plane, please find the closest pairs of points.

#### Input Format

The first line includes one integer $n$, which is the number of points.

The next $n$ lines, each containing two integers $x_i$, $y_i$, represent the coordinates of the $i$-th point.

#### Output Format

Output a line containing an integer $D^2$ that represents the **square** of the distance between the two closest points.

#### Sample

##### Input

```mathematica
5
1 1
1 9
9 1
9 9
0 10
```

##### Output

```mathematica
2
```

#### Range:

For 40% testcases: $1≤n≤3000$

For all testcases: $1≤n≤10^5,|x_i|, |y_i|≤2×10^7$