#include <iostream>
using namespace std;

#define N 3
int min_cost(int **input, int m, int n, int si, int sj, int ei, int ej);

int main()
{
    int m, n;
    cin >> m >> n;
    int **arr = new int *[m];
    for (int i = 0; i < m; i++)
    {
        arr[i] = new int[n];
        for (int j = 0; j < n; j++)
            cin >> arr[i][j];
    }
    // no checks for start and end
    cout << min_cost(arr, m, n, 0, 0, m - 1, n - 1);
    cout << endl;
    return 0;
}

int min_cost(int **input, int m, int n, int si, int sj, int ei, int ej)
{
    int **memo = new int *[m];
    for (int i = 0; i < m; i++)
        memo[i] = new int[n];

    // f(i, j) = min(f(i + 1, j), f(i, j + 1), f(i + 1, j + 1)) top-down
    // for bottom up

    memo[ei][ej] = input[ei][ej];

    for (int i = ej - 1; i >= sj; i--) // bottom most row
        memo[ei][i] = input[ei][i] + memo[ei][i + 1];

    for (int j = ei - 1; j >= si; j--) // right most column
        memo[j][ej] = input[j][ej] + memo[j + 1][ej];

    for (int i = ei - 1; i >= si; i--)
    {
        for (int j = ej - 1; j >= sj; j--)
            memo[i][j] = input[i][j] + min(memo[i + 1][j + 1], min(memo[i + 1][j], memo[i][j + 1]));
    }

    int ret = memo[si][sj];

    for (int i = 0; i < m; i++)
        delete memo[i];
    delete[] memo;

    return ret;
}
