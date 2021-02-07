#include <iostream>
using namespace std;

void sorted_or_not(int arr[], int n);

int main()
{
    int x[] = {1, -22, 33};
    sorted_or_not(x, 3);
    cout << endl;
    return 0;
}

void sorted_or_not(int arr[], int n)
{
    if (n <= 1)
    {
        cout << "Sorted";
        return;
    }
    if (arr[0] <= arr[1])
        sorted_or_not(arr + 1, n - 1);
    else
    {
        cout << "Not sorted";
        return;
    }
}
