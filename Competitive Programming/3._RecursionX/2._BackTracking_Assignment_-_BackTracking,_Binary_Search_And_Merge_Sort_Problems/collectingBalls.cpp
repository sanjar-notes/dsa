#include <bits/stdc++.h>
using namespace std;

int f(int n, int k) // Mr Sharma picks up kr balls, we need kr>=N/2
{
    int r = 0;
    while (n > k)
    {
        cout << "out\n";

        n -= k;   // Mr Sharma
        n *= 0.9; // Mr Singh takes 10 % of the remaining
        r++;
    }
    return k * r;
}

int main()
{
    int n;
    cin >> n;
    // do a binary search log N
    int start = 0, end = n, mid; // extremes: 0 to n
    while (start != end)
    {
        cout << "in";
        mid = (start + end) / 2;
        if (f(n, mid) < n / 2)
            start = mid + 1; // look to the right
        else
            end = mid - 1; //look to the left
    }
    cout << mid << endl; // k>1/2
    return 0;
}
