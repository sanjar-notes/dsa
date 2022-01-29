# 3. Special functions details
Created Wednesday 08 January 2020

The compiler is able to provide 4 special functions:

1. Default constructor
2. Copy constructor
3. Destructor
4. Copy assignment operator

Number 1 - conditionally given by the compiler
Number 2, 3, 4 - always given

* All special functions can be overriden.

*****
1. **Default constructor** does not need any invocation. It is used to initialize attributes. Provided by the compiler iff no(i.e of any type) constructor has been defined. It is simply an empty body.

Note:
* A program which has no default constructor(i.e it has been overshadowed), also compiles and runs as long as there's no call for the default constructor.

*****
**Parameterized** constructor has argument(s).
Static :	`Student obj1(val1, val2...);`
Dynamic :	`Student *obj1  = new Student(val1, val2...);`

* Never given by the compiler.

*****
2. **Copy constructor:**
It's a constructor(given by the compiler at all times) which takes an object as the argument, and copies all the data members to the new object. This copying is done in a *bit by bit* fashion. i.e **It does shallow copy.**

* We create an object which has all data_members the same as that of another pre-existing object called obj1.

Syntax:  just add a parenthesis to the class_name with the argument.
```c++
int main()
{
	Rectangle r1;
	Rectangle r2(r1); // copy constructor is called
}
```
Note:
* **Empty parenthesis should not be used. They are a part of C++'s **[Most Vexing Parse](https://stackoverflow.com/questions/180172/default-constructor-with-empty-brackets)  **wherein every empty () is treated as being a function declaration wherever it can be treated as such.**
* Although doing 'new Student()' is the same as 'new Student' - because cannot be misinterpreted as a function definition, as **new **is not a return type.
* All 4 possible cases while using the copy constructor for object creation:

S ≡ Stack, D ≡ Dynamic memory(heap)
S from S:	    `Student obj1(obj0);`
D from S:	`Student *obj1  = new Student(obj0);`
S from D:	`Student obj2(*obj1);`
D from D:	`Student *obj3 = new Student(*obj1);`
**Doubt/Motivation: Why don't we just copy each attribute expilcity, why have a copy constructor at all?**
We cannot, because:

* Some private attributes, may not have a proper getter at all. e.g We can only print the age, not access it via a variable.
* It is very tedious.
* It acts as an easy duplicate/clone button.

**Note: **

* If we wish to override the compiler-given copy constructor, it is important to use (const Student &t) as the formal param.
* Read : <http://www.cplusplus.com/doc/tutorial/classes2/#copy_constructor>

*****
4. **Copy assignment operator.**
If we need to copy data from one object to the other. Intuitively we'd want to use =.
'=' has actually been overloaded to implement *bit by bit* copying from rvalue location to the lvalue location.
Note: Beware of static and dynamically allocated objects, please **dereference** before using this operator.

* = does **shallow** copy.

Syntax examples(All 4 cases);
SS:   s1 = s2;
SD: 	s1 = *s2;
DS: 	*s1 = s2;
DD:	*s1 = *s2;

**Doubt: How does it differ with the copy constructor?**
**A)** This(=) operator is useful only if the two objects already exist. If one of them does not(i.e during declarization), then the copy constructor is called, not the assignment operator. i.e = will become a copy constructor in this case. [Copy vs Copy assignment operator.cpp](./3._Special_functions_details/copy_vs_copy_assignment.cpp)
e.g
Student x1 = x0; // this looks like copy assignment operator, but it is not. Copy constructor is called in this case, because x0 exists but x1 does not.
<http://www.cplusplus.com/doc/tutorial/classes2/#copy_assignment>

* Remember copy constructor is **more primitive** than assignment operator. The assignment operator resorts to the copy constructor and not the other way around. **Remember this.** Example:
```c++
MyClass obj2 = obj1; // actually calls the copy constructor
// so copy constructor is more primitive than assignment operator
```
* Never use an object assignment inside a copy constructor or a copy assignment operator. coz they form an infinite loop.