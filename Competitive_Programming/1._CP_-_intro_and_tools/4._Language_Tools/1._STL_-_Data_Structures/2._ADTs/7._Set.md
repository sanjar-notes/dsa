# 7. Set
Created Sunday 03 May 2020

There are two kinds unordered_set and set(this one is ordered):

* Each element is a key.
* **.insert(value) **inserts the value in the set. 
* **.remove(value) **removes the value if present.
* **.max() **returns the maxium;
* to check do **.count**(value) 
* **.find**(value) returns iterator to the value, returns set_name.end() if not found.
* .begin(), .end() are useful here too.
* iterator traverses non-linearly here, but it++ still works.
* unordered_set does not support pair<>, unordered_map too does not support pair<>.



* It(<set>) is implemented using a balanced BST: Everthing is log(n).
* unordered_set takes O(1) average time for all ops.


