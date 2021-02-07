#include <iostream>
using namespace std;
#include "PriorityQueue.h"

int main()
{
    PriorityQueue<int> pq;
    vector<int> vc = {1, 4, 5, 6, -90, 7};

    for (auto x : vc)
        pq.insert(x);
    // pq.removeMin();
    cout << pq.getMin();
    return 0;
}
