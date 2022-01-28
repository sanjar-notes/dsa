# 5. Stacks with templates
Created Wednesday 22 January 2020

Changes required in Stack class:

1. int* data to T* data
2. In push
3. In pop, replace INT_MIN, change it to 0 for the time being.
4. In top, replace INT_MIN by zero, coz it is universal.

No changes in:

1. nextIndex and capacity are always integers.


**From now on, we are well equipped with templates as well. We will use it as we want.**
This is important as Data structures work for any data type, i.e they are data type independent. So templates are very important. This encourages **reuse **over **duplication!!** 

