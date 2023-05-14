# Rook

## Description

You and Justin are playing a game on a $n×n$ chessboard. Justin first cuts out some squares in the chessboard, for the $i$-th column from left to right, he only leaves the bottommost $h_i$ squares.

Then you can place any number of rooks on the chessboard. A rook can move horizontally or vertically through any number of squares, but cannot move through squares that have been cut out. A rook can attack a square if and only if it can move to that square. After you place these rooks, Justin is supposed to find a square that is not occupied by rooks and cannot be attacked by any rook.

You want to win this game, that is to say, Justin cannot find any square satisfying these requirements. Now you need to calculate the number of ways to place rooks to ensure you can win. Since the answer may be large, output it modulo $998244353$.

## Input Format

The first line contains an integer $n$.

The second line contains $n$ integers $h_1,h_2,⋯,h_n$, separated by space.

## Output Format

A single integer, denoting the number of ways modulo $998244353$.

## Sample

### Sample Input

```
3
2 1 2
```

### Sample Output

```
17
```

## Constraints

For 20% testcases: $1≤n≤10$.

For 50% testcases: $1≤n≤50$.

For all testcases: $1≤n≤400, 1≤h_i≤n$.
