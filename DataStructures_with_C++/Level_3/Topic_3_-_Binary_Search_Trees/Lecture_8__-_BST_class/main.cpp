#include <iostream>
using namespace std;


template <typename T>
class BinaryTreeNode
{
public:
    T data;
    BinaryTreeNode<T> *left;
    BinaryTreeNode<T> *right;

    BinaryTreeNode(T data)
    {
        this->data = data;
        this->left = NULL;
        this->right = NULL;
    }
};

#include "BST.h"

int main()
{
    BST *tree = new BST();
    int choice, input;
    while (true)
    {
        cin >> choice;
        switch (choice)
        {
        case 1:
            cin >> input;
            tree->insert(input);
            break;
        case 2:
            cin >> input;
            tree->deleteData(input);
            break;
        case 3:
            cin >> input;
            if (tree->hasData(input))
            {
                cout << "true" << endl;
            }
            else
            {
                cout << "false" << endl;
            }
            break;
        default:
            tree->printTree();
            return 0;
            break;
        }
    }
}
