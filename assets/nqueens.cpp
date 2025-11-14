#include <bits/stdc++.h>
using namespace std;

bool check(int **mat, int n, int a, int b)
{
    int r = a, c = b;
    int end = max(r, c);
    for (int i = 0; i <= end; i++) // check previous rows only, i = column
    {
        if (mat[r][i] || mat[i][c])
            return true; // decluttered - checks both rows and columns
    }

    //make them the least
    int minv = min(r, c);
    r -= minv;
    c -= minv;

    // Forward Slash Diagonal
    while (r <= end && c <= end)
    {
        if (mat[r++][c++])
            return true;
    }

    //restore the point
    r = a;
    c = b;

    // set column to max
    while (r >= 0 && c < n)
    {
        if (mat[r][c])
            return true;
        r--, c++;
    }
    return false;
}

void helper(int **mat, int n, int r) // current row
{
    if (r == n)
    {
        for (int i = 0; i < 2 * n - 1; i++)
            cout << "-";
        cout << endl;
        // print the matrix, LRTD
        for (int i = 0; i < n; i++)
        {
            for (int j = 0; j < n; j++)
                cout << mat[i][j] << " ";
            cout << endl;
        }
        // just a line seperator
        return;
    }

    //place the queen at all possible columns in the row
    for (int i = 0; i < n; i++) // i is the column
    {
        if (check(mat, n, r, i) == false)
        {
            mat[r][i] = 1;
            helper(mat, n, r + 1); // set and proceed - does not matter if the emanating configs successful or not
            mat[r][i] = 0;         // unset when backtracking
        }
    }
    return; // Return - done wtth all the emanating configs
}

void placeNQueens(int n)
{
    int **mat = new int *[10];
    for (int i = 0; i < n; i++)
    {
        mat[i] = new int[10];
        for (int j = 0; j < n; j++)
            mat[i][j] = 0;
    }
    // initializations done
    helper(mat, n, 0);

    delete[] mat;
}

int main()
{

    int n;
    cin >> n;
    placeNQueens(n);
}
