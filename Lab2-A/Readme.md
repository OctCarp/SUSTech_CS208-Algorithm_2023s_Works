# Pay a new year call

## Description

XX lives in a town composed of $n$ villages (numbered $1,2,3,...,n$ respectively) and $m$ roads (each road connects two villages), of which the number of XX's village is $p (p∈[1,n])$. On the first day of the New Year, XX starts from his village and goes to another village to pay New Year's call through the road connected with his village. XX can also either go through the road he has passed or stay in her current village. Could you tell me the number of villages that XX might stay on the day $k$?

## Input

The first line contains four positive integers $n,m,p,q$ (it is guaranteed that the given graph is fully connected), where $q$ represents the number of questions. The following $m$ lines contain information about all the roads. Each line contains two positive integers $a$ and $b$, indicating that there is a road between the village numbered $a$ and the village numbered $b$. The last $q$ line contains $q$ questions, each line contains an integer $k$.

## Output

The output contains $q$ integers, separate with spaces, corresponding to $q$ questions respectively.

## Sample

### Input

```
4 3 2 3
2 1
2 3
4 2
0
1
2
```

### Output

```
1 4 4
```

Explanation: On day $0$, XX can only stay in the village where he originally stayed; On and after the first day, XX may be in any of the four villages.

## Hint

For $70%$ test cases,

- $nq≤2×10^6$

For $100%$ test cases,

- $1≤n≤30,000,1≤q≤200,000$.
- $m=n−1,k∈[0,100,000]$