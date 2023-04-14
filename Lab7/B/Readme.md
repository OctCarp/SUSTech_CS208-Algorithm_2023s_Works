# The Best Way to Wipe out a Friendship

### Description

Andrea is wise, rich, noble, famous, sacred, sociable, powerful, diligent and intelligent, so she has a lot of friends. However, she has got bored and she wants to reduce the number of her friends.

**Andrea** has listed the names of $n$ friends of hers on a paper and assigned a number $a_i (i∈[1,n])$ for each friend. She is going to keep an interval and abandon other friends. Every friend is also a believer in **Andrea**. The remaining interval $[l,r]$ is *religious*, if and only if there is some integer $m≥2$, such that $a_l \bmod m = a_{l+1} \bmod m =...= a_r \bmod m$.

Can you find out the maximal length of an *religious* interval?

### Input Format

The first line contains an integer $n (1≤n≤10^5)$.

The second line contains $n$ integers $a_1,a_2,...,a_n (1≤a_i≤10^9)$.

### Output Format

Print a single integer — the maximal length.

### Sample

#### Sample Input 1

```
5
6 4 2 5 1
```

#### Sample Output 1

```
3
```

#### Sample Input 2

```
4
10 5 2 8
```

#### Sample Output 2

```
3
```

#### Sample Input 3

```
8
78 45 12 234 54 3 55 465
```

#### Sample Output 3

```
6
```

### Hint

For 10% testcases, $n≤5$.

For 20% testcases, $n≤1∗10^3$.

For 30% testcases, $n≤5∗10^3$.

For 90% testcases, $n≤5∗10^4$.

For 100% testcases, $n≤10^5$.