#include <bits/stdc++.h>
using namespace std;

int main()
{
    int n, k;
    cin >> n >> k;
    int *arr = new int[n];

    int inp;
    for (int i = 0; i < n; i++)
        cin >> arr[i];
    sort(arr, arr + n);
    int i = 0, j = 1;
    long count = 0;
    while (j != n)
    {
        // i looking for variates
        while (arr[j] - arr[i] < k && j != n)
            j++;
        if (j == n)
            break;
        count += n - j; // the right, incl
        i++;            // update i
    }
    cout << count;
    return 0;
}
