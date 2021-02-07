// #include <iostream>
#include <bits/stdc++.h>
// #include <vector>
using namespace std;

int main()
{
    freopen("in.txt", "r", stdin);
    // majority is kept
    // lower bound
    vector<vector<int> *> arrs(3);
    vector<int> nums(3);

    for (int i = 0; i < 3; i++)
        cin >> nums.at(i);
    for (int i = 0; i < 3; i++)
    {

        arrs[i] = new vector<int>(nums[i]);
        for (int j = 0; j < nums[i]; j++)
            cin >> arrs.at(i)->at(j);
    }

    int k = *max_element(nums.begin(), nums.end());

    vector<vector<int>::iterator> curr(3);
    for (int i = 0; i < 3; i++)
        curr.at(i) = arrs.at(i)->begin();

    auto min_id = curr.begin();
    short score = 0;
    short further = 0;
    for (int i = 0; i < k; i++)
    {
        // cout << "p";
        // check if the three
        // make a combine sorted list, and include only those which are repeated
        // kind of merging k sorted arrays
        min_id = min_element(curr.begin(), curr.end());
        score = 0, further = 0;
        for (int j = 0; j < 3; j++)
        {
            if (curr[j] != arrs[j]->end())
            {
                if (*min_id[0] == *curr[j])
                {
                    curr[j] += 1;
                    score++; // move the pointer by one
                }
            }
            else
                further++;
        }
        cout << *min_id[0] << endl;

        if (further > 1)
            return 0;
        if (score > 1)
            cout << *min_id[0] << endl;
    }
    return 0;
}
