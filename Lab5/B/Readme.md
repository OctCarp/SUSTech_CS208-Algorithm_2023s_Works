## Voting

A monitor election is going to be held in your class. There are $(n+1)$ students in your class. And you want all your $n$ classmates to vote for you.

There exist two ways to convince each of your classmates to vote for you. The first way to convince your $i$ -th classmate is to pay him/her $c_i$ coins. The other way is to make $m_i$ other classmates vote for you, and the $i$ -th classmate will vote for you for free.

It should be noticed that the voting takes places in several steps. For example, if you have four classmates with $m_1=1,m_2=2,m_3=m_4=3,m_5=5$, then if you buy the vote of the $5$ -th classmate, then all your classmates will vote for you. And the set of classmates vote for you changes as: $5→1,5→1,2,5→1,2,3,4,5$.

Please calculate the minimum coins you need to spend so that all your classmates will vote for you.

## Input Format

the first line contains one integer $T$, representing the number of test cases.

The first line of each test case contains one integer $n(1≤n≤2×10^5)$, representing the number of your classmates.

The next $n$ lines contains two integers each line, $m_i(0≤m_i<n)$ and $c_i(0≤c_i<10^9)$.

**Hint:** It is guaranteed that the sum of $n$ over all test cases does not exceed $2×10^5$.

## Output Format

For each test case print one integer , representing the answer.

## Sample Input

```
3
7
0 1
3 1
1 1
6 1
1 1
4 1
4 1
3
1 5
2 10
2 8
6
2 6
2 3
2 8
2 7
4 4
5 5
```

## Sample Output

```
0
8
7
```

## Constraints

For 40% testcases, for two classmates $i$ and $j$, $m_i≤m_j$ if and only if $c_i≥c_j$.