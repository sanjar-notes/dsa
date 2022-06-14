# Lecture 1: Introduction to Pointers

**What will be the output ?**

    int *ptr = 0;
    int a = 10;
    ptr = a;
    cout << *ptr << endl;

**Options:**

    a. 10
    b. 0
    c. Error
    d. None

<details> <summary><strong>Correct Answer</strong></summary>

    Error
    Cannot assign int value to an int*

</details>

---

**What will be the output ?**

    int a = 7;
    int b = 17;
    int *c = &b;
    a = *c;
    *c = *c + 1;
    cout  << a << "  " << b << endl;

**Options**

    a. 18 18
    b. 7 18
    c. 17 17
    d. 17 18

<details> <summary><strong>Correct Answer</strong></summary>

    d. 17 18
    Make a variable map.

</details>

---

**What will be the output ?**

    float f = 10.5;
    float p = 2.5;
    float* ptr = &f;
    (*ptr)++;
    *ptr = p;
    cout << *ptr << " " << f << " " << p;

**Options**

    a. 2.5 10.5 2.5
    b. 2.5 11.5 2.5
    c. 2.5 2.5 2.5
    d. 11.5 11.5 2.5

<details> <summary><strong>Correct Answer</strong></summary>

    c.2.5 2.5 2.5
    Make a variable map.

</details>

---

# Lecture 2: Pointer Arithmetic

**What will be the output ?**

    int a = 7;
    int *c = &a;
    c = c + 1;
    cout  << a << "  " << *c << endl;

**Options**

    a. Garbage_value 7
    b. 7 Garbage_value
    c. 8 8
    d. 7 7

<details> <summary><strong>Correct Answer</strong></summary>

    b. 7 Garbage_value
    Obvious.

</details>

---

**Assume memory address of variable ‘a’ is : 400 (and an integer takes 4 bytes), what will be the output ?**

    int a = 7;
    int *c = &a;
    c = c + 3;
    cout  << c << endl;

**Fill in the answer**

    ____

<details> <summary><strong>Correct Answer</strong></summary>

    412
    400 + 3*4 = 412

</details>

---

**Assume memory address of variable ‘a’ is : 200 and a double variable is of size 8 bytes, what will be the output ?**

    double a = 10.54;
    double *d = &a;
    d = d + 1;
    cout  << d << endl;

**Fill in the answer**

    ____

<details> <summary><strong>Correct Answer</strong></summary>

    208
    200 + 1*8 = 208

</details>

---

# Lecture 3: Arrays and Pointers

**Assume integer takes 4 bytes and integer pointer 8 bytes.**\
**What is the output**

    int a[5];
    int *c;
    cout << sizeof(a) << " " << sizeof(c);

**Options**

    a. 8 8
    b. 5 8
    c. 20 8
    d. 20 4

<details> <summary><strong>Correct Answer</strong></summary>

    c. 20 8
    sizeof(a) = size of the array, sizeof(c) = 8 bytes(pointer size)

</details>

---

**Fill the output**

    int a[] = {1, 2, 3, 4};
    cout << *(a) << " " << *(a+1);

**Answer**

    ____

<details> <summary><strong>Correct Answer</strong></summary>

    c. 1 2
    *a = first element of the array,*(a+1) is the second element

</details>

---

**Assume that address of 0th index of array ‘a’ is : 200. What is the output ?**

    int a[6] = {1, 2, 3};
    cout << a << " " << &a;

**Answer**

    ____

<details> <summary><strong>Correct Answer</strong></summary>

    200 200
    value of 'a' and address of 'a' is the same in case of array names.

</details>

---

**Assume that address of 0th index of array ‘a’ is : 200. What is the output ?**

    int a[6] = {1, 2, 3};
    cout << (a+2);

**Answer**

    ____

<details> <summary><strong>Correct Answer</strong></summary>

    208
    jump = 4, 200 + 2*(4) = 208. Jump is decided based on data type.

</details>

---

**Assume that address of 0th index of array ‘a’ is : 200. What is the output ?**

    int a[6] = {1, 2, 3};
    int *b = a;
    cout << b[2];

**Options**

    a. Error
    b. 3
    c. 1
    d. 200
    e. 212

<details> <summary><strong>Correct Answer</strong></summary>

    b. 3
    b[2] = 3rd element

</details>

---

**Assume that address of 0th index of array ‘a’ is : 200. What is the output ?**

    int a[] = {1, 2, 3, 4, 5};
    cout << *(a) << " " << *(a + 4);

**Options**

    a. Error
    b. 200 216
    c. 1 5
    d. None of these

<details> <summary><strong>Correct Answer</strong></summary>

    b. 1 5
    1st and 5th element

</details>

---

**Assume that address of 0th index of array ‘a’ is : 200. What is the output ?**

    int a[] = {1, 2, 3, 4};
    int *p = a++;
    cout << *p << endl;

**Options**

    a. 1
    b. 2
    c. Garbage Value
    d. Error

<details> <summary><strong>Correct Answer</strong></summary>

    d. Error
    int *p = a is okay, but a = a+1 is invalid, coz it intends to make a change in the symbol table.

</details>

---

# End Of Quiz
