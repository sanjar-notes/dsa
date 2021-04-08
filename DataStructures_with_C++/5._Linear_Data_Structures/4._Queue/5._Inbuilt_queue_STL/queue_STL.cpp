#include <iostream>
using namespace std;
#include <queue>

int main()
{

    queue<int> q;
    for (int i = 0; i < 0; i++)
        q.push(i + 1);

    // // cout << q.getSize();
    // q.print();
    cout << q.front();
    q.pop();
    cout << q.front();
    return 0;
}
