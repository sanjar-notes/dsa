#include <bits/stdc++.h>
using namespace std;

int mergeSort(int *arr, int n)
{
    if (n <= 1)
        return 0;
    int ret = mergeSort(arr, n / 2) + mergeSort(arr + n / 2, n - n / 2);
    int *arra = new int[n];
    int total = 0;
    int i = 0, j = n / 2;
    while (i < n / 2 && j < n)
    {
        if (arr[i] < arr[j])
        {
            ret += arr[i] * (n - j); // in-order catch the left part
            arra[total++] = arr[i++];
        }
        else if (arr[i] > arr[j])
            arra[total++] = arr[j++];
        else
            arra[total++] = arr[i++];
    }

    if (j == n) // the second one remains
    {
        j = i;     // continue
        i = n / 2; // end at i
    }
    else
        i = n;

    while (j < i)
        arra[total++] = arr[j++];

    for (int i = 0; i < total; i++)
        arr[i] = arra[i];

    delete arra;
    return ret;
}

int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        int n;
        cin >> n;
        int *arr = new int[n];
        for (int i = 0; i < n; i++)
            cin >> arr[i];
        cout << mergeSort(arr, n) << endl;
        // for (int i = 0; i < n; i++)
        //     cout << arr[i] << " ";
        cout << endl;
        delete arr;
    }
}
