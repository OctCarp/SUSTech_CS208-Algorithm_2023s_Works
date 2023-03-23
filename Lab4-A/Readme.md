# TV Breaker

## Description

Recently, Bob bought a TV. The TV can be considered as a string $s$. **A TV is called wonderful if its string contains at least one amazing feature.** There are $n$ amazing features in total, and each one of the features is a string $f_i$. Alice is very jealous of Bob's TV. So one day Alice goes to Bob's home and starts breaking the TV.

Alice can only do one hitting for one time, each hitting she can choose one character of the TV string and make it become space. Now what she wants is to make Bob's TV become no wonderful. That is, after all her hittings, the TV will not contain any one of the amazing features.

Alice doesn't want to be very tired, so please help her find the minimum times of hittings to achieve her goal.

The alphabet of the strings consists of characters and the value of ASCII in decimal is from 33 to 126.

## Input Format

The first line contains a string $S$, which denotes Bob's TV.

The second line contains an integer $n$, which denotes the $n$ amazing features.

Then $n$ lines follow, each line contains a string $f_i$ that denotes the $i$-th amazing features.

## Output Format

A single integer, denotes the minimum times of hittings.

## Sample

### Sample Input 1

```
sustechcs208television
4
cs
television
cs208
sustech
```

### Sample Output 1

```
3
```

### Sample Input 2

```
<<<====================@=====>~
3
<<
~
===
```

### Sample Output 2

```
9
```

## Constraints

For 30% testcases: $1≤|S|≤1000, 1≤n≤50,1≤|f_i|≤100$.

For another 30% testcases: $1≤|S|≤100000,n=1,1≤|f_i|≤10000$

For all testcases: $1≤|S|≤100000, 1≤n≤50, 1≤|f_i|≤10000$.

**For all testcases: the sum of the appearance times of amazing features in $S$ will not exceed $500000$.**

BTW, Can you solve this problem when $n$ is in a larger range?