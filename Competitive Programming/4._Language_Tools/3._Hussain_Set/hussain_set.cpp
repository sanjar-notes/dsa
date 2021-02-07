#include <iostream>
#include <algorithm>
#include <queue>
using namespace std;

typedef long long ll;
int main()
{
    freopen("in.txt", "r", stdin);
    int n, m;
    cin >> n >> m;
    ll arr[n];
    for (int i = 0; i < n; i++)
        cin >> arr[i];
    sort(arr, arr + n);
    queue<ll> q;
    int endp = n - 1;
    int count_m = 0, ip;

    ll curr_comp = arr[endp];
    for (int i = 0; i < m; i++)
    {
        cin >> ip;
        while (count_m != ip)
        {
            if (ip - 1 == count_m)
                cout << curr_comp << endl;
            // compare array[endp] and q.front() for the maximum

            // find the maximum
            if (endp > -1)
                curr_comp = arr[endp] > q.front() ? arr[endp], endp-- : q.front(), q.pop();
            else if (endp < 0)
                curr_comp = q.front(), q.pop();
            else
                curr_comp = arr[endp], endp--;

            if (curr_comp / 2 > 0) // place it in the queue
                q.push(curr_comp / 2);
            count_m++;
        }
    }
    return 0;
}
