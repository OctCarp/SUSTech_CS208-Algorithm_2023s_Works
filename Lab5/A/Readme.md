## Shopping

Festival is coming and Andrea decides to buy $n$ gifts for her friends. However, $n$ gifts are sold on different days. So Andrea will buy them **in order**. For the $i$-th gift, the price is $c_i$.

In her city, there are only 1 dollar coins and 100 dollar notes. Before shopping, Andrea prepares $m$ coins and plenty of notes (you can assume that she always has enough notes to buy gifts).

There is only one cashier in the store and his efficiency depends on the gift he sells. For the $i$-th gift, his efficiency is $w_i$ and he needs $x·w_i$ seconds to check out where $x$ is the total number of the notes and coins he needs to give Andrea. The cashier always minimizes $x$.

Andrea wants to pay in such a way that the total time she needs to check out should be as small as possible.

Please help her to find out the minimum time she needs!

### Input Format

The first line contains two integers $n$ and $m$, representing the number of gifts and coins.

The second line contains $n$ integers, representing the price $c_i$ of each gift.

The third line contains $n$ integers, representing the efficiency $w_i$ of each day.

### Output Format

The output should be an integer representing the minimum time Andrea needs.

### Data range

#### For 20% cases:

$1≤n≤20$

#### For 50% cases:

$1≤n≤1000$

#### For all cases:

$1≤n≤10^5,0≤m,c_i,w_i≤10^5$

### Samples

#### Sample Input1

```mathematica
5 34
15 760 755 411 950
2 2 2 2 2
```

#### Sample Output1

```
170
```

#### Sample Input2

```
5 193
178 887 466 475 10
816 136 880 340 800
```

#### Sample Output2

```
10268
```