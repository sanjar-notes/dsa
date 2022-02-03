#include <bits/stdc++.h>
using namespace std;

int minCost_recur(int cost[4][4], int n, int p, int mask, int *dp)
{
    // if (p >= n)
    //     return 0;
    if (dp[mask] != INT_MAX)
        return dp[mask];
    int minimum = INT_MAX;
    for (int j = 0; j < n; j++)
    {
        if (!mask & (1 << j)) // if the jth job is vacant (R->L)
        {
            int ans = minCost_recur(cost, n, p + 1, mask | (1 << j), dp) + cost[p][j]; // pth person assigned job j
            if (ans < minimum)
                minimum = ans;
        }
    }
    return minimum;
}

int main()
{
    int cost[4][4] = {{10, 2, 6, 5}, {1, 15, 12, 8}, {7, 8, 9, 3}, {15, 13, 4, 10}};
    int *dp = new int[1 << 4];
    for (int i = 0, end = (i << 4); i < end; i++)
        dp[i] = INT_MAX;
    cout << minCost_recur(cost, 4, 0, 0, dp) << endl;
    return 0;
}
