# 6. Stack using LL
Created Wednesday 22 January 2020


* We should make the stack ADT using LL such that the user shouldn't  be able to guess(i.e it is very efficient)  

Note: We did not need to know inheritance, that is only for attributes. You don't need it to use it for working with many classes together.

Working:

1. We should make the top as head, as this will ensure O(1) push() and pop(). 
2. Doing otherwise is O(n), as we have to take care of tail which needs to be updated, for which a traversal is required when removing. i.e if we add/delete on the tail element, insertion is O(1) but deletion is O(n).


