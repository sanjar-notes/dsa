# Lecture 1: Address Typecasting

**Void pointer can point to which type of objects ?**

**Options**

    a. int
    b. double
    c. float
    d. All

<details> <summary><strong>Correct Answer</strong></summary>

    d. All
    void can point to any type, that too without a type-cast.

</details>

---

**What is the output ?**

    int main()
    {
        int d = 65;
        int i = d;
        char ch = i;
        cout << ch << endl;
    }

**Answer**

    Type here: ____

<details> <summary><strong>Correct Answer</strong></summary>

    A
    As integers are stored as per Little Endian System, so 65 is on the first 8 bits. Which are read by the character pointer.

</details>

---

**What is the output ?**

    #include <iostream>
    using namespace std;

    void updateValue(int *p)
    {
        *p = 610 % 255;
    }

    int main()
    {
        char ch = 'A';
        updateValue((int*)&ch);
        cout << ch;
    }

**Answer**

    Type here: ____

<details> <summary><strong>Correct Answer</strong></summary>

    d
    100 is d for ASCII. Clue: 97 - 96 = A.

</details>

---

# Lecture 2: Reference and Pass by Reference

**What is the correct syntax of declaring and defining a reference?**

**Options**

    a. int a = 10; int &b; b = a;
    b. int a = 10; int &b = a;
    c. int a = 10; int b = &a;
    d. int a = 10; int &b = &a;

<details> <summary><strong>Correct Answer</strong></summary>

    b. int a = 10; int &b = a;
    Reference variables need a record from the symbol table w.r.t a name. And this has to be done in one go. Hence they need to be initialized with the name of an already existing value.

</details>

---

**What is the output ?**

    #include <iostream>
    using namespace std;

    void func(int p)
    {
        cout << p << " ";
    }

    int main()
    {
        int i = 10;
        int &p = i;
        func(p++);
        cout << i;
    }

**Answer**

    Type here: ____

<details> <summary><strong>Correct Answer</strong></summary>

    10 11
    As the increment is a postfix, hence the code func(p) will be evaluated.
    Then p++ is evaluated. So in the next line(of the main()), 11 will be printed.

</details>

---

**What is the output ?**

    #include <iostream>
    using namespace std;

    void func(int i, int& j, int p)
    {
        i++;
        j++;
        p++;
    }

    int main()
    {
        int i = 10;
        int j = 6;
        int &p = i;
        func(i, j, p);
        cout << i << " " << j << " " << p;
    }

**Answer**

    Type here: ____

<details> <summary><strong>Correct Answer</strong></summary>

    10 7 10
    As i and p are passed by value, no changes get reflected on the actual(i. e main()) memory location. But as j is passed by reference, so a change is made at the actual memory.

</details>

---

# Lecture 3: Dynamic Allocation

**What is the output ?**

    In CPP, dynamic memory allocation is done using ____ operator.

**Options**

    a. calloc()
    b. malloc
    c. allocate
    d. new

<details> <summary><strong>Correct Answer</strong></summary>

    d. new
    new is used in C++.
    void *malloc(n*sizeof()), void *calloc(n, sizeof()), void *realloc(ptr, n*sizeof()), void free()

</details>

---

**How will you free the memory allocated by following program ?**

    #include <iostream>
    using namespace std;

    int main()
    {
        int *a = new int;
    }

**Options**

    a. free a;
    b. delete *a;
    c. delete a;
    d. new a;

<details> <summary><strong>Correct Answer</strong></summary>
    c. delete a;
</details>

---

**How will you free the memory allocated by following program ?**

    Correct statement for creating an integer array of size 5, dynamically -

**Options**

    a. int *arr[] = new int[5];
    b. int *arr = new int[5];
    c. int arr = new int[5];
    d. int *arr[5] = new int;

<details> <summary><strong>Correct Answer</strong></summary>

    b. int *arr = new int[5];

</details>

---

**Correct statement for deallocating the array is ?**

    Correct statement for creating an integer array of size 5, dynamically -

**Options**

    a. delete [] arr;
    b. delete arr;
    c. delete *arr;
    d. delete [] *arr;

<details> <summary><strong>Correct Answer</strong></summary>

    a. delete [] arr;

</details>

---

**On deleting a dynamic memory, if the pointer value is not modified, then the pointer points to ?**

    Correct statement for creating an integer array of size 5, dynamically -

**Options**

    a. NULL
    b. Other dynamically allocated memory
    c. The same deleted memory location
    d. It points back to location it was initialized with.

<details> <summary><strong>Correct Answer</strong></summary>

    a. delete [] arr;

</details>

---

# Lecture 4: Dynamic Allocation for 2D arrays

**What is the output ?**

    In CPP, dynamic memory allocation is done using ____ operator.

**Options**

    a. calloc()
    b. malloc
    c. allocate
    d. new

<details> <summary><strong>Correct Answer</strong></summary>

    d. new
    new is used in C++.
    void *malloc(n*sizeof()), void *calloc(n, sizeof()), void *realloc(ptr, n*sizeof()), void free()

</details>

---

**How will you free the memory allocated by following program ?**

    #include <iostream>
    using namespace std;

    int main()
    {
        int *a = new int;
    }

**Options**

    a. free a;
    b. delete* a;
    c. delete a;
    d. free a;

<details> <summary><strong>Correct Answer</strong></summary>

    c. delete a;
    We use the delete keyword, followed to by the to_heap_pointer_name.

</details>

---

**Correct statement for creating an integer array of size 5, dynamically ?**

**Options**

    a. int *arr[] = new int[5];
    b. int *arr = new int[5];
    c. int arr = new int[5];
    d. int *arr[5] = new int;

<details> <summary><strong>Correct Answer</strong></summary>

    b. int *arr = new int[5];
    Basic syntax.

</details>

---

**Correct statement for deallocating the array is:**

**Options**

    a. delete [] arr;
    b. delete arr;
    c. delete *arr;
    d. delete [] *arr;

<details> <summary><strong>Correct Answer</strong></summary>

    c. delete [] arr;
    Basic syntax.

</details>

---

**On deleting a dynamic memory, if the pointer value is not modified, then the pointer points to?**

**Options**

    a. NULL
    b. Other dynamically allocated memory
    c. The same deleted memory location
    d. It points back to location it was initialized with

<details> <summary><strong>Correct Answer</strong></summary>

    c. The same deleted memory location
    The memory is saved even if it goes out of scope.

</details>

---

**How to Dynamically create a Two Dimensional Array in C++?**

**Options**

    a. int *twoDArray = new int[10][10];
    b. int **twoDArray = new int*[10];
    c. int **twoDArray = new int[10][10];

<details> <summary><strong>Correct Answer</strong></summary>

    b. int **twoDArray = new int*[10];
    Just create an array of pointers, each of which points to an array of data_type, the rows.

</details>

---

**Can we create Jagged Arrays in C++ ?**

**Options**

    a. Yes
    b. No

<details> <summary><strong>Correct Answer</strong></summary>

    a. Yes
    Yes, we have no obligation to make all the arrays of the same size. Since there's no part in the pointer declaration that indicates any kind of number, so sizeof() field is just for the pointer(in contrast to statically declared array).

</details>

---

**Given the following CPP Program. Select the CORRECT Syntax of deleting this 2D array? Check all that apply?**

    #include <iostream>
    using namespace std;

    int main()
    {
        int **twoDArray = new int*[10];
        for(int i = 0; i < 10; i++)
            *(twoDArray + i) = new int[10];
    }

**Options**

    a. delete twoDArray [][];

    b.  for(int i = 0; i < 10; i++)
            delete twoDArray[i];

    c.  for(int i = 0; i < 10; i++)
            delete [] twoDArray[i];

    d.  for(int i = 0; i < 10; i++)
            delete twoDArray[i][];

<details> <summary><strong>Correct Answer</strong></summary>

    c. Only C
    Basic syntax

</details>

---

# End Of Quiz
