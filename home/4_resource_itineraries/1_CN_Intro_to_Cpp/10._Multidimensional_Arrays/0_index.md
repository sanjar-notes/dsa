# 10. Multidimensional Arrays
Created Saturday 21 December 2019

**2D arrays: **<http://www.cplusplus.com/doc/tutorial/arrays/>
When declaring a function which takes in a 2D array. It is very important to pass the number of columns in the array. This is important in cpp, as it is a basic requirement for going to the desired location.
Arrays are stored in cpp in row-major form. i.e arr[i][j] = *(arr+c*i+j). Where c = number of columns, i = row number and j = column number. 
e.g void f(x[][const int], int row, int column); When calling a function, no mention of the 'c' value is required. 

* To print the values, just print using two loops.
* During declaration and/or initialization, we can initialize the starting rows(and there elements, exactly as int x[10] = {1} means all 9 places to the right of x[0] are 0). **But **we have to provide every max_number, only the first one is optional. e. int x[][4][5] is valid but int x[4][5][] is invalid.
* Do take care that the column number(in the definition) is the the same as the number of columns in the real array.

e.g x[][const c1][const c2][]...[const cn]
	

