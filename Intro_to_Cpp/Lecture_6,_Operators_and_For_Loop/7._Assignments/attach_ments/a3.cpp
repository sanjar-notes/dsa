/*
Statement
                        <---Reverse of a number--->
Write a program to generate the reverse of a given number N. Print the corresponding reverse number.
Input format :
Integer N
Constraints:
Time Limit: 1 second
Output format :
Corresponding reverse number
Sample Input 1 :
1234
Sample Output 1 :
4321
Sample Input 2 :
1980
Sample Output 2 :
891
*/

#include<iostream>
using namespace std;

int main() {
	// Write your code here
	// use the general quick method using % and /
    int n;
    cin >> n;
    int result = 0;
    while(n>0){
        result = 10*result + n%10;
        n = n/10;
    }
    cout << result <<endl;

}
