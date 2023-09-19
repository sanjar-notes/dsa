# Lecture 5: Macros and Global Variables

**What is the output of the following program?**

    #include<iostream>
    using namespace std;

    int x = 1;

    void print()
    {
        int x = 2;
        {
            int x = 3;
            cout << x << endl;
        }
    }

    int main()
    {
        print();
        return 0;
    }

**Options**

    a. 1
    b. 2
    c. 3
    d. Error

<details> <summary><strong>Correct Answer</strong></summary>

    c. 3
    We declared variables at the innermost scope as the variables in the outer scope(s), hence the outer ones were 'shadwoed',
    hence only variable in the nearest scope was printed. 3 in this case, inside a code-block.

</details>

---

**What is the output of the following program?**

    #include <iostream>
    using namespace std;

    #define MULTIPLY(a, b) a*b

    int main()
    {
        cout << MULTIPLY(2+3, 3+5);
        return 0;
    }

**Answer**

    ____

<details> <summary><strong>Correct Answer</strong></summary>

    2 + 3*3 + 5 = 16
    "MULTIPLY(a, b)" will be replaced by "a*b" in code. So, MULTIPLY(2+3, 3+5) will be replaced by 2+3*3+5. And according to operator precedence, multiply operator (*) has higher precedence than plus operator (+). So, 3*3 will be evaluated first. Hence expression will become : 2+9+5 = 16

</details>

---

**What is the output of the following program?**

    #include <iostream>
    using namespace std;

    #define SQUARE(x) x*x

    int main()
    {
        int x = 36 / SQUARE(6);
        cout << x;
        return 0;
    }

**Answer**

    ____

<details> <summary><strong>Correct Answer</strong></summary>

    After the #define directibve is completed.
    We get int x = 36/6*6 = 36 / 6 * 6 = (36/6)*6 = 36 // paranthesisation is done by the compiler.
    So 36 is printed.

</details>

---

# Lecture 6: Inline and Default Arguments

**Inline functions are useful when \_\_\_\_**

**Options**

    a. Function is large with many nested loops
    b. Function has many static variables
    c. Function is small and we want to avoid function call overhead.
    d. None of the above

<details> <summary><strong>Correct Answer</strong></summary>

    c. Function is small and we want to avoid function call overhead.
    Obvious.

</details>

---

**What is the output of the following program ?**

    #include<iostream>
    using namespace std;

    int getValue(int x = 0, int y = 0, int z)
    {
        return (x + y + z);
    }

    int main()
    {
       cout << getValue(10);
       return 0;
    }

**Options**

    a. 10
    b. 0
    c. 20
    d. Compilation Error

<details> <summary><strong>Correct Answer</strong></summary>

    c. Function is small and we want to avoid function call overhead.
    Obvious.

</details>

---

**What is the output of the following program ?**

    Which of the following statement is correct?

**Options**

    a. Only one parameter of a function can be a default parameter.
    b. Minimum one parameter of a function must be a default parameter.
    c. All the parameters of a function can be default parameters.
    d. No parameter of a function can be default.

<details> <summary><strong>Correct Answer</strong></summary>

    c. All the parameters of a function can be default parameters.
    There's no restriction unless specified.

</details>

---

# Lecture 6: Constant Variables

**What is the output of the following program ?**

    #include <iostream>
    using namespace std;

    int main()
    {
        int  const  p = 5;
        cout << ++p;
        return 0;
    }

**Options**

    a. 5
    b. 6
    c. Error
    d. Garbage

<details> <summary><strong>Correct Answer</strong></summary>

    c. Error.
    Basics. Non change at the address in symbol table.

</details>

---

**What is the output of the following program ?**

    #include <iostream>
    using namespace std;

    int main()
    {
        int p = 5;
        int const *q = &p;
        p++;
        cout << p << endl;
        return 0;
    }

**Options**

    a. Error
    b. 5
    c. 6
    d. None

<details> <summary><strong>Correct Answer</strong></summary>

    c. 6
    Rule 1: Memories cannot be tagged const.
    Hence we can make a change through other paths(which just the old variable here).

</details>

---

**Which statement(s) will give an error for the following code -**

    #include <iostream>
    using namespace std;

    int main()
    {
        int p = 5;
        int const *q = &p;
    }

**Options**

    a. p++;
    b. q++;
    c. (*q)++;

<details> <summary><strong>Correct Answer</strong></summary>

    c. (*q)++;
    a. and b. will run without errors. Please read the declaration from right to left, we are protecting a int(through q), not the value we store in our pointer q. No restriction on the value of q.

    p is anyway indepenedent.

</details>

---

**Which statement(s) will give an error for the following code -**

    #include <iostream>
    using namespace std;

    int main()
    {
        int p = 5;
        int * const q = &p;
    }

**Options**

    a. p++;
    b. q++;
    c. (*q)++;

<details> <summary><strong>Correct Answer</strong></summary>

    b. q++
    When the declaration is read, then we can see that we are protecting q from change, so memory at the address is changeable.

    p is anyway independent.

</details>

---

**Which statement(s) will give an error for the following code -**

    #include <iostream>
    using namespace std;

    int main()
    {
        int p = 5;
        int const * const q = &p;
    }

**Options**

    a. p++;
    b. q++;
    c. (*q)++;

<details> <summary><strong>Correct Answer</strong></summary>

    b. (*q)++ and c. q++
    Reading the declaration, both the CHANGE OF q and the VALUE AT q are const.

    p is anyway independent.

</details>

---

**Which statement(s) will give an error for the following code -**

    #include <iostream>
    using namespace std;

    int main()
    {
        const int p = 5;
        int const *q = &p;
    }

**Options**

    a. p++;
    b. q++;
    c. (*q)++;

<details> <summary><strong>Correct Answer</strong></summary>

    a. p++ and c. (*q)++
    Value at p is const. So p++ will give and error.

    Value pointed by q is also const, so changing value through q is also an error.

    But changing q's value is still allowed.

</details>

---
