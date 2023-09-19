# 4. Overriding, Overloading, Delegation

Created Sunday 2 February 2022

### Functions with same name as base class member

Assume there's a public function named `run` in a class `Vehicle`.
If we inherit `Vehicle` publicly as `Car` and define a function `run` in it with the same signature as `Vehicle::run`, then calling `run` from main using a `Car` object calls `Car::run` and not `Vehicle::run`.

This is called member function overriding.

- If there was no `Car::run`, calling `run` using `Car` object would actually call `Vehicle::run`.
- Even after overriding, `run` from `Vehicle` is still available inside the derived class, but as `Vehicle::run` and not `run`, i.e. we have to name the base member function explicitly if it's overriden.

```c++
class Vehicle {
	public:
		void run()
		{
			cout << "Vehicle run called\n";
		}
};

class Car : public Vehicle {
	public:
		void run()
		{
			cout << "Derived run called\n";
		}

		void delegateRun()
		{
			Vehicle::run();
			// still availale inside, but have to be explicit
		}
};

int main()
{
	Car obj;
	obj.run(); // calls Car::run

	obj.delegateRun(); // calls Vehicle::run
}
```

### Overloading of base member functions

Overriding happens only if signature matches. If it doesn't, public members of the base class are available as usual.

### Delegation of duty

- Overidden and overloaded are still available in the derived class, but they must be called explicitly, i.e. with full name (`BaseClass::myMemberFunction()`).
- A similar thing, called **invocation** is done for constructors, destructors and copy assignment operator This is heavily used in constructor and destructors, like so:

```c++
class Vehicle
{
	Vehicle(); // assume constructor defined
	~Vehicle(); // assume destructor defined
};

class Car
{
	Car()
	{
		Vehicle(); // initializes inherited data members
		// logic for Car initialization
	}

	~Car()
	{
		// logic to de-allocate Car first - as inherited stuff is coupled with this
		~Vehicle(); // de-allocate the inherited members now
	}
}
```

- Invocation does not need explicit (full) naming, because it's only done for special functions. Reason: they have unique signatures.

### Order for constructor and destructor

- If we instantiated the derived class, constructor for the base is supposed to be called before the derived class's constructor. Reason: Inherited stuff is needed first.

###### BaseConstructor before DerivedConstructor

- While destroying an object of the derived class, destructor of the derived class is supposed to be called first, then the base destructor is called. Reason: Inherited stuff is coupled to the derived class's logic, it is let go after we are done with the derived class's logic.

###### DerivedDestructor before BaseDestructor

- So, the way constructor and destructors are called is the reverse of each other.
  ![](/assets/4_Overriding,_Overloading,_Delegation-image-1.png)
- This is because a derived class is more specific, so has more information. It's like cascading boxes, and can be visualized like so (outermost is child, innermost parent class):
  ![](/assets/4_Overriding,_Overloading,_Delegation-image-2.png)
