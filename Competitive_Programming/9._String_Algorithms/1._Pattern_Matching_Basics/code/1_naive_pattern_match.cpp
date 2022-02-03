#include <iostream>
using namespace std;

bool naive_p_match(const string &p, const string &s)
{
    for (int i = 0, end = s.size() - p.size(); i <= end; i++)
    {
        bool flag = true; // assuming match occurs
        // we are within range here
        for (int j = i, end = i + p.size(); j < end; j++)
        {
            if (s[j] == p[j - i])
                continue;
            else
            {
                flag = false;
                break;
            }
        }
        if (flag)
            return true;
    }
    return false;
}

int main()
{
    string s, p;
    getline(cin, s);
    getline(cin, p);
    cout << naive_p_match(p, s);
    cout << endl;
    return 0;
}
