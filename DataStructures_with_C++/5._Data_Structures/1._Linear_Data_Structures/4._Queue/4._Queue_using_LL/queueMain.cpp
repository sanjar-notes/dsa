#include <iostream>
using namespace std;
#include "queueUsingLL.h"

int main()
{
    QueueUsingLL<int> q;
    for (int i = 0; i < 1; i++)
        q.enqueue(i + 1);
    q.dequeue();
    // cout << q.getSize();
    q.print();
    return 0;
}
