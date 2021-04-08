#include <iostream>
using namespace std;

int main()
{
    int a = 0;
    cin >> a;
    int n = a / 2;

    // defining all variables here.
    int i = 1, j = 1, spaces = 1;

    // phase 1, simplem triangle
    i = 1;
    while (i <= n + 1)
    {
        spaces = 1;
        while (spaces <= n - i + 1)
        {
            cout << " ";
            spaces++;
        }
        j = 1;
        while (j <= 2 * i - 1)
        {
            cout << "*";
            j++;
        }
        cout << endl;
        i++;
    }
    // end of phase 1, working as required. This contains the medium face as well, the one with no spaces.

    // phase 2 starts
    // q1 -> n rows
    // q2 -> i spaces followed by a - 2*i stars
    // q3 -> done it

    i = 1;
    while (i <= n)
    {
        spaces = 1;
        while (spaces <= i)
        {
            cout << " ";
            spaces++;
        }
        j = 1;
        while(j<=a-2*i){
            cout << "*";
            j++;
        }
        cout << endl;
        i++;
    }
}
