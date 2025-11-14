#include <iostream>
using namespace std;

void helper(int maze[][20], int n, int **pathm, int r, int c)
{
    // mark current as visited
    pathm[r][c] = 1;

    if (r == n - 1 && c == n - 1)
    {
        for (int i = 0; i < 2 * n - 1; i++)
            cout << "-";
        cout << endl;
        // print the matrix, LRTD
        for (int i = 0; i < n; i++)
        {
            for (int j = 0; j < n; j++)
                cout << pathm[i][j] << " ";
            cout << endl;
        }
        // just a line seperator
        // don't return, unset the cell first
    }
    else
    {
        // check
        // 1. We are not going back
        // 2. The point is not a hole
        // 3. We are not crossing the boundary

        if (c > 0 && pathm[r][c - 1] == 0 && maze[r][c - 1] == 1) // Left
            helper(maze, n, pathm, r, c - 1);
        if (c < n - 1 && pathm[r][c + 1] == 0 && maze[r][c + 1] == 1) // Right
            helper(maze, n, pathm, r, c + 1);
        if (r > 0 && pathm[r - 1][c] == 0 && maze[r - 1][c] == 1) // UP
            helper(maze, n, pathm, r - 1, c);
        if (r < n - 1 && pathm[r + 1][c] == 0 && maze[r + 1][c] == 1) // DOWN
            helper(maze, n, pathm, r + 1, c);
    }
    pathm[r][c] = 0; // done, backtrack
}

void ratInAMaze(int maze[][20], int n)
{
    //as we need to include the path matrix, we need a helper function
    int **pathm = new int *[n];
    for (int i = 0; i < n; i++)
    {
        pathm[i] = new int[n];
        for (int j = 0; j < n; j++)
            pathm[i][j] = 0;
    }
    //initialization complete
    helper(maze, n, pathm, 0, 0);
}

int main()
{

    int n;
    cin >> n;
    int maze[20][20];
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            cin >> maze[i][j];
        }
    }
    ratInAMaze(maze, n);
}
