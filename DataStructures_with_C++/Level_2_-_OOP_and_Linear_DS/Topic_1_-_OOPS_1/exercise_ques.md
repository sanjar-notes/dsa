# Lecture 1 and 2

**Create objects**

    Which of these statements is used to allocate memory for an object dynamically ?

**Options**

    a. malloc
    b. alloc
    c. new
    d. give

<details> <summary><strong>Correct Answer</strong></summary>

    c. new

</details>

---

**Create object**

    Which of the following is/are a valid statement(s) to create an object of class Bird in C++ ?

**Options**

    a. Bird b = new Bird;
    b. Bird *b = new Bird;
    c. Bird b;
    d. new Bird b;

<details> <summary><strong>Correct Answer</strong></summary>

    b. Bird *b = new Bird;
    c. Bird b;

    b for dynamic allocation, c for static.

</details>

---

**Correct Statement**

    Figure out the correct statement

    class Car
    {
        public :
        int price;
    };

    int main()
    {
        Car c;
        //Figure out the correct statement to set the price of the car object referred to by c to “10000”
    }

**Options**

    a. c->price = 10000
    b. Car.price = 10000
    c. c.price = 10000;

<details> <summary><strong>Correct Answer</strong></summary>

    c. c.price = 10000;
    Statically allocated object with public attribute being accessed.

</details>

---

**What is the output**

    What is the output -

    #include <iostream>
    using namespace std;

    class Student
    {
        int rollNumber;
    };

    int main()
    {
        Student s;
        cout << s.rollNumber;
    }

**Options**

    a. GarbageValue
    b. 0
    c. Compilation Error
    d. None

<details> <summary><strong>Correct Answer</strong></summary>

    c. Compilation Error
    The program won't compile, as we are trying to access a private member.
    Default access modifier is private.

</details>

---

**What is the output**

    What is the output -

    #include <iostream>
    using namespace std;

    class Student
    {
        int rollNumber;
    };

    int main()
    {
        Student s;
        cout << s.rollNumber;
    }

**Options**

    a. A public member of a class can be accessed outside the class.
    b. A private member of a class cannot be accessed by the functions of the same class.
    c. A private member of a class cannot be accessed outside the same class.
    d. None of the above

<details> <summary><strong>Correct Answer</strong></summary>

    b. A private member of a class cannot be accessed by the functions of the same class.
    Private members can be accessed by the functions of the same class, irrespective of the function's access modifier.
    If it was not so, the private members would've been useless.

</details>

---

# Lecture 3(Getters and Setters) and 4(Constructors and 'this' keyword)

**What is the output**

    What will be the Output ?

    #include <iostream>
    using namespace std;

    class Box
    {
    public:
        int width;
        int height;
        int length;
        void volume()
        {
            cout << length * width * height;
        }
    };

    int main()
    {
        Box b;
        b.height = 5;
        b.width = 4;
        b.volume();
    }

**Options**

    a. Error
    b. 0
    c. 20
    d. Garbage value

<details> <summary><strong>Correct Answer</strong></summary>

    d. Garbage value
    Height and width are initialised to 5 and 4 respectively but length is not initialised. Default value for an integer data member of a class is garbage value, hence length contains garbage value. Volume will thus be garbage value.

</details>

---

**What is the output**

    What will be the output of the following code ?

    #include <iostream>
    using namespace std;

    class Student
    {
    public:
        char *name;
        int rollNo;
        Student(int num)
        {
            rollNo = num;
        }

        void print()
        {
            cout << rollNo;
        }
    };

    int main()
    {
        Student s(12);
        s.print();
    }

**Type the answer**

    ____

<details> <summary><strong>Correct Answer</strong></summary>

    12
    Constructor is called when an object is created, here when we create a Student object, corresponding student object is created and rollNo is assigned to 12. So output is 12.

</details>

---

**What is the output**

    What will be the output of the following code ?

    #include <iostream>
    using namespace std;

    class Student
    {
    public:
        char name;
        int rollNo;

        Student(int num)
        {
            rollNo = num;
        }

        void print()
        {
            cout << name << " " << rollNo;
        }
    };

    int main()
    {
        Student *s = new Student();
        s->name = 'A';
        s->rollNo = 15;
        s->print();
    }

**Options**

    a. GarbageValue 0
    b. GarbageValue 15
    c. Compilation Error

<details> <summary><strong>Correct Answer</strong></summary>

    c. Compilation Error

    There is Compilation error - “constructor Student() is undefined” because the default constructor is available only till the point we don’t create our own constructor. So Student class has only one constructor which require roll number as argument, hence we should pass integer as argument while creating any Student object.

</details>

---

**Find Incorrect Statement**

    Which of the following statements are not true about destructor?

    1. It is invoked when object goes out of the scope
    2. Like constructor, it can also have parameters
    3. It can be declared in private section
    4. It bears same name as that of the class and precedes tilde sign.

**Options**

    a. Only 2, 4
    b. Only 2, 3
    c. Only 1, 3
    d. Only 1, 4
    e. Only 2

<details> <summary><strong>Correct Answer</strong></summary>

    Only 2

    Destructors may be private, but it is a problem.

</details>

---

**Assume class DEMO. Which of the following statement(s) responsible to invoke copy constructor?**

    1. DEMO D2(D1); //  Here D1 is an already created object of class  DEMO

    2. D2 = D1; // Here D1, D2 are already created objects of class DEMO

**Options**

    a. Only 1
    b. Only 2
    c. Both 1 and 2

<details> <summary><strong>Correct Answer</strong></summary>

    a. Only 1
    Statement 2 is actually calling invoking the copy assignment operator and which is not a constructor, technically.

</details>

---

**Copy Assignment Operator**

    Consider following piece of code:

    class Pair
    {
      public :
      int first;
      int second;
    };

    int main()
    {

      Pair *p1 = new Pair;
      Pair p2;
    }

    Which of the following statement is feasible?

**Options**

    a. p2 = p1;
    b. p2 = *p1;
    c. Both 1 and 2 are correct.
    d. None of the above

<details> <summary><strong>Correct Answer</strong></summary>

    b. p2 = *p1;
    Statement a. will given array, type mismatch(Pair, Pair*);
    Statement b. is okay.

</details>

---

**Copy Assignment Operator**

    Consider following piece of code:

    #include <iostream>
    using namespace std;

    class Pair
    {
    public:
        int first;
        int second;
    };

    int main()
    {

        Pair p1;
        p1.first = 10;
        p1.second = 20;
        Pair p2;
        p2 = p1;
        cout << p2.first << " " << p2.second << endl;
    }

    Which of the following statement is feasible?

**Options**

    a. 10 20
    b. Error
    c. Garbage_value Garbage_value

<details> <summary><strong>Correct Answer</strong></summary>

    a. 10 20
    Perfectly normal. The copy assignement operator has been called.

</details>

---

# Coding Problems

<details> <summary><strong> 1. Does s contain t ? </strong></summary>

# 1. Does s contain t ?

    Given two string s and t, write a function to check if s contains all characters of t (in the same order as they are in string t).

    Return true or false.

    Do it recursively.

    E.g. : s = “abchjsgsuohhdhyrikkknddg” contains all characters of t=”coding” in the same order. So function will return true.

**Input Format**

    Line 1 : String s
    Line 2 : String t

**Output Format**

    true or false

**Sample Input 1**

    abchjsgsuohhdhyrikkknddg
    coding

**Sample Output 1**

    1

**Sample Input 2**

    abcde
    aeb

**Sample Output 2**

    false

<details> <summary><strong>Code</strong></summary>

    bool checksequenece(char large[] , char*small)
    {
        if(*small==0)
            return true;

        char x = *small;
        while(large[0]!=x && large[0]!='\0')
            large++;

        if(*large==0)
            return false;
        // else we have found it
        return (large+1, small+1);
    }

</details>

---

</details>

<details> <summary><strong> 2. Maximum Profit on App </strong></summary>

# 2. Maximum Profit on App

    You have made a smartphone app and want to set its price such that the profit earned is maximised. There are certain buyers who will buy your app only if their budget is greater than or equal to your price.

    You will be provided with a list of size N having budgets of buyers and you need to return the maximum profit that you can earn.

    Lets say you decide that price of your app is Rs. x and there are N number of buyers. So maximum profit you can earn is :

        m * x

    where m is total number of buyers whose budget is greater than or equal to x.

**Input Format**

    Line 1 : N (No. of buyers)
    Line 2 : Budget of buyers (separated by space)

**Output Format**

    Maximum profit

**Constraints**

    1 <= N <= 10^6

**Sample Input 1**

    4
    30 20 53 14

**Sample Output 1**

    60

**Sample Output 1 Explanation**

    Price of your app should be Rs. 20 or Rs. 30. For both prices, you can get the profit Rs. 60.

**Sample Input 2**

    5
    34 78 90 15 67

**Sample Output 2**

    201

**Sample Output 2 Explanation**

    Price of your app should be Rs. 67. You can get the profit Rs. 201 (i.e. 3 * 67).

<details> <summary><strong>Code</strong></summary>

    int maximumProfit(int budget[], int n)
    {
        // Write your code here

    }

</details>

---

</details>

<details> <summary><strong> 3. Split Array </strong></summary>

# 3. Split Array

    Given an integer array A of size N, check if the input array can be splitted in two parts such that -

        - Sum of both parts is equal
        - All elements in the input, which are divisible by 5 should be in same group.
        - All elements in the input, which are divisible by 3 (but not divisible by 5) should be in other group.
        - Elements which are neither divisible by 5 nor by 3, can be put in any group.

    Groups can be made with any set of elements, i.e. elements need not to be continuous. And you need to consider each and every element of input array in some group.

    Return true, if array can be split according to the above rules, else return false.

    Note : You will get marks only if all the test cases are passed.

**Input Format**

    Line 1 : Integer N (size of array)

    Line 2 : Array A elements (separated by space)

**Output Format**

    true or false

**Constraints**

    1 <= N <= 50

**Sample Input 1**

    2
    1 2

**Sample Output 1**

    false

**Sample Input 2**

    3
    1 4 3

**Sample Output 2**

    true

<details> <summary><strong>Code</strong></summary>

    bool splitArray(int *input, int size)
    {
        /* Don't write main().
         * Don't read input, it is passed as function argument.
         * Return output and don't print it.
         * Taking input and printing output is handled automatically.
         */

    }

</details>

---

</details>
