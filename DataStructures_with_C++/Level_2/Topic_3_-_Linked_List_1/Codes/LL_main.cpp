#include <iostream>
using namespace std;
#include "LL_node.hpp"

int main()
{
    Node *head = nullptr;

    for (int i = 0; i < 11; i++)
        insertNode(head, i, i);

    deleteNode(head, 11);
    print(head);
    return 0;
}
