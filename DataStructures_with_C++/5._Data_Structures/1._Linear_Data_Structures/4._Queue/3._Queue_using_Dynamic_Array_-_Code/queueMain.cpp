#include <iostream>
using namespace std;
namespace n1
{
#include "../1._Queue_using_array/queueUsingArray.h"
}
namespace n2
{
#include "queueUsingDynamicArray.h"
}

int main()
{
    n2::QueueUsingArray<int> q(10);
    for (int i = 0; i < 10; i++)
        q.enqueue(i + 1);
    q.print();
    // q.dequeue();
    cout << q.front();
    return 0;
}
