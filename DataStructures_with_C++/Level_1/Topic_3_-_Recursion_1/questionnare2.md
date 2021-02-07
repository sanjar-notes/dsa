# Lecture 1, 2 and 3: Recursion Level 1 (till Fibonacci number)

**What is the output of the following program?**

    #include <iostream>
    using namespace std;

    int func(int num)
    {
        return func(num- 1);
    }

    int main()
    {
        int num = 5;
        int ans = func(num - 1);
        cout << ans;
    }

**Options**

    a. Compilation Error
    b. Runtime Error
    c. 5
    d. None of these

<details> <summary><strong>Correct Answer</strong></summary>

    b. Runtime Error
    No anchor condition, so recursion calls will never end. Hence Runtime error.

</details>

---

**What is the output of the following program?**

    #include <iostream>
    using namespace std;

    void print(int n)
    {
        if(n < 0)
        {
            return;
        }
        cout << n << " ";
        print(n - 2);
    }

    int main()
    {
        int num = 5;
        print(num);
    }

**Options**

    a. Runtime error
    b. 5 4 3 2 1
    c. 5 3 1
    d. None of these

<details> <summary><strong>Correct Answer</strong></summary>

    c. 5 3 1
    Simple recursion.

</details>

---

**What is the output of the following program?**

    #include <iostream>
    using namespace std;

    void print(int n)
    {
        if(n < 0)
        {
            return;
        }
        if(n == 0)
        {
            cout << n << “ “;
            return;
        }
        print(n --);
        cout << n << “ “;
    }

    int main()
    {
        int num = 3;
        print(num);
    }

**Options**

    a. Runtime error
    b. 3 2 1
    c. 3 3 3
    d. 0 1 2 3

<details> <summary><strong>Correct Answer</strong></summary>

    a. Runtime Error
    As we are passing n--(post -), so n is passed everytime in the recursion call. And as n is not decreasing, it is an infinite recursion.

</details>

---
