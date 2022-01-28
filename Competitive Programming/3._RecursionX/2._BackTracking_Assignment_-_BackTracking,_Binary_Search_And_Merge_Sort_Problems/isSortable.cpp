#include <bits/stdc++.h>
using namespace std;
int main()
{
    // Constraints:
    // 		Only bubble sort is allowed
    // 		swap works iff difference is == 1

    // Observe that 1,0,3,2 can be sorted, but 1 3 0 2 cannot be.

    // we can perform bubble sort  - O(n^2)
    // Also we don't have to sort, we have to just say wether we can sort or not

    // The rankings range from 0 to n-1
    // Assume that we have a sorted array - We do some ops, 1 distance swaps.
    // After Each swap, both the swapped numbers cannot relocate
    // This means that such an array can be serially re-sorted

    // If any other swap function was used, we'd have a different type of array and serial sort won't be possible
    int t;
    cin >> t;

    int n, inp, i = 0;
    bool outp[t];

    // inputs
    for (int j = 0; j < t; j++)
    {
        cin >> n;
        for (i = 0; i < n; i++)
        {
            cin >> inp;
            if (inp == i) // everything is OK
                continue;
            else if (inp == i + 1)
            {
                cin >> inp; // mismatched positions
                if (inp == i)
                    i += 1;
                else
                    break;
            }
            else
                break;
        }
        outp[j] = (i == n); // sortable - loop ended successfully
    }

    //outputs
    for (i = 0; i < t; i++)
    {
        if (outp[i])
            cout << "Yes" << endl;
        else
            cout << "No" << endl;
    }
    return 0;
}
