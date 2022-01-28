# Lecture 4: Characters and Pointers

**What will be the output ?**

    char ch = 'a';
    char* ptr = &ch;
    ch++;
    cout << *ptr << endl;

**Options**

    a. a
    b. b
    c. 97
    d. 98

<details> <summary><strong>Correct Answer</strong></summary>

    b. b
    This should print all characters until it reaches a null character. But we can assume that the next one is a null character.

</details>

---

**Assume address of 0th index of array ‘b’ is 200. What is the output ?**

    char b[] = "xyz";
    char *c = &b[0];
    cout << c << endl;

**Options**

    a. 200
    b. x
    c. xyz
    d. None of these

<details> <summary><strong>Correct Answer</strong></summary>

    d. xyz
    This should print all characters until it reaches a null character.

</details>

---

**Assume that address of 0th index of array ‘a’ is : 200. What is the output ?**

    char b[] = "xyz";
    char *c = &b[0];
    c++;
    cout << c << endl;

**Options**

    a. 201
    b. y
    c. xyz
    d. yz

<details> <summary><strong>Correct Answer</strong></summary>

    d. yz
    This should print all characters until it reaches a null character.

</details>

---

**Fill the output ?**

    char s[]= "hello";
    char *p = s;
    cout << s[0] << " " << p[0];

**Answer**

    ____

<details> <summary><strong>Correct Answer</strong></summary>

    h h
    Why not hello hello or h hello? As we have used bracket notation, dereferencing has been done, and dereferencing happens according to the jump.
    The only anomaly is with character addresses(pointers and array_names), where instead of displaying the hex address, we get the derefenced char values till EOS.

</details>

---

# Lecture 5: Pointers and Functions

**Figure out the correct output of the following code.**

    void changeSign(int *p)
    {
        *p = (*p)  *  -1;
    }

    int main()
    {
        int a = 10;
        changeSign(&a);
        cout << a << endl;
    }

**Options**

    a. -10
    b.  10
    c.  Error
    d. None of the above

<details> <summary><strong>Correct Answer</strong></summary>

    -10
    We made changes at the address, and it will surely be reflected.

</details>

---

**Fill the output**

    void fun(int a[])
    {
        cout << a[0] << " ";
    }

    int main()
    {
        int a[] = {1, 2, 3, 4};
        fun(a + 1);
        cout << a[0];
    }

**Answer**

    ____

<details> <summary><strong>Correct Answer</strong></summary>

    2 1
    Obvious.

</details>

---

**What will be the output ?**

    void square(int *p)
    {
        int a = 10;
        p = &a;
        *p = (*p) * (*p);
    }

    int main()
    {
        int a = 10;
        square(&a);
        cout << a << endl;
    }

**Options**

    a. 100
    b. 10
    c. Error
    d. None of these

<details> <summary><strong>Correct Answer</strong></summary>

    10
    No changes were made at the location of the argument.

</details>

---

# Lecture 6: Double Pointer

**What will be the output ?**

    int a = 10;
    int *p = &a;
    int **q = &p;
    int b = 20;
    *q = &b;
    (*p)++;
    cout << a << " " << b << endl;

**Options**

    a. 10 21
    b. 11 20
    c. 11 21
    d. 10 20

<details> <summary><strong>Correct Answer</strong></summary>

    a. 10 21
    Use the diagram rules.

</details>

---

**What will be the output ?**

    int a = 100;
    int *p = &a;
    int **q = &p;
    int b = (**q)++ + 4;
    cout << a << " " << b << endl;

**Options**

    a. 100 104
    b. 101 104
    c. 101 105
    d. 100 105

<details> <summary><strong>Correct Answer</strong></summary>

    a. 101 104
    ++ is evaluated after the statement ends. Safe assumption.

</details>

---

**What will be the output ?**

    int a = 100;
    int *p = &a;
    int **q = &p;
    int b = (**q)++;
    int *r = *q;
    (*r)++;
    cout << a << " " << b << endl;

**Options**

    a. 102 100
    b. 101 100
    c. 101 101
    d. 102 101

<details> <summary><strong>Correct Answer</strong></summary>

    a. 102 100
    Draw a diagram.

</details>

---

**What will be the output ?**

    void increment(int **p)
    {
        (**p)++;
    }

    int main()
    {
        int num = 10;
        int *ptr = &num;
        increment(&ptr);
        cout << num << endl;
    }

    a. 10
    b. 11
    c. Error
    d. None of these

<details> <summary><strong>Correct Answer</strong></summary>

    b. 11
    The function changes the value at the address.

</details>

---

# End Of Quiz
