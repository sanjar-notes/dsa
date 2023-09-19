# 1. Kruskal's Algo Complexity

Created Saturday 25 April 2020

#### Algorithm

Idea:

1. Sort the edges according to weights. **Adjacency list will be better here(as it'll store the weights).**
2. Take the edges: source-destination-weight as input.
3. For storing the MST, make a list of n-1 <edges>.

**No visited bag required!**

Pseudocode:

1. Sort the edges according to weights. **Adjacency list will be better here(as it'll store the weights).**
2. Take the edges: source-destination-weight as input.
3. For storing the MST, make a list of n-1 <edges>.

#### Analysis - Time and Space

- Time Complexity is O(VE) using union find.

![](/assets/1._Kruskal's_Algo_Complexity-image-1.png)

- We can make it O(E logV) by using Union by rank and Path Compression, i.e we try to make a balanced tree.

![](/assets/1._Kruskal's_Algo_Complexity-image-2.png)s
