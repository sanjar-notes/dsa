/*
Statement
                                <---Square Root (Integral)--->

Given a number N, find its square root. You need to find and print only the integral part of square root of N.
For eg. if number given is 18, answer is 4.
Input format :
Integer N
Output Format :
Square root of N (integer part only)
Sample Input 1 :
10
Sample Output 1 :
3
Sample Input 2 :
4
Sample Output 2 :
2
*/

#include<iostream>
using namespace std;

int main() {
	// Write your code here
    // checking all squares from 1 to (sqrt(N))**2
    int n, i = 0;
    cin >> n;
    int p = i-1;
    while(i*i <= n){
        p = i++;
    } // when i surely exceeds, then only does the loop stop and as p is always 1 less than i, hence it is <= sqrt of N
    cout << p;

}
