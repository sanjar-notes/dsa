# 3. IO Techniques
Created Thursday 23 April 2020

Simple prerequisites like loops and all.
In C++, we can read and write from a file using stdin and stdout.


* Always use <bits/stdc++.h> for competitive programming.
* File Handling
```c++
freopen("in.txt", "r", stdin);	// read mode
freopen("out.txt", "w", stdout); // there's the append mode "a" too

cin >> x; // writes to x from stdin, i.e the file
cout << x; // writes the value of x to the file
```

* You can output simutaneously to multiple output files, but input is taken from one stream only.

For Python:
```python
# Below is Python3 code for input/output

import sys
# For getting input from in.txt file
sys.stdin = open('in.txt', 'r')
x = input()	# reading

# Printing the Output to out.txt file
sys.stdout = open('out.txt', 'w')
print(x)	//writing
```
