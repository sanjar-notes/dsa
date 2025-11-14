---
tags:
  - greedy
---
# 16. Greedy Algorithms
Created Tue Aug 13, 2024 at 1:08 AM

#greedy

## Context
Dynamic programming (when applicable) considers all possibilities when solving the problem.

But for many problems, there's simply no need to consider all possibilities at each point of the problem, and following a simpler local-optima choice would still lead to an optimal solution.

Like DP, Greedy is also used to solve optimization problems.

## DP vs Greedy
- Optimal substructure - both need it.
- Overlapping subproblems - DP needs to solve all subproblems. Greedy needs to solve one subproblem (this is called the greedy property - that there's just one subproblem to be solved).

The major difference between DP and Greedy is this - DP solves all subproblems, in order to makes the next choice (select the best from the sub-solutions). But greedy runs in the opposite order, it makes the choice first (locally optimum), and solves the subproblem (singular) that remains.


## Greedy implementation details
- Priority queue - choosing the optima quickly is key in the greedy approach, so priority queues are used quite often.
- 

### Knapsack problem
There are problems that cannot be solved by greedy, and need a DP solution, and vice versa.

Example - the 0-1 knapsack (things not divisible) needs a DP solution, while a fractional knapsack is easily solved using a greedy strategy (pick one with highest price/weight ratio).

## Greedy examples
- Prims algorithm - uses the greedy property, to choose smallest unconnected node. Proved using cut-and-paste (i.e. proof by contradiction).
- Dijkstra - this is combination of DP and greedy, picks the smallest-value unexplored node (the greedy part). It also updates already explored node's values (DP part), though only if they happen to be neighbor of an unexplored.
- Activity selection - pick the activity that finishes earliest. This greedy choice works because we have most time left ahead, to choose others. Had we not chosen this most early finishing activity, we would need to choose further activities. Comparing the two, the strategy would be more beneficial for sure.

## Proving greedy
- Prove optimal substructure. *Its easier in greedy since we can assume current choice is optimal, and inductively prove it'll be so.*
- Show that if we make the greedy choice, then only one subproblem remains.


## Applying Greedy
1. Check if optimal substructure
2. Develop a recursive relation
3. Show that if we make the greedy choice, then only one subproblem remains.
4. Prove that it is always safe to make the greedy choice. (Steps 3 and 4 can occur in either order.)
5. Develop a recursive algorithm that implements the greedy strategy.
6.  Convert the recursive algorithm to an iterative algorithm.


## Huffman codes
Huffman codes compress data very effectively: savings of 20% to 90% are typical, depending on the characteristics of the data being compressed.


## Matroid and greedy methods
In this section, we sketch a beautiful theory about greedy algorithms. This theory describes many situations in which the greedy method yields optimal solutions. It involves combinatorial structures known as “matroids.”

Although this theory does not cover all cases for which a greedy method applies or the Huffman-coding problem, it does cover many cases of practical interest.