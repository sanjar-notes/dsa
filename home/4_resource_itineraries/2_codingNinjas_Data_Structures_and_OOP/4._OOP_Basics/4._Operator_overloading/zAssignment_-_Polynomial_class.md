# zAssignment - Polynomial class
Created Tuesday 14 January 2020

**Polynomial**
Implement 3 functions
[main_for_polynominal.cpp](./zAssignment_-_Polynomial_class/main_for_polynominal.cpp)
[Polynomial_Class.cpp](./zAssignment_-_Polynomial_class/Polynomial_Class.cpp)
[CodingNinjas_Polynomial_soln.cpp](./zAssignment_-_Polynomial_class/CodingNinjas_Polynomial_soln.cpp)

* [Fourier transform](https://ocw.mit.edu/courses/electrical-engineering-and-computer-science/6-046j-design-and-analysis-of-algorithms-spring-2015/lecture-videos/lecture-3-divide-conquer-fft/) can be used for efficient multiplication


**Dynamic Array**

* We need an array that can change the size as required, according to the user.
* How will we do this:


1. We start with an arbitrary value of our choice.
2. When the user adds an element, the add(int index, int element).
	1. we will put it if we have space. 
	2. Else we will double the size of the array.
	3. We are not taking the number of elements he/she is adding. 
	4. They can also say where they want to add the element. We should check size here too. Do step b.
	5. If no such value is provided, we will append the element.


* Learnt that overloading is very useful, default arguments cannot take it's place;
* Remember to mark functions const wherever possible.

[./DynamicArray.cpp](./zAssignment_-_Polynomial_class/DynamicArray.cpp)

