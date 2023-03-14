# Stable Matching

## Description

There are $N$ single boys and $N$ single girls waiting to be matched.

Each boy has his own preference order of all $N$ girls, and each girl has her own preference order of all $N$ boys.

As you are a well-known matching master, they wish that you find a **stable matching** for them!

## Input Format

The first line includes one integer $N$.

The next line contains $N$ strings separated by spaces, representing the name of boy $1,2,…,N$ respectively.

The next line contains $N$ strings separated by spaces, representing the name of girl  $1,2,…,N$ respectively.

For the next $N$ lines, line $i$ contains a permutation of $N$ girls' names, representing the preference order of boy $i$, from passionate to indifferent.

For the next $N$ lines, line $i$ contains a permutation of $N$ boys' names, representing the preference order of girl $i$, from passionate to indifferent.

It is guaranteed that no two person share a same name.

## Output Format

Your program should output $N$ lines.

Each line contains a boy's name and a girl's name separated by a space, representing a pair in the matching. Please output the boy's name before the girl.

You must make sure that your solution is a stable matching.

If there are multiple solution, output any one.

## Sample

### Sample Input

```
3
A B C 
a b c 
b a c 
b a c 
b c a 
C B A 
B C A 
A C B 
```

### Sample Output

```
A a
B b
C c
```

## Hint

For $40\%$ testcases:

- $N≤100$

For 100% testcases:

- $1≤N≤1000$
- length of any name is a positive integer no more than 10