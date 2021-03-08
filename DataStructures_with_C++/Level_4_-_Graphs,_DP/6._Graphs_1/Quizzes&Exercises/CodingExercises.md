<details> <summary><strong> 1. Code : Min Cost Path </strong></summary>

# 1. Code : Min Cost Path

    Given an integer matrix of size m*n, you need to find out the value of minimum cost to reach from the cell (0, 0) to (m-1, n-1).

    From a cell (i, j), you can move ONLY in three directions : (i+1, j), (i, j+1) and (i+1, j+1).

    Cost of a path is defined as the sum of values of each cell through which path passes.

**Input format**

    Line 1 : Two integers, m and n
    Next m lines : n integers of each row (separated by space)

**Output format**

    Minimum cost

**Constraints**:

    1 <= n <= 500

**Sample Input 1**

    3 4
    3 4 1 2
    2 1 8 9
    4 7 8 1

**Sample Output 1**

    13

<details> <summary><strong>Code</strong></summary>

    #include <iostream>
    #include <queue>
    #include <unordered_set>
    using namespace std;

    void bfs(bool **, int, int, unordered_set<int> *);

    int main()
    {
        int V, E;
        cin >> V >> E;

        if (V == 0 || E == 0)
            return 0;

        // making an adjacency matrix of V*V

        bool **edges = new bool *[V];
        for (int i = 0; i < V; i++)
        {
            edges[i] = new bool[V];
            for (int j = 0; j < V; j++)
                edges[i][j] = false;
        }

        int a, b;
        for (int i = 0; i < E; i++)
        {
            cin >> a >> b;
            edges[a][b] = edges[b][a] = true; // marked as visited
        }

        // starting from the node

        unordered_set<int> *visited = new unordered_set<int>; // this is universal
        visited->clear();
        // for disconnected graph

        // we call bfs for each unvisited edge.
        // the completed ones will be ignored due to universal visited

        // looping to handle disconnectedness
        for (int i = 0; i < V && visited->size() < V; i++)
        {
            if (visited->count(i) == 0)
                bfs(edges, V, i, visited);

            // we used a for loop because this ensures all vertices are passed through,
            // even disconnected ones.
        }

        // deallocating the space
        for (int i = 0; i < V; i++)
            delete[] edges[i];
        delete[] edges;
        delete visited;

        return 0;
    }

    void bfs(bool **edges, int V, int sv, unordered_set<int> *visited)
    {
        // make the queue and the visited list
        queue<int> tbe; // TO BE EXPLORED

        // sv has special treatment, as it is the our unvisited neigbour in the graph :)

        visited->insert(sv); // mark as visited-> We do this outside
        tbe.push(sv);        // the start, if tbv is zero we stop.
        cout << sv << " ";   // we print this ourselves, as it is the users unvisited neigbour :)

        int curr = 0;           // this is done so that OS does not need frequent memory alloc lookups
        while (tbe.size() != 0) // tbe.size() is 1 initially
        {
            curr = tbe.front();
            tbe.pop();

            // check the possiblilty
            for (int i = 0; i < V && visited->size() < V; i++)
            {
                // if it is a neighbour and has not been visited, disconnected will be false always
                if (edges[curr][i] == true && visited->count(i) == 0)
                {
                    // print the neighbour
                    cout << i << " ";

                    // put in to be explored and visited->
                    tbe.push(i);
                    visited->insert(i);
                }
            }
            // printed all the neighbours
        }
        // All vertices printed
    }

</details>

---

</details>

<details> <summary><strong> 2. Code : Min Steps to 1 using DP </strong></summary>

# 2. Code : Min Steps to 1 using DP

    Given a positive integer n, find the minimum number of steps s, that takes n to 1. You can perform any one of the following 3 steps.

        1. Subtract 1 from it. (n= n - 1) ,
        2. If its divisible by 2, divide by 2.( if n%2==0, then n= n/2 ) ,
        3. If its divisible by 3, divide by 3. (if n%3 == 0, then n = n / 3 ).

    The time complexity of your code should be O(n).

**Input format**

    Line 1 : A single integer i.e. n

**Output format**

    Line 1 : Single integer i.e number of steps

**Constraints**:

    1 <= n <= 500

**Sample Input 1**

    4

**Sample Output 1**

    2

**Sample Output 1 Explanation**:

    For n = 4
    Step 1 : n = 4/2 = 2
    Step 2 : n = 2/2 = 1

**Sample Input 2**

    7

**Sample Output 2**

    3

**Sample Output 2 Explanation**:

    For n = 7
    Step 1 : n = 7 ­ - 1 = 6
    Step 2 : n = 6 / 3 = 2
    Step 3 : n = 2 / 2 = 1

<details> <summary><strong>Code</strong></summary>

    #include <iostream>
    #include <queue>
    #include <unordered_set>
    using namespace std;

    bool bfs(bool **edges, int V, int sv, int key, unordered_set<int> *);

    int main()
    {
        int V, E;
        cin >> V >> E;

        if (V == 0 || E == 0)
            cout << "false";

        // making an adjacency matrix of V*V

        bool **edges = new bool *[V];
        for (int i = 0; i < V; i++)
        {
            edges[i] = new bool[V];
            for (int j = 0; j < V; j++)
                edges[i][j] = false;
        }

        int a, b;
        for (int i = 0; i < E; i++)
        {
            cin >> a >> b;
            edges[a][b] = edges[b][a] = true; // marked as visited
        }

        int sv, key;
        cin >> sv >> key;

        // prank test
        if (sv >= V || key >= V)
        {
            cout << "false";
            return 0;
        }

        if(sv==key)
        {
            cout <<"true;
            return 0;
        }

        unordered_set<int> *visited = new unordered_set<int>; // this is universal

        // no need for connectedness check
        if(bfs(edges, V, sv, key, visited))
        cout << "true";
        else
        cout << "false";

        // deallocating the space
        for (int i = 0; i < V; i++)
            delete[] edges[i];
        delete[] edges;
        delete visited;

        return 0;
    }

    bool bfs(bool **edges, int V, int sv, int key, unordered_set<int> *visited)
    {
        // make the queue and the visited list
        queue<int> tbe; // to be explored

        // sv has special treatment, as it is the our unvisited neigbour in the graph :)

        visited->insert(sv); // mark as visited-> We do this outside
        tbe.push(sv);        // the start, if tbv is zero we stop.

        int curr = 0;           // this is done so that OS does not need frequent memory alloc lookups
        while (tbe.size() != 0) // tbe.size() is 1 initially
        {
            int curr = tbe.front();
            tbe.pop();

            // check the possiblilty
            for (int i = 0; i < V; i++)
            {
                // if it is a neighbour and has not been visited, disconnected will be false always
                if (edges[curr][i] == true && visited->count(i) == 0)
                {
                    if (i == key)
                        return true;
                    // print the neighbour

                    // put in to be explored and visited->
                    tbe.push(i);
                    visited->insert(i);
                }
            }
            // printed all the neighbours
        }
        return false;
        // All vertices printed
    }

</details>

---

</details>

<details> <summary><strong> 3. Code : Edit Distance </strong></summary>

# 3. Code : Edit Distance

    Given two strings s and t of lengths m and n respectively, find the Edit Distance between the strings. Edit Distance of two strings is minimum number of steps required to make one string equal to other.

    In order to do so you can perform following three operations only :

    1. Delete a character
    2. Replace a character with another one
    3. Insert a character

    Note - Strings don't contain spaces

**Input format**

    Line 1 : String s
    Line 2 : String t

**Output format**

    Line 1 : Edit Distance value

**Constraints**:

    1<= m,n <= 10

**Sample Input**

    abc
    dc

**Sample Output**

    2

<details> <summary><strong>Code</strong></summary>

    // Bruteforce method

    #include <iostream>
    #include <vector>
    using namespace std;

    int editDistance(string s1, string s2)
    {
        if(s1.size()==0 || s2.size()==0)
            return s1.size() + s2.size(); // additions

        if(s1.size() < s2.size())
        {
            string s3 = s1;
            s1 = s2;
            s2 = s3;
        }

        if(s1[0]==s2[0])// both are the same
            return editDistance(s1.substr(1), s2.substr(1));

        // 3 cases are possible

        // we prepend the smaller one and make both the [0] terms equal
        int x =  1 + editDistance(s1.substr(1), s2);

        // int remove the first one from the larger and assume that the next one can handle it
        int y = 1 + editDistance(s1, s2.substr(1));

        // replace the first character by the first character in either of the strings
        int z = 1 + editDistance(s1.substr(1), s2.substr(1));

        return min(x, min(y,z));
    }

</details>

---

</details>

<details> <summary><strong> 4. Code : Edit Distance (Memoization and DP) </strong></summary>

# 4. Code : Edit Distance (Memoization and DP)

    Given two strings s and t of lengths m and n respectively, find the Edit Distance between the strings. Edit Distance of two strings is minimum number of steps required to make one string equal to other.

    In order to do so you can perform following three operations only :

    1. Delete a character
    2. Replace a character with another one
    3. Insert a character

    Note - Strings don't contain spaces

**Input format**

    Line 1 : String s
    Line 2 : String t

**Output format**

    Line 1 : Edit Distance value

**Constraints**:

    1<= m,n <= 20

**Sample Input**

    abc
    dc

**Sample Output**

    2

<details> <summary><strong>Code</strong></summary>

    // Memoization

    #include<iostream>
    using namespace std;

    int editDistance_memo(string s1, string s2, int** memo)
    {
        int i = s1.size();
        int j = s2.size();

        //     i, j dependends on (i-1, j), (i-1, j-1) and (i, j-1)
        if(memo[i][j]==-1)
        {
            // the first letters are the same,  no operation required
            if(s1[0]==s2[0])    // i.e depends on i-1, j-1 alone
                memo[i][j] = editDistance_memo(s1.substr(1), s2.substr(1), memo);
            else
            {
                // create a first one - x.1, y
                int create_val = 1 + editDistance_memo(s1.substr(1), s2, memo);

                // delete the first element - x, y.1
                int delete_val = 1 + editDistance_memo(s1, s2.substr(1), memo);

                // int update - x.1 y.1
                int update_val = 1 + editDistance_memo(s1.substr(1), s2.substr(1), memo);

                memo[i][j] = min(create_val, min(delete_val, update_val));
            }
        }
        return memo[i][j];
    }

    // A big doubt, in reality the subtrings could be different. Yes but this problem was resolved back in the BF. And we just optimized the problem from their on.
    // In the solution we see that x and y are the same for each level,
    // as they originate using the same function, by a single function substr, hence the substrings will also be the same.

    int editDistance(string s1, string s2)
    {

    //     in the bf code, we have x.substr() and y.substr() so the total number of values are x.size()*y.size() i.e a 2d array
    //     i, j is for length and not substr()

        if(s1.size()<s2.size())
        {
            string s3 = s1;
            s1 = s2;
            s2 = s3;
        }

        int** memo = new int*[s1.size()+1];
        for(int i=0; i<s1.size()+1; i++)
        {
            memo[i] = new int[s2.size()+1];

            for(int j=0; j<s2.size()+1; j++)
                memo[i][j] = -1;     // unknown answers
        }

        // known answers
        for(int i=0; i<s1.size()+1; i++)
            memo[i][0] = i;

        for(int j=0; j<s2.size()+1; j++)
            memo[0][j] = j;

        return editDistance_memo(s1, s2, memo);    // we need the the bottom right point
    }

    // DP solution

    #include <iostream>
    using namespace std;

    int ed_dp(string s1, string s2)
    {

        if (s1.size() < s2.size())
        {
            string s3 = s1;
            s1 = s2;
            s2 = s3;
        }

        int **memo = new int *[s1.size() + 1];
        for (int i = 0; i < s1.size() + 1; i++)
            memo[i] = new int[s2.size() + 1];

        // known answers
        for (int i = 0; i < s1.size() + 1; i++)
            memo[i][0] = i;

        for (int j = 0; j < s2.size() + 1; j++)
            memo[0][j] = j;

        // as i, j depend on (i-1, j) and (i, j-1) and (i-1,j-1) - i.e previous answers

        //  we can just traverse and place the values. going R->L and T->D
        //  the 1st column and the first row are all answers

        int m = s1.size();
        int n = s2.size();

        for (int i = 1; i < m + 1; i++)
        {
            for (int j = 1; j < n + 1; j++)
            {
                //  we need to check if the string's 1st character is same
                if (s1[m - i] == s2[n - j])
                    memo[i][j] = memo[i - 1][j - 1]; // x.1 and y.1
                else                                 // here the ans is from the top-left, top or the left. whichever is the minimum
                    memo[i][j] = 1 + min(memo[i - 1][j - 1], min(memo[i - 1][j], memo[i][j - 1]));
            }
        }
        return memo[m][n];
    }

    int editDistance(string s1, string s2)
    {
        return ed_dp(s1, s2); // we need the the bottom right point
    }

</details>

---

</details>

<details> <summary><strong> 5. Code : Knapsack </strong></summary>

# 5. Code : Knapsack

    A thief robbing a store and can carry a maximal weight of W into his knapsack. There are N items and ith item weigh wi and is value vi. What is the maximum value V, that thief can take ?

**Input format**

    Line 1 : N i.e. number of items
    Line 2 : N Integers i.e. weights of items separated by space
    Line 3 : N Integers i.e. values of items separated by space
    Line 4 : Integer W i.e. maximum weight thief can carry

**Output format**

    Line 1 : Maximum value V

**Constraints**:

    1 <= N <= 20
    1<= wi <= 100
    1 <= vi <= 100

**Sample Input**

    4
    1 2 4 5
    5 4 8 6
    5

**Sample Output**

    13

<details> <summary><strong>Code</strong></summary>

    #include <iostream>
    using namespace std;

    // BruteForce solution - non elegant

    int knapsack(int* weights, int* values, int n, int maxWeight)
    {
        //  f(n) is the number of items we choose
        /*    f(n)
        {
            if(n==0)
                return 0;
            max = -1;
            generate all subsequences with sum less than capacity and find max amongst them
            if(max==-1)
                i.e every subsequence is greater than the capacity
                return f(n-1)
        }
        */

        if(n==0)
            return 0;

        int sum = 0, value = 0;
        for(int i=0;i<n; i++)
            sum+=weights[i], value+=values[i];
        if(sum<=maxWeight)
            return value;

        int* tempw = new int[n-1];
        int* tempv = new int[n-1];

        int max = -1;

        for(int i=0; i<n; i++)
        {
            for(int j=0; j<i; j++)
            {
                tempw[j] = weights[j];
                tempv[j] = values[j];
            }

            // skip the ith term

            for(int j=i+1; j<n; j++)
            {
                tempw[j-1] = weights[j];
                tempv[j-1] = values[j];
            }

            int ans = knapsack(tempw, tempv, n-1, maxWeight);    //this is surely less than max weight

            if(ans>max)    //takes care of the zero case too
                max = ans;
        }
        return max;
    }

    // Elegant Bruteforce - Select(if possible) or leave(anytime because what to take is the question)

    #include <iostream>
    using namespace std;

    int knapsack(int* weights, int* values, int n, int maxWeight)
    {
        // as this is a choosing problem. A thing is chosen or it is not.
        // go one by one say true or false

        if(n==0 || maxWeight==0)
            return 0;

        int chosen = -1;    // if not selectable max will ignore this

        //choose item[0], which is possible only if it can be accomodated
        if(weights[0]<=maxWeight)
            chosen = values[0] + knapsack(weights+1, values+1, n-1, maxWeight-weights[0]);

        //reject it
        // we can do this anytime - rejection for non fitting or for selection
        int rejected = knapsack(weights+1, values+1, n-1, maxWeight);

        // both values are valid values
        return max(chosen, rejected);
    }

</details>

---

</details>

<details> <summary><strong> Code: Knapsack (Memoization and DP) </strong></summary>

# 6. Code: Knapsack (Memoization and DP)

    A thief robbing a store and can carry a maximal weight of W into his knapsack. There are N items and ith item weigh wi and is value vi. What is the maximum value V, that thief can take ?

**Input format**

    Line 1 : N i.e. number of items
    Line 2 : N Integers i.e. weights of items separated by space
    Line 3 : N Integers i.e. values of items separated by space
    Line 4 : Integer W i.e. maximum weight thief can carry

**Output format**

    Line 1 : Maximum value V

**Constraints**:

    1 <= N <= 10^4
    1<= wi <= 100
    1 <= vi <= 100

**Sample Input**

    4
    1 2 4 5
    5 4 8 6
    5

**Sample Output**

    13

<details> <summary><strong>Code</strong></summary>

    #include <iostream>
    using namespace std;
    int knapsack(int* weights, int* values, int n, int maxWeight)
    {
        /* Don't write main().
        *  Don't read input, it is passed as function argument.
        *  Return output and don't print it.
        *  Taking input and printing output is handled automatically.
        */

        //write your code here
    }

</details>

---

</details>
