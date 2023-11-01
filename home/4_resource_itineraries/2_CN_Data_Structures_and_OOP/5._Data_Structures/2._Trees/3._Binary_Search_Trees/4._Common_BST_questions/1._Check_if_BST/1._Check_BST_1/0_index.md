# 1. Check BST 1
Created Friday 07 February 2020


* From the definition we know that if all the nodes on the left are smaller than the root, and all the nodes on the right are greater than the root.

i.e leftMax < root->data && rightMin > root->data

* Is this enough? Yes. Think recursively with the base case being a leaf node. We return true, as a leaf is a BST.
* For a NUll return as as INT_MIN and min as INT_MAX. return true here too. as NULL can also be taken as BST. This is to be used when we have a NULL)



* We need to return min and max, if we make two seperate functions which find the maximum and the minimum. This takes O(n) time.

```c++
int maxBT(BT*root)
{
	if(root==NULL)
		return INT_MIN;
	return max((root->data), maxBT(root->left), maxBT(root->right));
}

int minBT(BT*root)
{
	if(root==NULL)
		return INT_MAX;
	return min((root->data), minBT(root->left), minBT(root->right));
}

bool isBST(Bt* root)
{
	if(root==NULL || root->left && root-right==NULL)
		return true; // leaf and no node
	if(root->data > min(root->left) && root->data < max(root->right) && isBST(root->left) && isBST(root->right))
		return true; // Joining two Binary Search trees by a node is not neccessarily a Binary Search tree. Because we need to check the subtree property.
		// remember by checking for min and max only, we are still oblivious of the fact whether the left and right are Binary Search Trees.
	return false;
}
```

f(n) = 2n+T(n/2) =  nh =  nodes * height
worst case - O(n^2^) skewed tree, O(nlog~2~n)
Not a good solution as we have to do work again and again.





