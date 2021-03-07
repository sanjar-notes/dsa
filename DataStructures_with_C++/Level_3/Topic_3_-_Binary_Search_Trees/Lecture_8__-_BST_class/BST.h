#include <climits>
class BST
{
public:
    BinaryTreeNode<int> *root;

private:
    bool hasData(int data, BinaryTreeNode<int> *root)
    {
        if (root == NULL)
            return false; // not found

        if (root->data == data)
            return true;

        if (data < root->data) // look in the left subtree
            return hasData(data, root->left);
        return hasData(data, root->right); // looking in the right subtree

        // or just
        // root->data==data || hasData(data, root->left) || hasData(data, root->right);
    }

    BinaryTreeNode<int> *insert(int data, BinaryTreeNode<int> *root)
    {
        if (root == NULL)
        {
            root = new BinaryTreeNode<int>(data);
            return root;
        }

        //assign to the correct subtree, we do this coz one of them could be NULL
        if (root->data < data) // in the left subtree
            root->right = insert(data, root->right);
        // if (root->data > data) // in the right subtree
        else
            root->left = insert(data, root->left);
        return root; // required where we try to insert duplicate data
    }

    BinaryTreeNode<int> *deleteData(int data, BinaryTreeNode<int> *root)
    {
        if (root == NULL)
            return NULL;

        // root is definitely not NULL

        if (data > root->data)
            root->right = deleteData(data, root->right);

        else if (data < root->data)
            root->left = deleteData(data, root->left);

        else // base case, i.e found the node
        {
            if (root->left == NULL) // no left subtree or leaf case
            {
                BinaryTreeNode<int> *newroot = root->right;
                root->right = NULL; // disconnecting the parent first. So that deallocation does not kill the whole tree.
                delete root;
                return newroot;
            }

            if (root->right == NULL) // Left tree is there but no right subtree
            {
                BinaryTreeNode<int> *newroot = root->left;
                root->left = NULL; // removing the parent first. So that deallocation does not kill the whole tree.
                delete root;
                return newroot;
            }

            // both left and right subtrees exist
            // doing in an iterative way
            // min in the right subtree

            BinaryTreeNode<int> *minNode = root->right; // root of right subtree, this is not NULL

            //             if (minNode->left == NULL) // the right subtree is just one node
            //             {
            //                 root->right = NULL;
            //                 delete minNode;
            //                 return root;
            //             }

            //             while (minNode->left != NULL && minNode->left->left != NULL)
            //                 minNode = minNode->left;

            //             // we are now on the parent of minNode
            //             root->data = minNode->left->data;

            //             // delete the minNode->left
            //             // deallocate
            //             delete minNode->left;
            //             minNode->left = NULL;

            while (minNode->left != NULL)
                minNode = minNode->left;
            // we have reached the minNode
            root->data = minNode->data;
            root->right = deleteData(root->data, root->right);
            return root;
        }

        return root;
    }

    void printTree(BinaryTreeNode<int> *root)
    {
        if (root == NULL)
            return;
        cout << root->data << ":";

        if (root->left != NULL)
            cout << "L:" << root->left->data << ",";
        if (root->right != NULL)
            cout << "R:" << root->right->data;

        cout << endl;

        printTree(root->left);
        printTree(root->right);
    }

public:
    BST()
    {
        root = NULL;
    }

    bool hasData(int data)
    {
        return hasData(data, root);
    }

    int max(BinaryTreeNode<int> *root)
    {
        if (root == NULL)
            return INT_MIN;
        return max(root->right);
    }

    int min(BinaryTreeNode<int> *root)
    {
        if (root == NULL)
            return INT_MAX;
        return min(root->left);
    }

    void insert(int data)
    {
        // how to, just insert give the data to the tree which has to have it
        // it will attach itself
        // somewhat like c onstructing the tree again
        root = insert(data, root); // The root changes when the tree is empty
    }

    void deleteData(int data)
    {
        root = deleteData(data, root);
    }

    void printTree()
    {
        printTree(root);
    }

    ~BST()
    {
        delete root;
    }
};
