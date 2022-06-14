#include <bits/stdc++.h>
using namespace std;

int main()
{
    // n windows
    int n;
    cin >> n;

    // people after k revolutions, p = a[i] - k*n - i
    // answer = i for which p<=0 in the least time(kn+i).

    // we find the least time for which p<=0 for all
    // And select the one with the least value of time

    // Finding time, the only variable is k
    // p<=0
    // a[i]-k*n-i <=0
    // k = ceil((a[i]-i)/n

    // update answer if k*n+i is the minimum
    // Remember that people are dependent on time, and not vice-versa

    // minima boilerplate

    int k, time, inp;
    cin >> inp;
    k = inp / n;      // inp-0
    if (inp % n != 0) // inp-0
        k += 1;

    int min_time = k * n + 0;
    int ans = 0; // the minium seen
    for (int i = 1; i < n; i++)
    {
        cin >> inp;

        if (i >= inp)
            k = 0;
        else
        {
            k = (inp - i) / n;
            if ((inp - i) % n != 0)
                k += 1;
        }

        time = k * n + i;
        if (time < min_time)
        {
            min_time = time;
            ans = i;
        }
    }
    cout << ans + 1 << endl; // booth = index+1
    return 0;
}
