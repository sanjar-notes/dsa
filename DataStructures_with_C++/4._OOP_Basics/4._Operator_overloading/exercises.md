# Lecture 1: Deep and Shallow copy

**What is the output**

    What will be the output of the following code ?

    #include <iostream>
    using namespace std;
    #include <cstring>

    class Student
    {
    public:
        char *name;
        int rollNo;

        // Constructor 1
        Student(int num)
        {
            rollNo = num;
            name = new char[10];
            strcpy(name, "abc");
        }

        // Constructor 2
        Student(int num, char *str)
        {
            rollNo = num;
            name = new char[strlen(str) + 1];
            strcpy(name, str);
        }

        void print()
        {
            cout << name << " " << rollNo << " ";
        }
    };

    int main()
    {
        Student s1(101);
        s1.print();
        Student *s2 = new Student(150, "xyz");
        s2->print();
    }

**Options**

    a. Error
    b. GarbageValue 101 xyz 150
    c. abc 101 xyz 150
    d. None

<details> <summary><strong>Correct Answer</strong></summary>

    c. abc 101 xyz 150
    Basics

</details>

---

**What is the output**

    #include <iostream>
    using namespace std;

    class Student
    {
    public:
        char *name;
        int rollNo;

        void print()
        {
            cout << name << " " << rollNo << " ";
        }
    };

    int main()
    {
        char name[] = "Misha";
        Student s1;
        s1.name = name;
        s1.rollNo = 101;

        name[0] = 'N';
        Student s2;
        s2.name = name;
        s2.rollNo = 102;

        s1.print();
        s2.print();
    }

**Options**

    a. Misha 101 Nisha 102
    b. Nisha 101 Nisha 102
    c. Misha 101 Misha 102
    d. Nisha 101 Misha 102

<details> <summary><strong>Correct Answer</strong></summary>

    b. Nisha 101 Nisha 102
    Basics

</details>

---

# Copy constructor and initialization lists

**What is the output**

    class Student
    {
    public:
        const int rollNumber;
        int age;
    };

    int main()
    {
        Student s1;
        s1.rollNumber = 101;
        s1.age = 20;

        cout << s1.rollNumber << " " << s1.age;
    }

**Options**

    a. 101 20
    b. Garbage
    c. Compilation Error
    d. None

<details> <summary><strong>Correct Answer</strong></summary>

    c. Compilation Error
    const needs to be declarized. Not allowed. Useless anyway.

</details>

---

**What is the output**

    class Student
    {
    public:
        const int rollNumber;
        int age;

        Student(int r, int a) : rollNumber(r), age(a)
        {
        }
    };

    int main()
    {
        Student s1(100, 23);
        cout << s1.rollNumber << " " << s1.age;
    }

**Options**

    a. Error
    b. 100 Garbage
    c. 100 23
    d. Garbage Garbage

<details> <summary><strong>Correct Answer</strong></summary>

    c. 100 23
    Basics of initialization lists.

</details>

---

**What is the output**

    class Student
    {
    public:
        const int rollNumber;
        int age;

        int &x;

        Student(int r, int a) : rollNumber(r), age(a)
        {
        }
    };

    int main()
    {
        Student s1(100, 23);
        s1.x = age;
        cout << s1.rollNumber << " " << s1.age << " " << s1.x;
    }


        int main()
        {
            Student s1(100, 23);
            cout << s1.rollNumber << " " << s1.age;
        }

**Options**

    a. 100 23 23
    b. 100 23 Garbage
    c. Error
    d. None

<details> <summary><strong>Correct Answer</strong></summary>

    c. Error
    this keyword is missing in initialization list for the integer reference x;

</details>

---

# Constant Member Functions

**Member function**

    If a member function does not alter any data in the class, that may be declared as ....................

**Options**

    a. constant member function
    b. private member function
    c. static member function
    d. None

<details> <summary><strong>Correct Answer</strong></summary>

    a. constant member function
    Basics

</details>

---

**What is the output**

    class Student
    {
    public:
        int rollNumber;
        int age;
    };

    int main()
    {
        Student s1;

        Student const s2 = s1;

        s1.rollNumber = 101;
        s1.age = 20;

        cout << s2.rollNumber << " " << s2.age;
    }

**Options**

    a. 101 20
    b. Error
    c. Garbage Garbage
    d. None

<details> <summary><strong>Correct Answer</strong></summary>

    c. Counting the number of unit operations
    Basics

</details>

---

**What is the output**

    class Student
    {
        int rollNumber;

    public:
        int age;

        Student(int r)
        {
            rollNumber = r;
        }

        int getRollNumber()
        {
            return rollNumber;
        }
    };

    int main()
    {
        Student s1(101);
        s1.age = 20;

        Student const s2 = s1;
        cout << s2.getRollNumber();
    }

**Options**

    a. 101
    b. 0
    c. Garbage
    d. Error

<details> <summary><strong>Correct Answer</strong></summary>

    d. Error
    As s2 is a const object, so only constant member functions can be called through it. And that's not the case here.

</details>

---

**Correct statement**

    class Student
    {
    public:
        int rollNumber;
        static int totalStudents;
    };

    int Student::totalStudent = 20;

    int main()
    {
        Student s;
        // Correct statement to access totalStudents
    }

**Options**

    a. totalStudents
    b. s.totalStudents
    c. Student.totalStudents
    d. Student :: totalStudents

<details> <summary><strong>Correct Answer</strong></summary>

    d. Student :: totalStudents
    b would have also worked, but that is not a good practice.

</details>

---

**What is the output**

    class Student
    {
    public:
        int rollNumber;

        static int getRollNumber()
        {
            return rollNumber;
        }
    };

    int main()
    {
        Student s;
        s.rollNumber = 101;
        cout << s.getRollNumber() << endl;
    }

**Options**


    a. 101
    b. 0
    c. Compilation Error
    d. Error

<details> <summary><strong>Correct Answer</strong></summary>

    c. Compilation Error
    Static functions cannot operate on non static parts(data members and member functions).
    But non static can use static parts.

</details>

---

**Fill the output**

    class Student
    {
    public:
        int rollNumber;
        static int totalStudents;

        Student()
        {
            totalStudents++;
        }
    };

    int Student::totalStudents = 20;

    int main()
    {
        Student s1, s2, s3, s4;
        cout << Student ::totalStudents;
    }

**Answer**

    Type here ____

<details> <summary><strong>Correct Answer</strong></summary>

    24
    The constructor is called 4 times. So the static increases by 4.

</details>

---

**Recurrence for Merge Sort**

    What is the recurrence relation for merge sort :

**Options**

    a. T(n) = 2T(n/2)
    b. T(n) = 2T(n/2) + k
    c. T(n) = 2T(n/2) + O(n)
    d. T(n) = 2T(n/2) + O(log n)

<details> <summary><strong>Correct Answer</strong></summary>

    c. T(n) = 2T(n/2) + O(n)
    After we have successfully sorted the two halves, merge them O(n/2+/2) = O(n)

</details>

---

**Merge Sort**

    What is the time complexity of merge sort :

**Options**

    a. O(n)
    b. O(n^2)
    c. O(nlogn)
    d. O(log n)

<details> <summary><strong>Correct Answer</strong></summary>

    c. T(n) = 2T(n/2) + O(n)
    After we have successfully sorted the two halves, merge them, copy them k1*n + O(n/2+/2) = O(n)

</details>

---

**What is time complexity**

    What is the time complexity of following code ?

    int multiplyRec(int m, int n)
    {
        if(n == 1)
            return m;
        return m + multiplyRec(m,  n - 1);
    }

**Options**

    a. O(m*n)
    b. O(n)
    c. O(n^2)
    d. O(m)

<details> <summary><strong>Correct Answer</strong></summary>

    b. O(n)
    f(n) = k + f(n-1); f(n) = n*k + 0 = O(n)

</details>

---

**What is time complexity**

    int sumOfDigits(int n)
    {
            int sum;
            if(n < 10)
            {
                return n;
            }
            sum = (n % 10) + sumOfDigits(n / 10);
            return sum;
    }

**Options**

    a. O(logn) - log is to the base 10
    b. O(n)
    c. O(n^2)
    d. None of these

<details> <summary><strong>Correct Answer</strong></summary>

    a. O(logn) - log is to the base 10
    Basics

</details>

---

**Fibonacci**

    What is the time complexity of following code for calculating nth fibonacci number
    long fib(int n)
    {
        if(n == 0 || n == 1)
        {
            return n;
        }
        return fib(n - 1) + fib(n - 2);
    }

**Options**

    a. O(n)
    b. O(n^2)
    c. O(2^n)
    d. O(n^3)

<details> <summary><strong>Correct Answer</strong></summary>

    c. O(2^n)
    assume n-2  ~ n-1 -> f(n) = 2*f(n-1)
    Exponential

</details>

---

# Lecture 8 and 9

**Merge Sort space**

    The space complexity for merge sort is :

**Options**

    a. O(n)
    b. O(n^2)
    c. O(nlogn)
    d. O(log n)

<details> <summary><strong>Correct Answer</strong></summary>

    c. O(n)

    A doubt: Why not take into account the memory of the stack?
    Ans: Maximum stack memory is 12*log(n) = (8 Bytes + 4Bytes ~ pointer + size) * logn. But for the array it is much greater i.e max(12logn, 4n) = O(n)

</details>

---

**Fibonacci**

    The space complexity for finding nth fibonacci number using recursion is :

**Options**

    a. O(n)
    b. O(2^n)
    c. O(log n)
    d. O(n^2)
    e. O(nlogn)

<details> <summary><strong>Correct Answer</strong></summary>

    a. O(n)
    The max height, corresponding to the left most branch(if we do f(n-1) before f(n-2), from left to right). Only for the single variable.

</details>

---
