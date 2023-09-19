# 3. Longest Increasing subsequence

Created Wednesday 01 July 2020

Given an array find the longest increasing subsequence.

1. Bruteforce solution
   - Find all subsequences and choose the longest increasing one.
   - Number of subsequences = 2^n^
   - Time complexity = O(2^n^)
2. A better approach - Check dependency:
   - LIS = max(all increasing subsequences) = max(LIS(starting from 0), LIS(starting from1)...) = max(LIS(ending at 0), LIS(ending at 1)...) **Both are equivalent, we'll use L->R for convenience.**
   - ![](/assets/3._Longest_Increasing_subsequence-image-1.png)
   - We will store the LIS ending at each index. memo[i] = max(memo[i-1 to 0] where end is less than memo[i])
   - A caveat here: It can happen that a sequence is reset. And the big memo values lie far to the left. To capture these large values, we should search the whole array to the left, updating only if arr[left] < arr[i] && (1+val[left]) < val[i]. Do set val[i] = 1 before the inner loop starts.
   - O(n^2^) time, O(n) space.

[LIS.cpp](3._Longest_Increasing_subsequence/LIS.cpp)

Note: We skipped a step, i.e we directly used bottom-up approach.
