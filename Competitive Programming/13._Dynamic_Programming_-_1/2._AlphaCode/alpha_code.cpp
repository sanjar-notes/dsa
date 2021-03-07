#include <iostream>
using namespace std;

int alphaCode1(int n, int arr[])
{
    if (n <= 1)
        return 1; //empty string
    int one = alphaCode1(n - 1, arr + 1);
    int two = (arr[0] * 10 + arr[1] <= 26) ? alphaCode1(n - 2, arr + 2) : 0;
    return one + two;
}

int alphaCode2(int n, int arr[], int memo[])
{
    if (memo[n])
        return memo[n];
    int one = memo[n - 1] = alphaCode2(n - 1, arr, memo); /// a123 as f(12) and 3
    // left to right
    int two = (arr[n - 2] * 10 + arr[n - 1] <= 26) ? alphaCode2(n - 2, arr, memo) : 0; // a123 as f(ak1) and 23(1)
    return (memo[n] = one + two);
}

// alphaCode2 works like this
// 1. Goes from right to left
// 2. Fills the value from left to right.(using the previous results(left))
// 3. Returns the right most-value memo[n]

// We can omit step 1 altogether
// And write a loop.

int alphaCode3(int n, int arr[])
{
    if (n <= 1)
        return 1;
    int memo[n + 1] = {1, 1}; // no need of initialization
    for (int i = 1; i < n; i++)
    {
        // for each position we treat it as itself and with the one on the left
        // The right ones depend on the left ones, for all.
        // memo[n] means the nth character is the last one
        memo[i + 1] = memo[i];
        if (arr[i - 1] * 10 + arr[i] <= 26)
            memo[i + 1] += memo[i - 1];
    }
    return memo[n];
}

// note that at any time we need, at most, two values on the left
// Therefore, we can just have two variables, instead of an array.
int alphaCode4(int n, int arr[])
{
    if (n <= 1)
        return 1;
    int a = 1, b = 1; // for memo[0] an memo[1]
    int temp;
    for (int i = 1; i < n; i++)
    {
        temp = b;
        if(arr[i]==0 && arr[i-1]>2)
            return 0;
        if (arr[i - 1] * 10 + arr[i] <= 26)
            temp += a;
        // move by 1
        a = b;
        b = temp;
    }
    return b;
}

int main()
{
    int n;
    cin >> n;
    int arr[n];
    for (int i = 0; i < n; i++)
        cin >> arr[i];

    // cout << alphaCode1(n, arr);

    // int memo[n + 1] = {1, 1};
    // for (int i = 2; i < n + 1; i++)
    //     memo[i] = 0;
    // cout << alphaCode2(n, arr, memo);

    // cout << alphaCode3(n, arr);

    cout << alphaCode4(n, arr);
    cout << endl;
    return 0;
}
