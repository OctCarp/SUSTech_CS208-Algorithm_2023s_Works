# Urban Construction

### Description

**Sjkmost** persuaded **Justin** to force his citizens to trip with zipline. However, the citizens are not strong enough and the citizens often fell from the zipline. Therefore, they decided to provide the citizens with some cable cars. Now **Sjkmost** is preparing the cable cars.

There are $n$ cable cars on the cable, each has an index $a_i$. **Sjkmost** is trying to put them in order.

**Sjkmost** can spend $c$ *justin* (a type of currency) to cut down a segment of rope of length $c$, rotate it and splice back. That is, he can spend $r−l+1$ *justin* to rotate the cable cars in an interval.

**Sjkmost** has a budget of $2×10^7$ *justin*. He should sort the cable cars with some operations with a total cost no more than $2×10^7$ *justin*. But he is so good at sorting that this problem is too boring for him.

**lhyyy**, who is not good at graph theory at all and got lost in **Justin**'s city, luckily met **Justin** at last. Now he doesn't know how to leave the city. If he can help sort the cable cars for **Sjkmost**, **Sjkmost** will tell him how to leave. However, **lhyyy** is not good at sorting as well. Can you help him?

### Input Format

The first line contains an integer $n (1≤n≤10^5)$, indicating the number of cable cars.

The second line contains $n$ integers $a_1,a_2,...,a_n (1≤a_i≤10^9)$, indicating the indexes of the cable cars.

### Output Format

Output the operations in order.

Each line contains two integers $l_i,r_i$ satisfying $1≤l_i≤r_i≤n$, which means rotating the interval $[l_i,r_i]$.

Finally, output a line `-1 -1` denoting the end of the output.

$∑r_i−l_i+1$ should not exceed $2×10^7$.

**There must be an empty line at the end of the output!**

**If there are multiple solutions, you can print any of them.**

### Sample

#### Sample Input1

```
4
1 3 2 4
```

#### Sample Output1

```
2 3
-1 -1
```

#### Sample Input2

```
4
4 3 2 1
```

#### Sample Output2

```
1 3
1 4
2 4
-1 -1
```

#### Sample Input3

```
10
11 4 5 1 4 1 91 9 8 10
```

#### Sample Output3

```
1 2
2 3
3 5
7 9
5 7
2 3
5 6
3 5
1 4
7 8
9 10
8 9
-1 -1
```

### Hint

For 10% testcases, $n≤5$.

For 20% testcases, $n≤500$.

For 30% testcases, $n≤5×10^3$.

For 50% testcases, $n≤1×10^4$.

For 70% testcases, $n≤3×10^4, a_i≤n$.

For 100% testcases, $n≤5×10^4$.