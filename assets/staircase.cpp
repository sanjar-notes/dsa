#include <iostream>
using namespace std;
long staircase(int n);

int main()
{
    int n;
    cin >> n;
    cout << staircase(n);
}

long staircase(int n)
{
    long *memo = new long[n];
    memo[0] = 1; // 1
    memo[1] = 2; // 2 and 1+1
    memo[2] = 4; // (1,1,1), (1,2), (2, 1), 3

    for (int i = 3; i < n; i++)
    {
        memo[i] = 0;
        for (int j = i - 1, end = i - 3; j >= end; j--)
            memo[i] += memo[j]; // by the last three
    }
    return memo[n - 1];
}
