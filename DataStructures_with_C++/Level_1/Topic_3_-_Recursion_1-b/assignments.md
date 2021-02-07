# Replace pi (recursive)

    Given a string, compute recursively a new string where all appearances of "pi" have been replaced by "3.14".

**Sample Input 1**

    xpix

**Sample Output 1**

    x3.14x

**Sample Input 2**

    pipi

**Sample Output 2**

    3.143.14

**Sample Input 3**

    pip

**Sample Output 3**

    3.14p

<details> <summary><strong>Code</strong></summary>

void helper(char* arr, char* write);

void replacePi(char input[])
{
// using some auxilary space
int length = 0;
while(input[length]!=0)
length++;
// when we reach here, input[length] = 0. OK!

    char *cop = new char[length];
    for(int i=0; i<length; i++)
        cop[i] = input[i];
    cop[length]='\0';
    helper(cop, input);

}

void helper(char* arr, char* write)
{
if(*arr==0)
{
*write = 0;
return;
}

    if(*arr=='p' && *(arr+1)=='i')
    {
        *(write++) = '3';
        *(write++) = '.';
        *(write++) = '1';
        *(write++) = '4';
        helper(arr+2, write);
    }
    else
    {
        *(write++)=*arr;
        helper(arr+1, write);
    }

}

// to save time, use iterative shifting, no choice in that

</details>

---

# Remove X

    Given a string, compute recursively a new string where all 'x' chars have been removed.

**Sample Input 1**

    xaxb

**Sample Output 1**

    ab

**Sample Input 2**

    abc

**Sample Output 2**

    abc

**Sample Input 3**

    xx

**Sample Output 3**

    (empty string)

<details> <summary><strong>Code</strong></summary>

    void removeX(char input[])
    {
        static char* head = input;

        if(*input==0)
            return;

        if(*input!='x')
        {
            *head = *input;
            head++;
            removeX(input+1);
        }
        else
            removeX(input+1);
        *head=0; // put it at the end
    }

</details>

---

# String to Integer

    Write a recursive function to convert a given string into the number it represents. That is input will be a numeric string that contains only numbers, you need to convert the string into corresponding integer and return the answer.

    Input format :
    Numeric string (string, Eg. "1234")
    Output format :
    Corresponding integer (int, Eg. 1234)

**Sample Input 1**

    1231

**Sample Output 1**

    1231

**Sample Input 2**

    12567

**Sample Output 2**

    12567

<details> <summary><strong>Code</strong></summary>

    // Change in the given string itself. So no need to return or print the changed string.

    int helper(char* input, int & multiplier);

    int stringToNumber(char input[])
    {
        if(input[0]==0)
            return 0; // checking for an emoty string
        int multiplier = 1;
        return helper(input, multiplier);
    }

    int helper(char* input, int & multiplier)
    {
        if(*(input+1)=='\0')
            return (*input) - 48;
        int x = helper(input+1, multiplier);
        multiplier*=10;
        return x + multiplier*((*input)-48);
    }

    // we could have also traversed the string in backwards order.
    // This is better than coming up with a memory hog solution.

</details>

---

# Pair star

    Given a string, compute recursively a new string where identical chars that are adjacent in the original string are separated from each other by a "*".

**Sample Input 1**

    hello

**Sample Output 1**

    hel*lo

**Sample Input 2**

    xxyy

**Sample Output 2**

    x*xy*y

**Sample Input 3**

    aaaa

**Sample Output 3**

    a*a*a*a

<details> <summary><strong>Code</strong></summary>

    // Change in the given string itself. So no need to return or print the changed string.

    void pairStar(char input[])
    {
        if(*input==0)
            return;

        if(input[0]==input[1])
        {
            // shift array to the right by 1,
            char* wr = input+1;
            char temp  = 0; // for flipping with the element present at the write head write head
            char bag = '*';    // carries what is to be written
            while(*(wr-1)!=0)
            {
                temp = *wr;
                *wr = bag;
                bag = temp;
                wr++;
            }
            *(wr)=0;
            // done, move to the next i.e input+2
            pairStar(input+2);
        }

        // move by 1 step
        pairStar(input+1);
    }

</details>

---

# Tower of Hanoi

    Tower of Hanoi is a mathematical puzzle where we have three rods and n disks. The objective of the puzzle is to move all disks from source rod to destination rod using third rod (say auxiliary). The rules are :

        1) Only one disk can be moved at a time.
        2) A disk can be moved only if it is on the top of a rod.
        3) No disk can be placed on the top of a smaller disk.

    Print the steps required to move n disks from source rod to destination rod.
    Source Rod is named as 'a', auxiliary rod as 'b' and destination rod as 'c'.

    Input Format :
    Integer n
    Output Format :
    Steps in different lines (in one line print source and destination rod name separated by space)

**Sample Input**

    2

**Sample Output**

    a b
    a c
    b c

<details> <summary><strong>Code</strong></summary>

    void towerOfHanoi(int n, char source, char auxiliary, char destination)
    {
        if(n==0)
            return;
        if(n==1)
        {    // transfer directly or restated as as through auxiliary, but output is the same
            cout << source << " " << destination << endl;
            return;
        }
        if(n==2)
        {
            cout << source << " " << auxiliary << endl;
            cout << source << " " << destination << endl;
            cout << auxiliary << " " << destination << endl;
            return;
        }

        towerOfHanoi(n-1, source, destination, auxiliary);   // recursion, place the heap(without the heaviest) on the auxiliary
        cout << source << " " << destination << endl;        // heaviest from A to C using nothing
        towerOfHanoi(n-1, auxiliary, source, destination);   // the heap from B to C using A as the auxiliary
    }

    // Did it in one go, mathematical induction is so useful.

</details>

---
