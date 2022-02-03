#include <iostream>
using namespace std;

int longestBitonicSubarray(int *input, int n);

int main()
{
    int n, input[100000];
    cin >> n;
    for (int i = 0; i < n; i++)
    {
        cin >> input[i];
    }
    cout << longestBitonicSubarray(input, n);
    return 0;
}

int longestBitonicSubarray(int *input, int n)
{
    // for LincreSub we have to go from left to right(look from right to left)
    // for largest decreasing sub sarting from i, we go from right to left (look from left to right)
    // we'll keep a max sum value.
    pair<int, int> *memo = new pair<int, int>[n];

    memo[0].first = memo[0].second = memo[n - 1].first = memo[n - 1].second = 1; // okay

    for (int i = 0; i < n; i++) // ends have their answers already
    {
        // longest increasing subsequence
        // n-i
        memo[i].first = 1;
        for (int j = i - 1; j >= 0; j--)
        {
            if (input[j] < input[i] && (1 + memo[j].first) > memo[i].first)
                memo[i].first = 1 + memo[j].first;
        }

        memo[n - i - 1].second = 1;
        // longest decreasing subsequence
        for (int j = n - i; j < n; j++)
        {
            if (input[n - i - 1] > input[j] && (1 + memo[j].second) > memo[n - i - 1].second)
                memo[n - i - 1].second = 1 + memo[j].second;
        }
    }
    int ret = -1;

    // mind the maximum sum
    for (int i = 0; i < n; i++)
    {
        if (memo[i].first + memo[i].second > ret)
            ret = memo[i].first + memo[i].second;
    }
    delete[] memo;

    return ret - 1; // one for the common point
}

