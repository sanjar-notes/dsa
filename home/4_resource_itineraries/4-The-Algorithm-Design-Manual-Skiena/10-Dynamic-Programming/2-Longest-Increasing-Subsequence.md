---
tags:
  - dp
---
# 2. Longest Increasing Subsequence
Created Tue Aug 6, 2024 at 11:17 PM

## Problem
Given an array of numbers, find the longest increasing subsequence. Duplicates may be there.


## Solution
- By naive exhaustion - we would need to enumerate using a bitset, and check for monotonicity, so n \* 2<sup>n</sup>.
- A greedy algorithm wouldn't do since each index can have multiple choices moving forward.

Lets try DP. Lets go from right to left (easier to handle). We need the value of `LIS(n)`, i.e. LIS ending at n. lets try to make a recurrence relation. To figure out LIS(i), we'd need to consider all previous index LIS, and choose the max, and also check if current element (ith) is greater than the chosen LIS's last element, aka predecessor. Recurrence is LIS(i) = max(previous LIS) + (last_element_of_chosen_LIS <= current ? 1: 0)

Since there's just one possible LIS at any point, and our param is index, so a linear store will do. We'll store both length and value of the last-element in each array element (or use two arrays). Memoization is done.

Lets try to see if we there's an explicit order possible or not. LIS(0) = 1 (single element). And since every LIS depends on all before, we can just run our code left to right, so for any index, all depends (left side values) are known. There's no need of recursion.

Note:
- Q: Why can't there be two (or more) equal sized subsequences ending at an index?
	- A: Suppose there were two sequences of equal length. What about their ending elements, if they are different, then one can accept the other, making it longer by one. if the last elements are the same, similar logic applies to the prefixes (ignore the last element). So, there can only be one longest-increasing-subsequence at a given index. If two are not possible, more with same length are also not possible.

## War Story - Text Compression for Bar Codes
A company was using a greedy algorithm to do something, under the assumption that assessing all possibilities was not possible. It turns out a DP solution was possible.

The speedup wasn't much (as DP can be on par with greedy, but not faster), but they got a better answer (since it was an optimization problem).

So, a DP may yield a better quality answer than a greedy-like (if pure greedy isn't possible) one.