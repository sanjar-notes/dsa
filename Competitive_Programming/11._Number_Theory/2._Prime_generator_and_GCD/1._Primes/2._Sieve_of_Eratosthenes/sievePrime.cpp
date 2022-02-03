#include <iostream>
#include <cmath>
using namespace std;

void sieve(int n)
{
    if (n < 2)
        return;
    bool *arr = new bool[n + 1]{false, false}; // for 0 to 1s

    for (int i = 2; i < n + 1; i++)
        arr[i] = true;
    bool flag = false;
    for (int i = 2, end = int(sqrt(n)); i < end; i++)
    {
        flag = false;
        for (int j = 2; j < i; j++)
        {
            if (i % j == 0)
            {
                flag = true;
                break;
            }
        }
        if (flag)
            continue;

        // Old factor tweak passed
        // start from i
        int j = i;
        while (j * i < n + 1)
        {
            arr[i * j] = false;

            j += 1;
        }
    }

    for (int i = 2; i < n + 1; i++)
    {
        if (arr[i])
            cout << i << " ";
    }
    delete[] arr;
}

int main()
{
    int n;
    cin >> n;
    sieve(n);
    cout << endl;
    return 0;
}
