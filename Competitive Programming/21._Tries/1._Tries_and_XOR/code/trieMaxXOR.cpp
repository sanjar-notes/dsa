#include <bits/stdc++.h>
using namespace std;
class trieNode
{
public:
    trieNode *left, *right;

public:
    trieNode()
    {
        left = right = NULL;
    }
};

void insert(int n, trieNode *head)
{
    trieNode *curr = head; // will point to the deepest node
    for (int i = 31; i >= 0; i--)
    {
        int b = (n >> i) & 1; // the Leftmost bit
        if (b == 0)
        {
            if (curr->left == NULL)
                curr->left = new trieNode();
            curr = curr->left;
        }
        else
        {
            if (curr->right == NULL)
                curr->right = new trieNode();
            curr = curr->right;
        }
    }
}

int findMaxXorPair(trieNode *head, int *arr, int n)
{
    int max_xor = INT_MIN;
    int ip;
    for (int i = 0; i < n; i++)
    {
        int curr_max = 0;
        int value = arr[i];
        trieNode *curr = head;
        for (int j = 31; j >= 0; j--)
        {
            int b = (value >> j) & 1; // the Leftmost bit
            if (b == 0)
            {
                if (curr->right)
                {
                    curr_max += pow(2, j);
                    curr = curr->right;
                }
                else
                    curr = curr->left; // nothing added
            }
            else
            {
                if (curr->left)
                {
                    curr_max += pow(2, j);
                    curr = curr->left;
                }
                else
                    curr = curr->right;
            }
        }
        if (curr_max > max_xor)
            max_xor = curr_max;
    }
    return max_xor;
}

int main()
{
    int arr[] = {8, 1, 2, 15, 10, 5}; // answer is 5 and 10
    int N = sizeof(arr) / sizeof(arr[0]);
    trieNode *head = new trieNode;
    for (int i = 0; i < N; i++)
        insert(arr[i], head);
    cout << findMaxXorPair(head, arr, N) << endl;
}
