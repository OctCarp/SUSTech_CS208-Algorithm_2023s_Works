# Game

## Description

Bob is very angry because Alice broke his wondeful TV, so he will battle with Alice in a game to avenge.

The game is a very simple game. Initially, they are given a non-empty string $s$, consisting of lowercase letters. The length of the string is even. Each player also has its own empty string. In one move, a player takes either the first or the last letter of the string $s$, removes it from $s$ and **appends** it to their own string (put it at the end of the string).

The game ends when $s$ is empty. And then Alice and Bob will compare their strings, the one that owns a lexicographically smaller string will be the winner.

Bob is very confident with the game, so he will let **Alice move first**. Also, Alice and Bob will take their moves optimally.

Your task is to tell who is the winner or they draw.

## Input Format

The first line contains an integer denotes that the number of testcases

The following $T$ lines, each line contains a string $s$, denotes that string in description

## Output Format

For each testcase, print the result of the game.

If winner is Alice, print " `Alice` "

If winner is Bob, print " `Bob` "

If they draw, print " `Draw` "

## Sample

### Sample Input 1

```
3
ilikealgorithm
gggggggggggg
ooooooooooooohhhhhhhhhhhhh
```

### Sample Output 1

```
Alice
Draw
Alice
```

## Constraints

For 30% testcases: $1≤|S|≤20$.

For all testcases: $1≤|S|≤2000$.

The total length of the strings over all testcases doesn't exceed 2000.
