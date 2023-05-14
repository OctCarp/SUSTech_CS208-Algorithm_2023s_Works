# Federated Learning

## Description

Federated Learning(FL) is a branch of machine learning which is developed for better data and privacy security. In FL, let's consider a very simple and interesting case.

Assume we build a FL system in a tree structure, there are $n$ clients in this FL system. Each client has its local model $w_i$. Now the trained global model will be sent to this FL system from the center server. Each node has a probability of $\frac{w_i}{\sum_{i=1}^nw_i}$ to receive the global model.

Starting from the client which has received the global model, it will update itself to the global model and send the global model to its adjacent client to update. Each not updated client has a probability of $p_i$ to be updated if **at least** one of its adjacent clients has updated to the global model. Also, the updated client can continue to send the global model to its adjacent client.

Now the problem is that, if exactly one client will get the global model initially, can you calculate the probability that exactly $k$ clients are eventually updated?

## Input Format

The first line contains two integers $n,k$, denotes the number of clients and $k$ is in description part.

The following $n−1$ lines, each line contains two positive integers $u$ and $v$ $(1≤u,v≤n)$ denoting that there is an edge $(u,v)$ on the tree.

Then following $n$ lines, each line contains three integers $w_i,a_i,b_i$, denotes that $w_i$ in description part, and $p_i=\frac{a_i}{b_i}$ in description part.

It is guaranteed that $1≤w_i,a_i,b_i≤10^9,\sum_{i=1}^nw_i≤10^9,\gcd(a_i,b_i)=1$

## Output Format

One line an integer. The integer should be the answer modulo $10^9+7$, which means if your answer is $\frac{a}{b}(\gcd(a,b)=1)$, you need to output $a⋅b^{−1}\mod 10^9+7$, where $b⋅b^{−1}\equiv 1\pmod{10^9+7}$.

## Sample

### Sample Input 1

```
5 3
3 1
3 2
1 5
1 4
4 2 7
5 1 9
3 2 3
8 1 7
11 6 11
```

### Sample Output 1

```
666077058
```

## Constraints

For 60% testcases, $1≤n≤200$.

For 100% testcases, $1≤n≤2000$.

## Hints:

If you don't know how to print the answer, here are some hints.

In Discrete Math, we know that how to solve congruence $ax\equiv b \pmod m$.

Also in Discrete Math, you have learnt Fermat's little theorem or extended Euclidean algorithm.

