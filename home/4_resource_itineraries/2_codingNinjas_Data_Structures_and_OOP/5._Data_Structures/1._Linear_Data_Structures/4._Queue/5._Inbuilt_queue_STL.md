# 5. Inbuilt queue STL
Created Thursday 23 January 2020


* Now we will focus only on the interface.
* Queue has been implemented in C++ STL. We will use only that now.



* header **<queue>**
* It's a simple one sided queue
* declaration is small 'q', queue <> variable_name.

Interface:

1. push(data) - the same as our enqueue(). Inserts the element in the queue.
2. front() - returns the element at head if it exists, else generic value.
3. void pop() - deletes an element but does not return the deleted value. It is a void.
4. size() - same as our getSize(). Returns the size of the queue.
5. empty() - returns true if empty, else false.
6. back() - returns the element at the back.


Note: Both stack and queue have the exact same interfaces. With the same signatures. Only the working changes. **pop and front are different!**

* Print was not discussed here.


For both sides insertion and deletion, use <deque>.

