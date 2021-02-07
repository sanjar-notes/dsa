<details> <summary><strong> 1. Print Level Wise </strong></summary>

# 1. Print Level Wise

    Given a generic tree, print the input tree in level wise order. ####For printing a node with data N, you need to follow the exact format -
        N:x1,x2,x3,...,xn
    where, N is data of any node present in the binary tree. x1, x2, x3, ...., xn are the children of node N
    There is no space in between.
    You need to print all nodes in the level order form in different lines.

**Input format**

    Elements in level order form separated by space (as per done in class).
    Order is - Root_data, n (No_Of_Child_Of_Root), n children, and so on for every element

**Output format**

    Level wise print

**Sample Input**

    10 3 20 30 40 2 40 50 0 0 0 0

**Sample Output**

    10:20,30,40
    20:40,50
    30:
    40:
    40:
    50:

<details> <summary><strong>Code</strong></summary>

    // Following is the given TreeNode structure.
    /**************

    template <typename T>
    class TreeNode {
    public:
        T data;
        vector<TreeNode<T>*> children;

        TreeNode(T data) {
            this->data = data;
        }

        ~TreeNode() {
            for (int i = 0; i < children.size(); i++) {
                delete children[i];
            }
        }

    };
    ***************/

    #include <queue>
    void printLevelWise(TreeNode<int> *root)
    {
        //prank check
        if (root == NULL)
            return;

        queue<TreeNode<int> *> nodesPending;

        nodesPending.push(root); // obviously pending, we have not printed it's children.

        // Another reason is that if we don't do this, then queue will not be systematic.

        // for optimization
        int data;                   // for relevance
        int n;                      // number of children
        TreeNode<int> *node = NULL; // the parent node

        // start printing the children
        while (nodesPending.size() != 0)
        {
            node = nodesPending.front(); // current root's data
            n = node->children.size();
            data = node->data;

            cout << data << ":";
            if (n != 0)
            {
                cout << node->children.at(0)->data;
                nodesPending.push(node->children.at(0));
                for (int i = 1; i < n; i++)
                {
                    cout << "," << node->children.at(i)->data;
                    nodesPending.push(node->children.at(i));
                }
            }
            // else don't print anything
            cout << endl;
            nodesPending.pop();
        }
    }

</details>

---

</details>

<details> <summary><strong> 2. Find sum of nodes </strong></summary>

# 2. Find sum of nodes

    Given a generic tree, count and return the sum of all nodes present in the given tree.

**Input Format**

    Elements in level order form separated by space (as per done in class).
    Order is - Root_data, n (No_Of_Child_Of_Root), n children, and so on for every element

**Output Format**

    Sum of all nodes

**Sample Input**

    10 3 20 30 40 2 40 50 0 0 0 0

**Sample Output**

    190

<details> <summary><strong>Code</strong></summary>

    int sumOfNodes(TreeNode<int> *root)
    {
        if (root == NULL)
            return 0; // prank

        // for optimization
        int sum = root->data;
        int n_children = root->children.size();

        // sum of all children , root has already been added
        for (int i = 0; i < n_children; i++)
            sum += sumOfNodes(root->children.at(i));

        return sum;
    }

</details>

---

</details>

<details> <summary><strong> 3. Max data node </strong></summary>

# 3. Maximum node

    Given a generic tree, find and return the node with maximum data. You need to return the complete node which is having maximum data.

    Return null if tree is empty.

**Input Format**

    Elements in level order form separated by space (as per done in class).
    Order is - Root_data, n (No_Of_Child_Of_Root), n children, and so on for every element

**Output Format**

    Updated LL elements (separated by space)

**Sample Input**

    10 3 20 30 40 2 40 50 0 0 0 0

**Sample Output**

    50

<details> <summary><strong>Code</strong></summary>

    // Following is the given Tree node structure.
    /**************
     template <typename T>
    class TreeNode {
        public:
            T data;
            vector<TreeNode<T>*> children;

            TreeNode(T data) {
                this->data = data;
            }

            ~TreeNode() {
                for (int i = 0; i < children.size(); i++) {
                    delete children[i];
                }
            }
    };
    ***************/

    TreeNode<int> *maxDataNode(TreeNode<int> *root)
    {
        if (root == NULL)
            return NULL;

        //base case is redundant
        // if(root->children.size()==0)
        //     return root;

        // max(root) = max(root, all children)

        // for optimization
        int n_children = root->children.size();
        TreeNode<int> *curr = root, *prev = root; // we use two variables and don't reuse root coz root is required for accessing all the subtrees

        for (int i = 0; i < n_children; i++)
        {
            curr = maxDataNode(root->children.at(i));
            if (curr->data > prev->data)
                prev = curr;
        }
        // prev has the most max value at each iteration
        return prev;
    }

</details>

---

</details>

<details><summary><strong> 4. Find height </strong></summary>

# 4. Find height

    Given a generic tree, find and return the height of given tree.

**Input Format**

    Elements in level order form separated by space (as per done in class). Order is -

    Root_data, n (No_Of_Child_Of_Root), n children, and so on for every element

**Output Format**

    Height

**Sample Input**

    10 3 20 30 40 2 40 50 0 0 0 0

**Sample Output**

    3

<details> <summary><strong>Code</strong></summary>

    / Following is the given Tree node structure.
    /**************
     template <typename T>
    class TreeNode {
        public:
            T data;
            vector<TreeNode<T>*> children;

            TreeNode(T data) {
                this->data = data;
            }

            ~TreeNode() {
                for (int i = 0; i < children.size(); i++) {
                    delete children[i];
                }
            }
    };
    ***************/

    int height(TreeNode<int> *root)
    {
        if (root == NULL)
            return -1;

        //base case is redundant
        // if(root->children.size()==0)
        //     return 0; // single node, on the ground

        // height  = 1 + max(height of all subtrees)

        int n_children = root->children.size();
        int prev = 0, curr = 0;

        for (int i = 0; i < n_children; i++)
        {
            curr = height(root->children.at(i));
            if (curr > prev)
                prev = curr;
        }
        return prev + 1;
    }

</details>

---

</details>

<details> <summary><strong> 5. Count leaf nodes </strong></summary>

# 5. Count leaf nodes

    Given a generic tree, count and return the number of leaf nodes present in the given tree.

**Input Format**

    Elements in level order form separated by space (as per done in class).
    Order is - Root_data, n (No_Of_Child_Of_Root), n children, and so on for every element

**Output Format**

    Count of leaf nodes

**Sample Input**

    10 3 20 30 40 2 40 50 0 0 0 0

**Sample Output**

    4

<details> <summary><strong>Code</strong></summary>

    /// Following is the given Tree node structure.
    /**************
     template <typename T>
    class TreeNode {
        public:
            T data;
            vector<TreeNode<T>*> children;

            TreeNode(T data) {
                this->data = data;
            }

            ~TreeNode() {
                for (int i = 0; i < children.size(); i++) {
                    delete children[i];
                }
            }
    };
    ***************/

    int numLeafNodes(TreeNode<int>* root)
    {
        // leaf nodes = sum of leaf nodes of the subtrees
        // base case, if no children return 1;

        // edge case: NULL prank
        if(root==NULL)
            return 0;

        // base case has to be here as it must stop the recursion when we do this
        // does matter here. As for loop does the same



        int leaves = 0;
        for(int i=0; i<root->children.size(); i++)
            leaves+=numLeafNodes(root->children.at(i));
        if(root->children.size()==0)
            return 1;
        return leaves;
    }

</details>

---

</details>
<details> <summary><strong> 6. PostOrder Traversal </strong></summary>

# 6. PostOrder Traversal

    Given a generic tree, print the post-order traversal of given tree.

    Post-order traversal is : Children and then Root

**Input Format**

    Elements in level order form separated by space (as per done in class).
    Order is - Root_data, n (No_Of_Child_Of_Root), n children, and so on for every element

**Output Format**

    Post-order traversal, elements separated by space

**Sample Input**

    10 3 20 30 40 2 400 50 0 0 0 0

**Sample Output**

    400 50 20 30 40 10

<details> <summary><strong>Code</strong></summary>

    // Following is the given Tree node structure.
    /**************
     template <typename T>
    class TreeNode {
        public:
            T data;
            vector<TreeNode<T>*> children;

            TreeNode(T data) {
                this->data = data;
            }

            ~TreeNode() {
                for (int i = 0; i < children.size(); i++) {
                    delete children[i];
                }
            }
    };
    ***************/

    void postOrder(TreeNode<int> *root)
    {
        if (root == NULL)
            return;

        // print all the subtrees of the children
        for (int i = 0; i < root->children.size(); i++)
            postOrder(root->children.at(i));

        // print the node
        cout << root->data << " ";
    }

</details>

---

</details>

<details> <summary><strong> 7. Reverse LL (Iterative) </strong></summary>

# 7. Reverse LL (Iterative)

    Given a linked list, reverse it iteratively.

    You don't need to print the elements, just reverse the LL duplicates and return the head of updated LL.

**Input Format**

    Linked list elements (separated by space and terminated by -1)

**Output Format**

    Updated LL elements (separated by space)

**Sample Input**

    1 2 3 4 5 -1

**Sample Output**

    5 4 3 2 1

<details> <summary><strong>Code</strong></summary>

    node *rev_linkedlist_itr(node *head)
    {
        if (head == NULL || head->next == NULL)
            return head;
        // uni and empty taken care of

        node *r = NULL, *q = NULL, *p = head;
        while (p != NULL)
        {
            q = p;
            p = p->next;
            q->next = r;
            r = q;
        }

        // q, r is the head at last. P is the untouched node
        return r;
    }

</details>

---

</details>
