/*
                                        <---Decimal to Binary--->
Given a decimal number (integer N), convert it into binary and print.
The binary number should be in the form of an integer.
Note : The given input number could be large, so the corresponding binary number can exceed the integer range. So take the answer as long.
Input format :
Integer N
Output format :
Corresponding Binary number (long)
Sample Input 1 :
12
Sample Output 1 :
1100
Sample Input 2 :
7
Sample Output 2 :
111
*/

#include <iostream>
using namespace std;
// the easiest way to do this, the most intuitive too.
int main()
{
    // Write your code here
    int n;
    cin >> n;
    long bin = 0l;
    long rol = 1l; // used for keeping the digits safe
    while (n > 0)
    {
        bin += (n % 2) * rol;
        n = n / 2;
        rol *= 10l;
    }
    cout << bin << endl;
}
