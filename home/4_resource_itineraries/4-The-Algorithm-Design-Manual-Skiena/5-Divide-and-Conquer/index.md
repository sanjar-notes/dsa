# 5. Divide and Conquer
Created Mon Jul 29, 2024 at 9:39 PM

#dnc
## Main idea
One of the most powerful techniques for solving problems is to break them down into smaller, more easily solved pieces. 

*Smaller problems are less overwhelming, and they permit us to focus on details that are lost when we are studying the whole thing.*

## Steps
- Divide and conquer involves 3 steps:
  1. Divide (express it into smaller problems of the same type)
  2. Conquer (solve the instances)
  3. Combine (combine the solutions to form the complete solution)
## Breaking down problems
Two important algorithm design paradigms are based on breaking problems down into smaller problems. 
- Dynamic programming (DP) - typically removes one element from the problem, solves the smaller problem, and then adds back the element to the solution of this smaller problem in the proper way.
- Divide and conquer (DnC) - instead splits the problem into (say) halves, solves each half, then stitches the pieces back together to form a full solution.

Note: Relation to recursion - In DnC, subproblems are of the same type as the parent, so recursion is the natural choice for programming.

## When is DnC useful?
*Whenever the merging takes less time than solving the two subproblems, we
get an efficient algorithm.* 

Merge sort is an example, since merging is linear while sorting two halves has a log factor.


## Info about DnC
- DnC is used in many important algorithms like mergesort, fast fourier transform and Strassen's matrix multiplication.
- Beyond binary search and its variants, it becomes difficult to apply DnC.
- Ability to use DnC depends on solving recurrence relations.
- Combining efficiently is important too, not just solving the subproblems. The efficiency of conquering (aka combining) determines if DnC will be useful or not. Conquering should take less time.

### Decrease-and-conquer method (related)
In some problems, its possible to make the input smaller (i.e. without splitting into multiple inputs), after doing some (efficient) compute in each step. Since we don't have multiple inputs, there is no combine step. Code may be purely iterative (tail recursive) here.

Examples:
- Euclid's algorithm for GCD
- Binary search