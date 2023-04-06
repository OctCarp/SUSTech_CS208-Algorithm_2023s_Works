# Urban Planning

### Description

**Justin** is very rich and he owns a city. The road forms a tree consisting of $n$ vertices.

A tree's vertex is called a leaf if it has exactly one vertex adjacent to it. The distance between two vertices is the number of edges on the shortest path between them.

As suggested by **sjkmost**, **Justin** forces the citizens to trip with zipline. He built residential areas on the leaves and zipline stations on other vertices. Adjacent vertices are connected by ziplines.

Now **Justin** wants to group residential areas into regions. He wants to offer the residents convenient traffic, so the distance between every two residential areas in the region should not be greater than $k$. He also wants to group them into as few regions as possible, or it will be disturbing to manage.

This problem is too easy for **Justin**, so he solved it in a second.

**lhyyy** travelled to this city to visit **Justin**. However, he is not good at graph theory at all and he got lost. Can you find out how many regions there are in the city for **lhyyy**?

In other words, given a tree, you should split the leaves into sets such that the distance between any two leaves in the same set is not greater than �, and find out the minimal number of sets.

### Input Format

The first line contains two integers $n,k (3≤n≤10^5,1≤k<n)$.

The $i$-th $(2≤i≤n)$ line contains two integers $x_i,y_i$, denoting an edge $\{x_i,y_i\}$.

### Output Format

Print a single integer — the minimal number of sets the split can have.

### Sample

#### Sample Input

```
5 2
1 2
1 3
3 4
3 5
```

#### Sample Output

```
2
```

### Hint

For 20% testcases, $n≤5$.

For 40% testcases, $n≤1000$.

For another 10% testcases, $x_i=i−1,y_i=i$.

For another 10% testcases, $x_i=1,y_i=i$.

For another 10% testcases, it is guaranteed that the data is generated randomly.

For 100% testcases, $n≤10^5$.