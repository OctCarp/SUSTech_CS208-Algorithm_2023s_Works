### Hotel

#### Description

The city where Andrea lives is a beautiful place that attracts many tourists. All the tourists will check into the biggest hotel in this city.

The hotel has $n$ rooms and receives $m$ check in/checkout requests in the holiday. The rooms are numbered from $1$ to $n$ and at the beginning, all rooms are empty.

The tourists always come in group and when the $i$-th group checks in, they need $x$ contiguous rooms. If there are lots of rooms that meet the request, they will choose the room number to be the smallest possible and check in.

The tourists also checkout in group and when the $i$-th group checks out, the rooms numbered from $l_i$ to $r_i$ will be empty. Please note that some of those rooms may have been empty before the request.

Please help the hotel deal with these requests. For each check in request, please tell the tourists the number of the leftmost room they can check in.

#### Input Format

The first line contains two integers $n$ and $m$, representing the number of rooms and the number of requests.

The following $m$ lines each contains two or three integers representing the operations. The format is as follows:

1. `1 x`: The check in request.
2. `2 l r`: The checkout request.

#### Output Format

For each check in request, print a line containing one integer, representing the room number of the leftmost room. If there is no room available, please print `0`.

#### Sample

##### Input

```mathematica
5 5
1 3
1 2
2 3 5
2 1 1
1 3
```

##### Output

```mathematica
1
4
3
```

#### Range

For 50% testcases:

$1≤n,m≤10^3$

For all testcases:

$1≤n,m≤5×10^4$

