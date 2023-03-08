# C Algorithms

## 🐧 What is it?

This repository contains two C algorithms I wrote back in December 2021.

The first one solves the [N Queens Problem](https://en.wikipedia.org/wiki/Eight_queens_puzzle), which is about placing queens on an nth dimensional chess table such that no queen threatens another.

The second one is the [Subgraph Isomorphism Problem](https://en.wikipedia.org/wiki/Graph_isomorphism_problem), and what it does is that, for `k` graphs, it checks whether there exists a subgraph of each graph such that there exists an [isomorphism](https://en.wikipedia.org/wiki/Graph_isomorphism) of any two subgraphs.

I wrote these for my Algorithms course in December 2021, back when I was just getting used to writing code every day.

## 🏃 How to run it?

1.  Clone this repository.
2.  Compile the *N Queens Problem* with `gcc -o sah sah.c` and the *Subgraph Isomorphism Problem* by using `gcc -o graf graf.c`.
3.  Run them using `./sah` and `./graf`. The program reads from `.in` files and outputs the result in `.out` files. In order to change the input, one can simply change the contents of the `.in` files.
4.  Enjoy!

## ♟️ How can I use them?

### N Queens Problem

The code for this is found in `sah.c`.

This program reads from an input file called `sah.in`:

```
N
```

It then outputs to `sah.out` a list of `N` pairs `(a, b)` that can be interpreted as the positions of the queens on the N dimensional chess table. It does this using an iterative algorithm.

### Subgraph Isomorphism Problem

This program reads from an input file called `graf.in`:

```
K
V1 E1
a11 b11
a12 b12
...
a1E1 b1E1
V2 E2
a21 b21
a22 b22
...
a2E2 b2E2
...
VK EK
aK1 bK1
aK2 bK2
...
aKEK bKEK
```

It outputs `-1` if there exists no solution, or `K` lists of `K2` numbers representing the `K2` indices of the `K` graphs that form subgraphs isomorphic to one another.

Considering this problem is NP-complete, it makes sense that there would be some restrictions to the inputs. These are `K < 5`, `Vi < 9`, `K2 < 5`, and that for an initial graph with `K2` nodes, there can be no more than `K2 + 2` nodes in the other `K - 1` graphs.

## 🎬 What's happening behind it?

The *N Queens Problem* is most commonly solved by using backtracking algorithms with exponential complexities, but the solution I implemented is iterative and only needs liniar time to find the positions.

The *Subgraph Isomorphism Problem* checks for the first graph and all the other graphs to be isomorphic with one another, and if it doesn't find a match it then removes a node from the `K - 1` graphs and checks again, then removes two nodes and checks, and then it could remove 3 nodes and so on.

For college, I also had to write [nondeterministic algorithms](https://en.wikipedia.org/wiki/Nondeterministic_algorithm) for these problems and estimate their complexities. This was a very lucrative exercise, as being allowed to familiarize oneself with theoretical nondeterminism can come in handy later on when studying parallel computing.

## ⚛️ Complexity analysis

For the *N Queens Problem*, we only need `O(N)` time to find the solutions and another `O(N)` time to output them, so the final time complexity for the entire algorithm can be estimated as `O(N + N) = O(N)`.

Compared to the usual `O(N!)` complexity obtained through backtracking, our liniar complexity is very, very good.

For the *Subgraph Isomorphism Problem*, our approach should be to use worst-case analysis and only focus on the case in which one of the `K - 1` graphs, say graph `i`, has `K2 + 2` nodes, and in that case the complexity is `O(K * Vi^4)`, where `Vi` is the number of nodes that graph `i` has.

This complexity is still polynomial, and reasonably good for the given problem.
