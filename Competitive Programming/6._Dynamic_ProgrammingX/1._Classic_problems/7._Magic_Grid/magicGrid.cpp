#include <bits/stdc++.h>
using namespace std;

int magic_grid(int **arr, int m, int n, int si, int sj, int ei, int ej);

int main()
{
    int t;
    cin >> t;
    int m, n;
    while (t--)
    {
        cin >> m >> n;
        int **arr = new int *[m];
        for (int i = 0; i < m; i++)
        {
            arr[i] = new int[n];
            for (int j = 0; j < n; j++)
                cin >> arr[i][j];
        }

        cout << magic_grid(arr, m, n, 0, 0, m - 1, n - 1) << endl;

        for (int i = 0; i < m; i++)
            delete[] arr[i];
        delete[] arr;
    }
    return 0;
}

int magic_grid(int **arr, int m, int n, int si, int sj, int ei, int ej)
{
    int **memo = new int *[m];
    for (int i = 0; i < m; i++)
        memo[i] = new int[n];

    // memo cell symbolizes the minimum health before starting from that cell
    // minimum value at any place can be 1. We need to find the minimum value at si, sj so that we can reach ei, ej
    // now memo[ei][ej] = arr[ei][ej], we have to go there no matter what
    // memo[ei][ej] = arr[ei][ej] >=0 ? 1 : 1 - arr[ei][ej];
    memo[ei][ej] = arr[ei][ej] >= 0 ? 1 : 1 - arr[ei][ej];

    // can move only right or down ==> f(i, j) = min(f(i+1,j), f(i, j+1)) > 0 ? 1 : max(f(i+1,j), f(i, j+1))+1;
    // One of the move is constrained in the bottom-most and the right-most border
    // so we can initialize them

    for (int i = ei - 1; i >= si; i--)
    {
        memo[i][ej] = memo[i + 1][ej] - arr[i][ej];
        if (memo[i][ej] <= 0)
            memo[i][ej] = 1;
    }

    for (int j = ej - 1; j >= sj; j--)
    {
        memo[ei][j] = memo[ei][j + 1] - arr[ei][j];
        if (memo[ei][j] <= 0)
            memo[ei][j] = 1;
    }

    // we have all our values computed
    for (int i = ei - 1; i >= si; i--)
    {
        for (int j = ej - 1; j >= sj; j--)
        {
            memo[i][j] = min(memo[i][j + 1], memo[i + 1][j]) - arr[i][j]; // choose the path with least pre-cost
            if (memo[i][j] <= 0)
                memo[i][j] = 1; // everything is okay
        }
    }

    int ret = memo[0][0];

    for (int i = 0; i < m; i++)
        delete[] memo[i];
    delete[] memo;

    return ret;
}

// 1
// 2 3
// 0 1 -3
// 1 -2 0
