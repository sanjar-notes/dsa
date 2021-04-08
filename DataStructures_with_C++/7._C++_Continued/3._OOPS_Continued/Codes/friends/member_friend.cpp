#include <iostream>
#include <bits/stdc++.h>
using namespace std;

int main()
{
    priority_queue<int> p;
    int arr[] = {1, 3, 56, 4, 43, 4, 5, 2};
    for (int i = 0; i < 8; i++)
        p.push(arr[i]);

    int x = 0;

    for (int it = 0; it < 8; it++)
    {
        x = p.top();
        p.pop();
        cout << x << " ";
    }

    for (int i = 0; i < 8; i++)
        p.push(i);

    priority_queue<int> q;
    for (int i = 0; i < 8; i++)
        q.push(i + 11);
    q.swap(p);

    for (int it = 0; it < 8; it++)
    {
        x = p.top();
        p.pop();
        cout << x << " ";
    }

    cout << endl;
    return 0;
}
