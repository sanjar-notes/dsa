# Return Keypad Code

    Given an integer n, using phone keypad find out all the possible strings that can be made using digits of input n.
    Return empty string for numbers 0 and 1.

    Note : The order of strings are not important.
    Input Format :
    Integer n
    Output Format :
    All possible strings in different lines
    Constraints :
    1 <= n <= 10^6

**Sample Input**

    23

**Sample Output**

    ad
    ae
    af
    bd
    be
    bf
    cd
    ce
    cf

<details> <summary><strong>Code</strong></summary>

    int keypad(int num, string output[])
    {
        /* Insert all the possible combinations of the integer number into the output string array. You do not need to
        print anything, just return the number of strings inserted into the array.
        */
        if (num <= 1)
        {
            output[0] = ""; // base case
            return 1;
        }
        // we can either do n%10 or n/multplier. The first is good.
        // as we are taking the last place it will need to be printed at the end of the branch. So a head recursion would suffice, I hope.

        int count = keypad(num / 10, output);

        // assume that the output is now filled.
        // we need to append the output with all possible values of the given string.

        int a = num % 10;
        string toPut = "";

        switch (a)
        {
        case 2:
            toPut = "abc";
            break;
        case 3:
            toPut = "def";
            break;
        case 4:
            toPut = "ghi";
            break;
        case 5:
            toPut = "jkl";
            break;
        case 6:
            toPut = "mno";
            break;
        case 7:
            toPut = "pqrs";
            break;
        case 8:
            toPut = "tuv";
            break;
        case 9:
            toPut = "wxyz";
            break;
        // default: return 1; // end of everything
        }

        // we need to make the copies of the output
        a = toPut.size();   // done with a
        int jumper = count; // jumper

        for (int i = 0; i < a - 1; i++)
        {
            for (int j = 0; j < count; j++)
            {
                output[jumper + j] = output[j];
            }
            jumper += count;
        }

        jumper = 0;
        // append the value
        for (int i = 0; i < a; i++)
        {
            char app = toPut[i];
            // cout << app << endl;
            for (int j = 0; j < count; j++)
            {
                output[jumper + j] += app;
            }
            jumper += count;
        }

        return a * count;
    }

    // 1 ""
    // 2 abc
    // 3 def
    // 4 ghi
    // 5 jkl
    // 6 mno
    // 7 pqrs
    // 8 tuv
    // 9 wxyz

</details>

---
