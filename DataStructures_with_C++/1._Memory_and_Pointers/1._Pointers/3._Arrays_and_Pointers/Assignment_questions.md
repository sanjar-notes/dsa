# Assignment

**What will be the output ?**

    #include <iostream>
    using namespace std;
    void swap(char *x, char *y)
    {
        char *t = x;
        x = y;
        y = t;
    }

    int main()
    {
        char *x = "geeksquiz";
        char *y = "geeksforgeeks";
        char *t;
        swap(x, y);
        cout << x << " " << y;
        t = x;
        x = y;
        y = t;
        cout << " " << x << " " << y;
        return 0;
    }

**Options**

    a. geeksforgeeks geeksquiz geeksforgeeks geeksquiz
    b. geeksquiz geeksforgeeks geeksquiz geeksforgeeks
    c. geeksquiz geeksforgeeks geeksforgeeks geeksquiz
    d. Compiler Error

<details> <summary><strong>Correct Answer</strong></summary>

    c. geeksquiz geeksforgeeks geeksforgeeks geeksquiz
    The function changes only values of the formal parameters, and does not affect the value stored at the address.

</details>

---

**What will be the output ?**

    #include <iostream>
    using namespace std;
    int main()
    {
        float arr[5] = {12.5, 10.0, 13.5, 90.5, 0.5};
        float *ptr1 = &arr[0];
        float *ptr2 = ptr1 + 3;
        cout<<*ptr2<<" ";
        cout<< ptr2 - ptr1;
        return 0;
    }

**Options**

    a. 90.5 3
    b. 90.5 12
    c. 10.0 12
    d. undefined

<details> <summary><strong>Correct Answer</strong></summary>

    a. 90.5 3
    Basic arithmetic.

</details>

---

**What will be the output ?**

    #include<iostream>
    using namespace std;
    int main() {
        char st[] = "ABCD";
        for(int i = 0; st[i] != ‘\0’; i++) {
           cout << st[i] << *(st)+i << *(i+st) << i[st];
        }
        return 0;
    }

**Options**

    a. AAAABBBBCCCCDDDD
    b. ABCD
    c. A65AAB66BBC67CCD68DD
    d. Compilation Error

<details> <summary><strong>Correct Answer</strong></summary>

    c. A65AAB66BBC67CCD68DD
    st[i] = *(st+i) = *(i+st)
    while *(st)+i = ASCII_value + i

</details>

---

**What will be the output ?**

    #include <iostream>
    using namespace std;
    void Q(int z)
    {
        z += z;
        cout<<z << " ";
    }

    void P(int *y)
    {
        int x = *y + 2;
        Q(x);
        *y = x - 1;
        cout<<x << " ";
    }

    int main()
    {
        int x = 5;
        P(&x);
        cout<<x;
        return 0;
    }

**Options**

    a. 7 6 14
    b. 14 7 5
    c. 14 7 6
    d. 14 6 5

<details> <summary><strong>Correct Answer</strong></summary>

    c. 14 7 6
    Basics, do on pen and paper if need be.

</details>

---

**What will be the output ?**

    #include<iostream>
    using namespace std;
    int main()
    {
        int ***r, **q, *p, i=8;
        p = &i;
        (*p)++;
        q = &p;
        (**q)++;
        r = &q;
        cout<<*p << " " <<**q << " "<<***r;
        return 0;
    }

**Options**

    a. 8 8 8
    b. 10 10 10
    c. 9 10 11
    d. 9 10 10

<details> <summary><strong>Correct Answer</strong></summary>

    b. 10 10 10
    Basics, just draw a diagram.

</details>

---

**What will be the output ?**

    int f(int x, int *py, int **ppz)
    {
        int y, z;
        **ppz += 1;
        z = **ppz;
        *py += 2;
        y = *py;
        x += 3;
        return x + y + z;
    }

    int main()
    {
        int c, *b, **a;
        c = 4;
        b = &c;
        a = &b;
        cout << f(c, b, a);
        return 0;
    }

**Options**

    a. 21
    b. 18
    c. 19
    d. 24

<details> <summary><strong>Correct Answer</strong></summary>

    c. 19
    Basics, just draw a diagram. Make new memory for formal variables.

</details>

---

# End Of Quiz
