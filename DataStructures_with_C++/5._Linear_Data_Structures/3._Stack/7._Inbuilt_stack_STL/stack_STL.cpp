#include <iostream>
using namespace std;
#include <stack>

int main()
{
    stack<int> p;
    for (int i = 0; i < 7; i++)
        p.push(i);
    while (!p.empty())
    {
        cout << p.top() << " ";
        p.pop();
    }
    return 0;
}
