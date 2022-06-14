# Assignments

<details> <summary><strong> 1. Sum of all nodes </strong></summary>

# 1. Sum of all nodes

    Given a binary tree, find and return the sum of all nodes.

**Input format**

    Elements in level order form (separated by space). If any node does not have left or right child, take -1 in its place.

**Sample Input**

    5 6 10 2 3 -1 -1 -1 -1 -1 9 -1 -1

**Sample Output**

    35

<details> <summary><strong>Code</strong></summary>

    // Following is the Binary Tree node structure
    /**************
    class BinaryTreeNode {
        public :
        T data;
        BinaryTreeNode<T> *left;
        BinaryTreeNode<T> *right;

        BinaryTreeNode(T data) {
            this -> data = data;
            left = NULL;
            right = NULL;
        }
    };
    ***************/

    int sumOfAllNodes(BinaryTreeNode<int> *root)
    {
        // preorder traversal
        if (root == NULL)
            return 0;

        return root->data + sumOfAllNodes(root->left) + sumOfAllNodes(root->right);
    }

</details>

---

</details>

<details> <summary><strong> 2. is Balanced </strong></summary>

# 2. is Balanced

    Given a binary tree, check if its balanced i.e. depth of left and right subtrees of every node differ by at max 1. Return true if given binary tree is balanced, false otherwise.

**Input Format**

    Elements in level order form (separated by space). If any node does not have left or right child, take -1 in its place.

**Sample Input 1**

    5 6 10 2 3 -1 -1 -1 -1 -1 9 -1 -1

**Sample Output 1**

    false

**Sample Input 2**

    1 2 3 -1 -1 -1 -1

**Sample Output 2**

    true

<details> <summary><strong>Code</strong></summary>

    // Following is the Binary Tree node structure
    /**************
    class BinaryTreeNode {
        public :
        T data;
        BinaryTreeNode<T> *left;
        BinaryTreeNode<T> *right;

        BinaryTreeNode(T data) {
            this -> data = data;
            left = NULL;
            right = NULL;
        }
    };
    ***************/

    // we need this function
    int height(BinaryTreeNode<int> *root)
    {
        if (root == NULL)
            return 0;
        return 1 + max(height(root->left), height(root->right));
    }

    bool isBalanced(BinaryTreeNode<int> *root)
    {
        if (root == NULL)
            return true;

        int dif = height(root->left) - height(root->right);
        dif = dif > 0 ? dif : -dif;

        if (dif <= 1)
            return isBalanced(root->left) && isBalanced(root->right);
        return false;
    }

</details>

---

</details>

<details> <summary><strong> 3. Level order traversal </strong></summary>

# 3. Level order traversal

    Given a binary tree, print the level order traversal. Make sure each level start in new line.

**Input Format**

    Elements in level order form (separated by space). If any node does not have left or right child, take -1 in its place.

**Output Format**

    Elements are printed level wise, each level in new line (separated by space).

**Sample Input**

    5 6 10 2 3 -1 -1 -1 -1 -1 9 -1 -1

**Sample Output**

    5
    6 10
    2 3
    9

<details> <summary><strong>Code</strong></summary>

    // Following is the Binary Tree node structure
    /**************
    class BinaryTreeNode {
        public :
        T data;
        BinaryTreeNode<T> *left;
        BinaryTreeNode<T> *right;

        BinaryTreeNode(T data) {
            this -> data = data;
            left = NULL;
            right = NULL;
        }
    };

    ***************/

    void printLevelATNewLine(BinaryTreeNode<int> *root)
    {
        if (root == NULL)
            return;

        queue<BinaryTreeNode<int> *> q;
        q.push(root);
        q.push(NULL);

        // passes a level with the line seperator Base case
        // this line seperator will be encountered only if all of the previous nodes children have been take care of. Forward case

        BinaryTreeNode<int> *temp;
        while (!q.empty())
        {
            temp = q.front();
            q.pop();

            if (temp == NULL)
            {
                // a. If this is the last NULL
                if (q.empty())
                    return;

                // b. this is not the last NULL
                q.push(NULL); // the for the present generation
                cout << endl;
                continue; // because temp needs to be changed
            }

            cout << temp->data << " ";
            // take in children belonging to all
            if (temp->left != NULL)
                q.push(temp->left);
            if (temp->right != NULL)
                q.push(temp->right);
        }
    }

    /* Painful insights:

        We assume that we have the ability to print all the children on a level with a NULL as line end.

        If this is possible, we can do the following.
            We start to push the children of the present level one by one.
            Hence we successfully have pushed a generation of nodes.

            When we encounter the NULL, two cases are possible:
            a. The list is empty and everything has been printed, Break;
            b. We have more chilren remaining. As we have already pushed the generation of nodes
                push the NULL as the end value. print newline. continue , because we need the q.front() for adding the children

            If we don't have a NULL, just push the non-NULL children of the node.
            T.C = O(n), Space complexity = O(n)

        If this is not possible.
            Ha ha ha, is is possible.

    /*

</details>

---

</details>

<details> <summary><strong> 4. Remove Leaf nodes </strong></summary>

# 4. Remove Leaf nodes

    Remove all leaf nodes from a given Binary Tree. Leaf nodes are those nodes, which don't have any children.

    Note : Root will also be a leaf node if it doesn't have left and right child. You don't need to print the tree, just remove all leaf nodes and return the updated root.

**Input Format**

    Elements in level order form (separated by space)

    (If any node does not have left or right child, take -1 in its place)

**Output Format**

    Elements are printed level wise, each level in new line (separated by space).

**Sample Input**

    8 3 10 1 6 -1 14 -1 -1 4 7 13 -1 -1 -1 -1 -1 -1 -1

**Sample Output**

    8
    3 10
    6 14

<details> <summary><strong>Code</strong></summary>

    // Following is the Binary Tree node structure
    /**************
    class BinaryTreeNode {
        public :
        T data;
        BinaryTreeNode<T> *left;
        BinaryTreeNode<T> *right;

        BinaryTreeNode(T data) {
            this -> data = data;
            left = NULL;
            right = NULL;
        }
    };
    ***************/

    BinaryTreeNode<int> *removeLeafNodes(BinaryTreeNode<int> *root)
    {
        if (root == NULL)
            return NULL;

        if (root->left == NULL && root->right == NULL)
            return NULL;
        root->left = removeLeafNodes(root->left);
        root->right = removeLeafNodes(root->right);
        return root;
    }

</details>

---

</details>

<details> <summary><strong> 5. Level wise linkedlist </strong></summary>

# 5. Level wise linkedlist

    Given a binary tree, write code to create a separate linked list for each level. You need to return the array which contains head of each level linked list.

**Input Format**

    Elements in level order form (separated by space). If any node does not have left or right child, take -1 in its place.

**Output Format**

    Each level linked list is printed in new line (elements separated by space).

**Sample Input**

    5 6 10 2 3 -1 -1 -1 -1 -1 9 -1 -1

**Sample Output**

    5
    6 10
    2 3
    9

<details> <summary><strong>Code</strong></summary>

    vector<node<int> *> createLLForEachLevel(BinaryTreeNode<int> *root)
    {
        // if(root==NULL)
        //     return NULL;

        // followung the same level order
        // first make the queue fully, then make the LL's
        // same both ways.

        queue<BinaryTreeNode<int> *> q; // the queue required for level order
        q.push(root);                   //    for level order
        q.push(NULL);                   //    for level order

        vector<node<int> *> ret; // heads of the LL's
        ret.push_back(NULL);     // making a place for an empty LL, emptiness indicated by NULL

        node<int> *ltail = NULL; // keeping track of the current LL's tail. Can serve as NULL and head too. Used fr=or progressing the list

        BinaryTreeNode<int> *temp; // the variable for doing queue ops, so that calls are not made many times

        while (!q.empty())
        {
            temp = q.front();
            q.pop();

            if (temp == NULL) // not going to happen initially, as root!=NULL
            {
                ltail->next = NULL; // end the list
                if (q.empty())      // last NULL
                    return ret;

                ltail = NULL;
                ret.push_back(ltail); // make a place for the new list in ret
                // tail which points to nothing is now the head of the LL
                q.push(NULL);
                continue;
            }

            if (temp->left != NULL)
                q.push(temp->left);

            if (temp->right != NULL)
                q.push(temp->right);

            if (ret.back() == NULL) // we have valid node in queue but the LL is not started
            {
                ltail = new node<int>(temp->data); // making tail point to something
                ret.push_back(ltail);
            }
            else
            {
                ltail->next = new node<int>(temp->data);
                ltail = ltail->next;
            }
        }
    }

    /*
        Insights: Using the same principle of level, by a seperator.
        Problems encountered:
        0. Should i fill the entire queue and then make the LL's. No we won't be able to do this in a queue(as you'll never reach a q.front()==NULL). You can use a vector. But the space complexity is o(N), but for queue it is O(N/2). Which is huge.
        Using recursion yields the same thing. So queue is the most effiecient.
        If we use queue, we have to make the LL simultaneously. As nodes are being popped.
        1. How to make an LL. Soln: Using NULL in the return vector before the loop starts.
        2. For progressing the list, we need to have a tail pointer. Make a variable called ltail before the loop.
        3. A bug: ltail be made to point to NULL and pushed into the stack. pushing NULL and then setting ltail = NULL is wrong because ltail is nothing but a pointer. Hence ltail itself needs to be pushed when making the head. Basics.
    */

</details>

---

</details>

<details> <summary><strong> 6. ZigZag tree </strong></summary>

# 6. ZigZag tree

    Given a binary tree, print the zig zag order i.e print level 1 from left to right, level 2 from right to left and so on. This means odd levels should get printed from left to right and even level right to left.

**Input Format**

    Elements in level order form (separated by space)

    (If any node does not have left or right child, take -1 in its place)

**Output Format**

    Elements are printed level wise, each level in new line (separated by space).

**Sample Input**

    5 6 10 2 3 -1 -1 -1 -1 -1 9 -1 -1

**Sample Output**

    5
    10 6
    2 3
    9

<details> <summary><strong>Code</strong></summary>

    // Following is the Binary Tree node structure
    /**************
    class BinaryTreeNode {
        public :
        T data;
        BinaryTreeNode<T> *left;
        BinaryTreeNode<T> *right;

        BinaryTreeNode(T data) {
            this -> data = data;
            left = NULL;
            right = NULL;
        }
    };

    ***************/

    // used Linked list
    #include <list>
    void zigZagOrder(BinaryTreeNode<int> *root)
    {
        if (root == NULL)
            return;

        queue<BinaryTreeNode<int> *> q;
        q.push(root);
        q.push(NULL);
        // O(n) space complexity

        list<BinaryTreeNode<int> *> prit;

        BinaryTreeNode<int> *temp;

        bool flag = false;

        while (!q.empty())
        {
            temp = q.front();
            q.pop();

            if (temp == NULL)
            {

                while (!prit.empty())
                {
                    cout << prit.front()->data << " ";
                    prit.pop_front();
                }
                cout << "\n";
                if (q.empty())
                    return;
                q.push(NULL);
                flag = !flag;
                continue;
            }
            if (flag == false)
                prit.push_back(temp);
            else
                prit.push_front(temp);
            if (temp->left != NULL)
                q.push(temp->left);
            if (temp->right != NULL)
                q.push(temp->right);
        }
    }

    // Using two stacks and L->R and R->L child check
    void zigZagOrder(BinaryTreeNode<int> *root)
    {
        if (root == NULL)
            return;
        stack<BinaryTreeNode<int> *> sf;     // forward
        stack<BinaryTreeNode<int> *> sb;     // backwards
        stack<BinaryTreeNode<int> *> *p, *c; // parents, children

        stack<BinaryTreeNode<int> *> *switcher;
        sf.push(root);
        p = &sf;
        c = &sb;

        bool flag = false; // this makes us shift the array from left to right and right to left
        while (!p->empty())
        {
            if (flag == false)
            {
                while (!p->empty())
                {
                    // print the conent of the parent
                    cout << p->top()->data << " ";
                    if (p->top()->left != NULL)
                        c->push(p->top()->left);

                    if (p->top()->right != NULL)
                        c->push(p->top()->right);
                    p->pop();
                }
                // done with the parent
                cout << "\n";
                flag = true;
            }
            else
            {
                while (!p->empty())
                {
                    // print the conent of the parent
                    cout << p->top()->data << " ";
                    if (p->top()->right != NULL)
                        c->push(p->top()->right);
                    if (p->top()->left != NULL)
                        c->push(p->top()->left);
                    p->pop();
                }
                // done with the parent
                cout << "\n";
                flag = false;
            }

            // switch parent and child.
            switcher = p;
            p = c;
            c = switcher;
        }
    }

</details>

---

</details>

<details> <summary><strong> 7. Min and Max of Binary Tree </strong></summary>

# 7. Min and Max of Binary Tree

    Given a binary tree, find and return the min and max data value of given binary tree.
    Return the output as an object of PairAns class, which is already created.

**Input Format**

    Elements in level order form (separated by space)
    (If any node does not have left or right child, take -1 in its place)

**Output Format**

    Max and min (separated by space)

**Sample Input**

    8 3 10 1 6 -1 14 -1 -1 4 7 13 -1 -1 -1 -1 -1 -1 -1

**Sample Output**

    14 1

<details> <summary><strong>Code</strong></summary>

    // Following is the Binary Tree node structure
    /**************
    class BinaryTreeNode {
        public :
        T data;
        BinaryTreeNode<T> *left;
        BinaryTreeNode<T> *right;

        BinaryTreeNode(T data)
        {
            this -> data = data;
            left = NULL;
            right = NULL;
        }
    };

    // PairAns class -
    class PairAns
    {
        public :
            int min;
            int max;
    };

    ***************/
    #include <climits>
    PairAns minMax(BinaryTreeNode<int> *root)
    {
        if (root == NULL)
        {
            PairAns ret;
            ret.min = INT_MAX;
            ret.max = INT_MIN;
            return ret; // return by value
        }
        PairAns al = minMax(root->left);
        PairAns ar = minMax(root->right);
        al.min = min(al.min, min(ar.min, root->data));
        al.max = max(al.max, max(ar.max, root->data));
        return al;
    }

</details>

---

</details>
