#include <iostream>
using namespace std;
#include "queueUsingArray.h"

int main()
{
    QueueUsingArray<int> q(4);
    for (int i = 0; i < 4; i++)
        q.enqueue(i*i);
    // q.dequeue();
    q.print();
    return 0;
}
