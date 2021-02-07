#include <iostream>
#include <vector>
#include <climits>
using namespace std;

//     DP Explanation:

//     Each cell has dependencies on its R, D and RD.
//     Except the destination, which is the only concrete value.

//     Now observe that for the L, U and LU of this final cell.

//     L depends on the destination(coz D and RD are absent), this will propagate along the the last row.
//     Each cell = input.cell.val + memo.right.val

//     Similarly the last column too has the same trend.
//     Each cell = input.cell.val + memo.up.val

//     What remains is all the intermdediate cells
//     Now the LU of the destination has its dependencies met. It becomes concrete.

//     // No need of initialization.

//     This pattern continues until we reach the RD of the starting point.
//     Here we return start.val + min(R, D, RD) for the start.

int mcp_dp(int **input, int m, int n)
{
    int **memo = new int *[m];

    for (int i = 0; i < m; i++)
        memo[i] = new int[n];

    memo[m - 1][n - 1] = input[m - 1][n - 1];

    // update the last row
    for (int j = n - 2; j >= 0; j--)
        memo[m - 1][j] = input[m - 1][j] + memo[m - 1][j + 1];

    // update the last column
    for (int i = m - 2; i >= 0; i--)
        memo[i][n - 1] = input[i][n - 1] + memo[i + 1][n - 1];

    for (int i = m - 2; i >= 0; i--)
    {
        for (int j = n - 2; j >= 0; j--)
            memo[i][j] = input[i][j] + min(memo[i + 1][j + 1], min(memo[i + 1][j], memo[i][j + 1]));
    }

    return memo[0][0];
}

// Memoization

int mcp_memo_h(int **input, int **memo, int m, int n, int i, int j)
{
    if (i > m - 1 || j > n - 1)
        return INT_MAX;

    if (memo[i][j] == -1)
        memo[i][j] = input[i][j] + min(mcp_memo_h(input, memo, m, n, i + 1, j + 1), min(mcp_memo_h(input, memo, m, n, i + 1, j), mcp_memo_h(input, memo, m, n, i, j + 1)));

    return memo[i][j];
}

int mcp_memo(int **input, int m, int n)
{
    int **memo = new int *[m];
    for (int i = 0; i < m; i++)
    {
        memo[i] = new int[n];
        for (int j = 0; j < n; j++)
            memo[i][j] = -1;
    }

    memo[m - 1][n - 1] = input[m - 1][n - 1];

    return mcp_memo_h(input, memo, m, n, 0, 0);
}

// Bruteforce
int mcp_bf_h(int **input, int m, int n, int i, int j)
{
    if (i == m - 1 && j == n - 1)
        return input[i][j];

    // out of range
    if (i > m - 1 || j > n - 1)
        return INT_MAX;

    int r = mcp_bf_h(input, m, n, i, j + 1);
    int rd = mcp_bf_h(input, m, n, i + 1, j + 1);
    int d = mcp_bf_h(input, m, n, i + 1, j);

    return input[i][j] + min(r, min(rd, d));
}

int mcp_bf(int **input, int m, int n)
{
    return mcp_bf_h(input, m, n, 0, 0);
}

int mcp(int **arr, int m, int n)
{
    return mcp_bf(arr, m, n);
    // return mcp_memo(arr, m, n);
    // return mcp_dp(arr, m, n);
}

int main()
{
    int **arr, m, n;
    cin >> m >> n;
    arr = new int *[m];
    for (int i = 0; i < m; i++)
        arr[i] = new int[n];

    for (int i = 0; i < m; i++)
    {
        for (int j = 0; j < n; j++)
            cin >> arr[i][j];
    }
    cout << mcp(arr, m, n) << endl;
}
