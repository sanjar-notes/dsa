# 4. Find Path
Created Sunday 09 February 2020

We can do this using a vector in heap, and we will return the pointer of it. If we don't find it. We return the NULL when we don't find it. Otherwise, we will return the vector and push_back(all the value) the **order of output does not matter.**

Simple thing.
Search the root, return the value;
```c++
vector ret = f(root->left);
if(ret!=NULL)
{
	ret.push_back(root->data);
	return data;
}
ret = f(root->right);
if(ret!=NULL)
	ret.push_back(root->data);
return ret;
```


We are always doing push_back(), but no problem the user can traverse the array in the backwards direction.


