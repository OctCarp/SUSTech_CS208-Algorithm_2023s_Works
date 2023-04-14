### Modify

Recently, Andrea got a list with only one element $n$. Since she doesn't like anything other than 0 and 1, she performed some operations on this list. In each operation, she removed every element $x$, such that $x>1$ from the list. Then, in the same position, she added $⌊\frac{x}{2}⌋,x\bmod 2,⌊\frac{x}{2}⌋$ into the list. Until the list contained only 1 or 0, she stopped the operations.

Now, she wants to know the sum of the elements whose index are in the range $[l,r]$. Given $n, l, r$, please tell her the answer.

#### Input Format

The first line contains 3 integers, $n, l, r$ —— represent the initial element and the range.

It's guaranteed that the $r$ is not greater than the length of the final list.

#### Output Format

The output should be an integer representing the sum of the elements.

#### Example

##### Input

```mathematica
9 2 7
```

##### Output

```mathematica
3
```

##### Explanation

$[9]→[4,1,4]→[2,0,2,1,2,0,2]→[1,0,1,0,1,0,1,1,1,0,1,0,1,0,1]$

the sum is, $0+1+0+1+0+1=3$

#### Data Range

##### For 20 % cases:

$n≤5000$

##### For 50 % cases:

$n≤2^{50},r−l≤10^5$

##### For all cases:

$n≤2^{50}, 1≤l≤r≤$ the final length