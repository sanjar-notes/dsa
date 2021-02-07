#include <bits/stdc++.h>
using namespace std;

freopen("in.txt", "r", stdin);

void func(string &n, vector<pair<int, vector<int>>> arr);

int main()
{
    // freopen("in.txt", "r", stdin);
    vector<pair<int, vector<int>>> arr(26);
    int cases = 0;
    cin >> cases;
    string *ip = new string[cases];
    for (int i = 0; i < cases; i++)
        cin >> ip[i];

    // output
    for (int i = 0; i < cases; i++)
        func(ip[i], arr);
    return 0;
}

void func(string &n, vector<pair<int, vector<int>>> arr)
{
    // clear the containers
    for (int i = 0; i < 26; i++)
        arr[i].first = 0, arr[i].second.clear();

    for (int i = 0; i < n.size(); i++)
        arr[n[i] - 'a'].first++, arr[n[i] - 'a'].second.push_back(i + 1);

    // check if an odd exists
    int odds = 0, odd = -1;

    for (int p = 0; p < 26; p++)
    {
        if (arr.at(p).second.size() % 2 == 1)
        {
            odd = p;
            odds += 1;
        }
        if (odds > 1)
        {
            cout << -1 << endl;
            return;
        }
    }

    // start filling the values, edit the given array itself
    int outp[n.size()];
    int i = 0, j = n.size() - 1;

    for (int p = 0; p < 26; p++)
    {
        if (p == odd)
            continue;
        while (arr.at(p).second.size() != 0)
        {
            outp[i++] = arr.at(p).second.back();
            arr.at(p).second.pop_back();
            outp[j--] = arr.at(p).second.back();
            arr.at(p).second.pop_back();
        }
    }

    // place the odd one at the center
    for (int k = i; k <= j; k++)
    {
        outp[k] = arr.at(odd).second.front();
        arr.at(odd).second.pop_back();
    }

    //print the result
    for (int i = 0; i < n.size(); i++)
        cout << outp[i] << " ";
    cout << endl;
}
