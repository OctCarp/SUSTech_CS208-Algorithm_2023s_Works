# Careless Boy

## Description

Dy is a careless boy. One day, on the way of delivering apples, Dy pays all attention on playing Nihsneg on his phone. Dy is so focused on playing that he doesn’t realize that all apples drop out from the baskets! Now Dy needs to collect apples along the way and take them back to the truck. All tools he can use are the baskets on the truck and himself. Dy need to set off from the truck to collect apples with his baskets. Every basket has its own volume $v_i$, representing the number of apples it can hold. At any time, Dy can carry only one basket. The truck and the apples are on the same line. The line can be considered as a number axis and the truck is its origin. Every apple has its own position $p_i$ on the number axis. Once Dy passes by an apple, he can pick up the apple and keep collecting apples if the basket is not full. Once the basket is full, Dy must take it back to the truck. Dy wonders how far it would take him to fill up all the baskets (If the total number of apples is less than the sum of basket volume ($n<∑v_i$), then Dy just need to collect all apples). And he wants the total distance to be as small as possible.

## Input Format

The first line has two integers $n$ and $m$, representing the number of apples and the baskets; The next line has $m$ integers, representing the volume $v_i$ of each basket. The final line has $n$ integers, representing the position $p_i$ of each apple.

## Output Format

The output should be an integer representing the total minimum distance cost to finish the mission.

## Data range

#### For 30% cases:

$1≤n≤100$; $1≤v_i,p_i≤1000$;

#### For 60% cases:

$1≤n≤5000$; $1≤v_i,p_i≤10^6$;

#### For all cases:

$1≤n,m≤10^6$; $1≤v_i,p_i≤10^9$; It is guaranteed that the list of $p_i$ is sorted in ascending order.

## Samples

#### Sample Input 1

```
6 3
2 1 3
1 2 4 5 6 8
```

#### Sample Output 1

```
26
```

#### Sample Input 2

```
6 3
1 2 2
1 4 4 5 6 8
```

#### Sample Output 2

```
22
```