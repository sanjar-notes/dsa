#include <iostream>
using namespace std;
#include "LL_node.hpp"

int main()
{
    Node *head = nullptr;
    for (int i = 0; i < 10; i++)
        insertNode(head, i, i);

    return 0;
}
