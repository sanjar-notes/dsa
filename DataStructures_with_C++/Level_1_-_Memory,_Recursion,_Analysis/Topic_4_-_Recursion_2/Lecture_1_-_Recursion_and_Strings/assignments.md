# Replace Character Recursively

    Given an input string S and two characters c1 and c2, you need to replace every occurrence of character c1 with character c2 in the given string.

    Do this recursively.

    Input Format :
    Line 1 : Input String S
    Line 2 : Character c1 and c2 (separated by space)
    Output Format :
    Updated string
    Constraints :
    1 <= Length of String S <= 10^6

**Sample Input 1**

    abacd
    a x

**Sample Output 1**

    xbxcd

<details> <summary><strong>Code</strong></summary>

    void replaceCharacter(char input[], char c1, char c2)
    {
        // static char* write = input;
        if(*input==0)
            return;
        if(*input==c1)
            *input=c2;
        replaceCharacter(input+1, c1, c2);
    }

</details>

---

# Remove Duplicates Recursively

    Given a string S, remove consecutive duplicates from it recursively.

    Input Format :
    String S
    Output Format :
    Output string
    Constraints :
    1 <= Length of String S <= 10^3

**Sample Input**

    aabccba

**Sample Output**

    abcba

<details> <summary><strong>Code</strong></summary>

    void helper(char* input, char* write);
    void removeConsecutiveDuplicates(char *input)
    {
        if(*input==0)
            return;
        helper(input, input);
    }

    void helper(char* curr, char* write)
    {
        if(*curr==0)
            return;

        // search for the difference
        while(*curr==*write)
            curr++;
        // curr is now a different aspect
        if(*curr=='\0')
        {
            *(write+1)=0;
            return;
        }

        *(write+1) = *curr;
        // call the function
        helper(curr, write+1);
    }

</details>

---

# Merge Sort

    Given a string S, remove consecutive duplicates from it recursively.

    Input Format :
    String S
    Output Format :
    Output string
    Constraints :
    1 <= Length of String S <= 10^3

**Sample Input**

    aabccba

**Sample Output**

    abcba

<details> <summary><strong>Code</strong></summary>

    void helper(char* input, char* write);
    void removeConsecutiveDuplicates(char *input)
    {
        if(*input==0)
            return;
        helper(input, input);
    }

    void helper(char* curr, char* write)
    {
        if(*curr==0)
            return;

        // search for the difference
        while(*curr==*write)
            curr++;
        // curr is now a different aspect
        if(*curr=='\0')
        {
            *(write+1)=0;
            return;
        }

        *(write+1) = *curr;
        // call the function
        helper(curr, write+1);
    }

</details>

---
