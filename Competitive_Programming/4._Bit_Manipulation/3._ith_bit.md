# 3. ith bit
Created Monday 29 June 2020


1. **Return** ith bit.

A simple way to do this would be
```c++
N = 100010101 // suppose we need 2nd bit - zero based counting
```
Approach 1 - Shift+Modulus:

1. Shift by k to the right
2. Check last bit
```c++
return (n >> i)%2; // Booth's algorithm - O(n)
```
Approach 2 - Shift and AND:
We can produce pow(2, i) using the left shift operator
```c++
return (n >> i) & 1; // returns 1 if set and 0 if unset
```
### ----

2. **Set** ith bit - OR
```c++
	// 01101 to set 2nd bit we need 00100 i.e 2^i
	// to set we use OR
	n|=(1<<i); // O(1)
```
### ----

3. **Unset** ith bit - AND and NOT
```c++
	// the
	n&=~(1<<i);
```

