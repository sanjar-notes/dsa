# 1. Vector
Created Sunday 03 May 2020


* It is a dynamic array. Reallocates and doubles size when size()>capacity().

Uses:
```c++
#include<iostream>
#include<vector>

int main()
{
vector<int> v(5);
}
```

Q) What is an iterator?
A) It is the pointer to an element within the range of the data structures.

1. We can go to the next one by doing **+=1**
2. We can access the element in the data structure by dereferencing.
3. **vec.begin()** returns the starting element. **vec.end()** is the pointer **after **the last element in the DS.
4. To make an iterator using
```c++
vector<int> :: iterator it = vec.begin();
// we can also just use auto
```

*****

Vector is just another name of our Dynamic Array. Exactly the same as our implementation.

* It has been implemented in STL.
* Doubles the size when the size is less.
* Keeps a size variable.
* Keeps a capacity variable.
* Starts from size 0, i.e NULL.
* Can be used dynamically and statically.


*****

header: **<vector>**
Declaration:
```c++
vector <data_type> v; 	static
vector <data_type>* v = new vector<int>;	//note the parentheses
vector <data_type>* v = new vector<int>(23);	//intial size is 23, not capacity
// Our size is 23, not capacity. i.e push_back() increases size to 24.
```
// We can specify initial capacity by providing an integer paremeter to the constructor. e.g vector<int> pq(23); **Remember that this inserts a garbage of type int, i.e size()==capacity().**

*****

Methods:

* vector_name.**push_back(T)** - append. We **must **use this function only, as it checks for capacity and updates size
* **pop_back()** deletes the last element.
* vector_name.**at(i)** - access/modify value at index i, if within size. **Can be used as lvalue too.**
* v[i] can also be used, but it is not safe for **insertion**, as it does no range checking. Use it only when you are sure of the index. For insertion use **at()**
* **vec.front() **and vec.**back**() are also useful.
* v.**size() **- returns the number of elements in the vector.
* v.**capacity() **- returns the capacity of the vector. i.e maxium elements which can be taken without resizing.
* vector_name.**pop_front() **- is a **void function**

Learnt on my own:

* v.**reserve(int i)** - makes the initial capacity as the i places.
* **clear() - **makes size = 0. size() does not return an lvalue.
* v.**insert(position, value) **inserts the value at index position and returns the iterator to the place where it has inserted val.
* v.**begin**() - returns iterator to the first element
* v.**end**() - returns iterator to **one place after** the last element. i.e iterator to v.at(i+1). It may not exist though.
* = operator does a **deep** copy of the vector, good.


*****

Note: Just don't try to break the abstraction.
Advantages:

1. Very space efficient. Least wastage.
2. Fastest access.
3. Doubling decreases the sporadic insertion time. Can be compensated with reserve().


