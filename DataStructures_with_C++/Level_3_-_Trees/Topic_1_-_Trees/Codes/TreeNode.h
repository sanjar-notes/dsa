#include <vector>
using namespace std;

template <typename T>
class TreeNode
{
public:
    T data;
    vector<TreeNode<T> *> children; // we could also write <TreeNode*>
    TreeNode(T data=0)
    {
        this->data = data;
        // children is NULL by default
    }
};
