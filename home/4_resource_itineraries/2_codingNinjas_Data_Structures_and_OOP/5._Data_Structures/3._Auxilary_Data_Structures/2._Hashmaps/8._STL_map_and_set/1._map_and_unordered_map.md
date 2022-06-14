# 1. map and unordered map
Created Tuesday 18 February 2020


1. map ordered - BST implementation - O(logn) - ops.
2. unordered_map - Hash table. Unordered - O(1) - all ops.


map has an order because you can use inOrder.
unordered is can be in **any** order. Order is random.


* Header: #include<unordered_map>
* It is a template.
* Remember "key then value"


The functions: mapname.f()

1. insert(pair<>). Does not **overwite** the value if we try to {insert key, different value}. No errors though if a key exists.
2. at(key).  Acess the value for 'key'. Throws an error if key is absent. Can be used as lval. 
3. mapname[key] -Used for acess and assignment. **Note: Creates **a (key, value) pair if key was absent. Returns no errors. **T.C same as insert(). But this is better. Should'nt be used if we are working on old data. i.e don't create your own.**
4. count(key) - returns the count. In a map, it is either 0 or 1. **Used for checking existence.**
5. size() - returns number of key value pairs.
6. erase(key), deletes a key if present. Else does nothing. No exceptions.


**Notes:**

1. Never use a hashmap to store coordinates, uncategorized tuples. As multiple tules could have same values for some.
2. unordered_map cannot store.


