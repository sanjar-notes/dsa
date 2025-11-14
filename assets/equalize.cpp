#include <iostream>
using namespace std;

int main()
{
    int n;
    cin >> n;
    char arr1[n], arr2[n];
    for (int i = 0; i < n; i++)
        cin >> arr1[i];
    for (int i = 0; i < n; i++)
        cin >> arr2[i];

    // do we need two of them yes, we need to have 1 Lookahead
    int cost = 0;
    for (int i = 0; i < n; i++)
    {
        if (arr1[i] != arr2[i])
        {
            if (i < n - 1 && arr1[i + 1] == arr2[i] && arr1[i] == arr2[i + 1])
                cost++, i++; // single flip
            else
                cost++; // last one
        }
    }
    cout << cost << endl;
    return 0;
}

