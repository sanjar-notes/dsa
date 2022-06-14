# 1. Inheritance - Concept
Created Sunday 26 April 2020

### Why inheritance
- Conceptually, inheritance is a way to derive a **more specific** concept from a general one.
- Essentially, inheritance is a code reuse mechanism in OOP. It is used to avoid redundant code.

For example, if we can specify the concept (class actually) of a `Car` from a more general concept of `Vehicle`,`Car` will have all/most properties of `Vehicle`, although more information will be added to really make it a `Car`.
![](Selection_104.png)
Some more examples are Shape <-- Circle, Person <-- Student.
- Due to reuse, one doesn't have to write the Horse again from scratch. And it's really useful if there are many animal classes that need to be derived from the class `Animal`.


### How is inheritance done
- Internally, the parent class's code is copied or made available to the specific class, except a few exceptions.
- The derived class inherits **all** (with some exceptions) properties of the parent class, i.e. inheritance isn't selective. Additionally, we can override and add more stuff as needed.
![[Pasted image 20220201220415.png]]
- The execptions (that are not inherited) are constructors, destructors and the copy assignment operator. The reason is that all these functions being general, don't have access to the added information in the derived class - the specific stuff (data members and member functions) of the derived class.
- So they need to redefined. **Of course, they are still available to be called**, but they'll work on behalf of inherited stuff only, not the new stuff.