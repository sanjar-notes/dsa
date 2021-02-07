#include <bits/stdc++.h>
using namespace std;

void func(vector<int> &, long);

int main()
{
    int cases = 0;
    cin >> cases;
    vector<tuple<vector<int>, long>> ip(cases);
    for (int i = 0; i < cases; i++)
    {
        int num_args;
        cin >> num_args;
        cin >> get<1>(ip[i]);
        get<0>(ip[i]).resize(num_args);
        for (int j = 0; j < num_args; j++)
            cin >> get<0>(ip[i])[j];
        //extra arguments
    }
    // io done

    // output
    for (int i = 0; i < cases; i++)
        func(get<0>(ip[i]), get<1>(ip[i]));

    return 0;
}

void func(vector<int> &vec, long k)
{
    // Focus on the array and the problem
    //definition
    sort(vec.begin(), vec.end());
    if (k <= vec.size())
    {

        cout << *(vec.end() - k) << endl;
    }
    else
    {
        int sum = 0;
        for (int i = 0, n = vec.size(); i < n; i++)
            sum += vec[i];
        cout << sum / k << endl;
    }
}
