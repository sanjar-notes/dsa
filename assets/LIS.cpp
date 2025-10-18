#include <iostream>
using namespace std;

int LIS(int arr[], int n)
{
    int *outp = new int[n];
    outp[0] = 1;
    for (int i = 1; i < n; i++)
    {
        outp[i] = 1;
        for (int j = i - 1; j >= 0; j--)
        {
            if (arr[j] < arr[i] && (oupt[j] + 1) > outp[i])
            {
                outp[i] += outp[j];
                break;
            }
        }
    }
    int ret = outp[n - 1];
    delete[] outp;
    return ret;
}

int main()
{

    int n;
    cin >> n;
    int *arr = new int[n];
    for (int i = 0; i < n; i++)
        cin >> arr[i];
    cout << LIS(arr, n);
    cout << endl;
    return 0;
}
