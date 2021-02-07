#include <iostream>
#include <vector>
#include <tuple>
#include <algorithm>
using namespace std;

void func(vector<pair<int, int>> &, vector<int>);

int main()
{
    int cases = 0;
    cin >> cases;
    vector<tuple<vector<pair<int, int>>, vector<int>>> ip(cases);
    for (int i = 0; i < cases; i++)
    {
        int num_args, subcases;
        cin >> num_args >> subcases;
        get<0>(ip[i]).resize(num_args);
        get<1>(ip[i]).resize(subcases);

        for (int j = 0; j < num_args; j++)
            cin >> get<0>(ip[i])[j].first >> get<0>(ip[i])[j].second;
        //extra arguments

        for (int j = 0; j < subcases; j++)
            cin >> get<1>(ip[i])[j];
    }
    // io done

    // output
    for (int i = 0; i < cases; i++)
        func(get<0>(ip[i]), get<1>(ip[i]));

    return 0;
}

void func(vector<pair<int, int>> &vec, vector<int> p)
{
    // Focus on the array and the problem
    sort(vec.begin(), vec.end());
    for (int i = 0, j = p.size(); i < j; i++)
    {
        auto ret = lower_bound(vec.begin(), vec.end(), make_pair(p[i], 0));
        if (ret == vec.end()) // not found
            cout << -1;
        else if (ret == vec.begin()) // the first interval
            cout << ret->first - p[i];
        else
        {
            if (ret->first == p[i])
                cout << 0;
            else
            {
                int checker = (ret - 1)->second - p[i];
                if (checker > 0)
                    cout << 0;
                else
                    cout << ret->first - p[i];
            }
        }
        cout << endl;
    }
}
