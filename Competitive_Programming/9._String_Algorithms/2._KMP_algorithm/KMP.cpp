#include <bits/stdc++.h>
using namespace std;

bool kmp(string &text, string &pattern);

int *getlps(string &pattern);

int main()
{
    string text = "adadabadadabadadad", pattern = "adadabadadabadad";
    // cout << "Enter case string: ";
    // getline(cin, text);
    // cout << "Enter patter: ";
    // getline(cin, pattern);
    if (kmp(text, pattern))
        cout << "Matched";
    else
        cout << "Does not match";
    cout << endl;
    return 0;
}

bool kmp(string &text, string &pattern)
{
    // build table
    int n = text.length(), m = pattern.length();
    int *lps = getlps(pattern);
    cout << "[=";
    int i = 0, j = 0;
    while (i < n && j < m)
    {
        if (text[i] == pattern[j])
        {
            i++, j++; // continue in both strings and pattern
        }
        else
        {
            if (j != 0)
            {
                j = lps[j - 1];
            }
            else
                i++;
        }
        cout << "=>\b";
    }
    cout << "\n";
    return j == m; // end of pattern
}

int *getlps(string &pattern)
{
    int m = pattern.size();
    int *lps = new int[m];
    lps[0] = 0;
    int i = 1, j = 0;
    for (int i = 1; i < m; i++)
    {
        if (pattern[i] == pattern[j])
            lps[i] = ++j;
        else
        {
            if (j == 0)
                lps[i] = 0; // cannot go further
            else
                j = lps[j - 1], i--;
        }
    }
    // while (i < m)
    // {
    //     if (pattern[i] == pattern[j])
    //     {
    //         lps[i] = j + 1;
    //         j++;
    //         i++;
    //     }
    //     else
    //     {
    //         if (j != 0)
    //             j = lps[j - 1];
    //         else
    //         {
    //             lps[i] = 0; // cannot go further
    //             i++;
    //         }
    //     }
    // }
    return lps;
}
