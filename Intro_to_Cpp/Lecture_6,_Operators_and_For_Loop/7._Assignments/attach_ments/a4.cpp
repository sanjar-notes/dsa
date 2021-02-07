/*
Statement
                    <---Binary to decimal--->
Given a binary number as an integer N, convert it into decimal and print.
Input format :
An integer N
Output format :
Corresponding Decimal number (as integer)
Sample Input 1 :
1100
Sample Output 1 :
12
Sample Input 2 :
111
Sample Output 2 :
7
*/

#include <iostream>
using namespace std;

int main()
{
    // Write your code here
    // only for +ve binary inputs n
    int n;
    cin >> n;
    int res = 0, po = 1;
    while (n > 0)
    {
        res += po * (n % 10);
        n = n / 10;
        po *= 2;
    }
    cout << res;
}
