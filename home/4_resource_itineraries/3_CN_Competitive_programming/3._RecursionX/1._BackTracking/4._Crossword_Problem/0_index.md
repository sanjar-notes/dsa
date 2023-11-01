# 4. Crossword Problem
Created Friday 26 June 2020

**Crossword Problem**
CodingNinjas has provided a crossword of 10*10 grid. The grid contains '+' or '-' as its cell values. Now, you are also provided with a word list that needs to placed accurately in the grid. Cells marked with '-' are to be filled with word list.
**Note:** We have provided such test cases that there is only one solution for the given input.
**Input format:**
The first 10 lines of input contain crossword. Each of 10 lines has a character array of size 10. Input characters are either '+' or '-'.
The next line of input contains the word list, in which each word is separated by ';'.
**Output format:**
Print the crossword grid, after placing the words of word list in '-' cells.
**Sample Test Cases:**
**Sample Input 1:**
```c++
+-++++++++
+-++-+++++
+-------++
+-++-+++++
+-++-+++++
+-++-+++++
++++-+++++
++++-+++++
++++++++++
----------
CALIFORNIA;NIGERIA;CANADA;TELAVIV
```

**Sample Output 1:**
```c++
+C++++++++
+A++T+++++
+NIGERIA++
+A++L+++++
+D++A+++++
+A++V+++++
++++I+++++
++++V+++++
++++++++++
CALIFORNIA
```

*****


* There's no choice but to check all possible cases. This is a backtracking problem.
* We can calculate the starting coordinates, type(across or down) and length of the missing letters.
* Then we'll try to place them one by one.
* We have to also take into account that multiple words can cross each other. An intersection must be the same letter.

[./crossword.cpp](4._Crossword_Problem/crossword.cpp)

*****

Has a weird error.

