# 4. Exercise - number of Binary Trees
Created Tuesday 30 June 2020


* For a given height h, how many balanced binary trees are possible.
* For h=0 ⇒1 (no tree), h=1⇒1(only root), h=2 ⇒ 3
* It is actually quite simple: For height h, take the root. On the left and right, there are 3 possibilities
	1. h-1 and h-1
	2. h-1 and h-2
	3. h-2 and h-2
* f(h) = f(h-1)*(f(h-1)+2*f(h-2))
* It has lots of duplicates, memoization.
* We can form the bigger solutions from smaller ones here. Dynamic programming is applicable.


