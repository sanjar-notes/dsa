#include <iostream>
using namespace std;
#include "hashMap.h"
int main()
{
    ourmap<int> mp;
    for (int i = 0; i < 10; i++)
        mp.insert("abc" + '0' + i, i + 1);

    cout << mp.size() << " " << mp.capacity() << endl;
    // cout << mp.getValue("abc1");

    for (int i = 0; i < 10; i++)
        cout << mp.getValue("abc" + '0' + i) << endl;

    cout << endl;
    return 0;
}
