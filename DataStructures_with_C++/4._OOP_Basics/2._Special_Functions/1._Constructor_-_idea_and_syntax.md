# 1. Constructor - idea and syntax
Created Wednesday 08 January 2020

#### Idea of a constructor
* A newly created object **should have **some initial value. Garbage values are undesired.
* Constructor do exactly this - they initialize data.
* Constructors are called automatically - this relieves us of initializing objects using setters.


#### Properties of a constructor
1. It is a function
2. Name is the same as that of the class.
3. Has no return type, not even void.
4. Called only once in the life-time of an object.


#### Types of constructors
1. Default constructor - No arguments. **It is named default coz it takes no argument.**
2. Parameterized constructor -  takes some argument.
3. Copy constructor - Takes only one object of the same class as argument.


Notes:
* If **no** constructor(i.e. of any type) is defined, **then and only then** a default constructor will be supplied by the compiler(actually just an empty body).
```
// compiler provided constructor
class_name()
{

}
```

* If we define a constructor of any type, then this '**default'** constructor goes out of scope for us.
* If a type of constructor is called, but not defined, although atleast one constructor(of some other type) has been defined. Then this is a compilation error, as no matching constructor could be found.

<http://www.cplusplus.com/doc/tutorial/classes2/#default_constructor>

* **Tip:** A parameterized constructor can be passed default arguments, so that there's no need of a separate default constructor. Takes care of the ambiguity, which can be a runtime error.
* A constructor can be called explicitly, because this is useful.
```c++
int main()
{
	Car c;
	string name = "Batman";
	c.ride(Passenger(name)); // explicit call without declaration
}
```
* A constructor can call other functions from inside it, no problem.
* A program will **compile** **and run**, even if only a (non default param) parameterized constructor is defined. But it'll give runtime error if no params are given during its creation. **This is because we may not need a default constructor at all, due to presence of a parameterized constructor(which is not a default).**


