# Michael's Shopping Challenge

## Description

Michael is excited about the annual sale at his favorite store, where he can use coupons to get discounts on items he's been eyeing for months. The store has $n$ items with original prices $p_i$, and Michael has $k$ coupons that can reduce the price of the $i$-th item to $c_i$. Each coupon can only be used once. With a budget of $m$ dollars, Michael wants to know how many items he can purchase while using the coupons optimally. Can you help him figure out the best way to use his coupons and get the most items?

## Input

The input consists of three integers on the first line: $n$, $m$, and $k$ $(1≤n≤50000,1≤m≤10^14,0≤k≤n)$, where $n$ is the number of items, $m$ is the budget and $k$ is the number of available coupons.

The following $n$ lines each contain two integers, $p_i$ and $c_i$ $(1≤c_i≤p_i≤10^9)$, representing the original price and discounted price of the $i$-th item when a coupon is applied, respectively.

## Output

A single integer represents the maximum number of items Michael can buy.

## Sample

### Input

```
4 6 2
9 2
4 3
3 2
2 1
```

### Output

```
3
```

### Explain

Michael applied coupons on the item $1$ and $3$， and he can buy the item $1,3$ and $4$. The total cost is $2+2+1=5$.

## Grading

The test data consists of two subtasks, and to obtain a score for a particular subtask, all the test cases within that subtask must be passed.

- Subtask 1(40 points): All data is randomly generated.
- Subtask 2(60 points): Data contains specially constructed cases.