#include <iostream>
#include <vector>
using namespace std;

#define N 9

int steps = 0;
// we avoid mistakes
vector<int> getValues(int maze[][N], int r, int c) // returns a set of possible values
{
    // cout << steps++;
    bool arr[N];
    for (int i = 0; i < N; i++)
        arr[i] = false;
    // check the unit
    // go to the top left corner of the 3 x 3 square
    // How? Observe for some examples
    int sr = 3 * (r / 3), sc = 3 * (c / 3);

    // keep the unit check first
    for (int i = 0; i < 3; i++)
    {
        for (int j = 0; j < 3; j++)
        {
            if (maze[sr + i][sc + j] != 0 && !arr[maze[sr + i][sc + j] - 1]) //if value in the 3x3
                arr[maze[sr + i][sc + j] - 1] = true;
        }
    }

    //check the rows and columns
    for (int i = 0; i < N; i++)
    {
        if (maze[r][i] != 0 && !arr[maze[r][i] - 1])
            arr[maze[r][i] - 1] = true;
        if (maze[i][c] != 0 && !arr[maze[i][c] - 1])
            arr[maze[i][c] - 1] = true;
    }

    vector<int> ret; //populate the possible values
    for (int i = 0; i < N; i++)
    {
        if (!arr[i]) // number not present - add to possible values vector
            ret.push_back(i + 1);
    }
    return ret; // returns possible values for the place
}

bool solveSudoku(int maze[][N], vector<pair<int, int>> &missing, int position) // not void - we have only one solution, we shoul stop after doing it
{
    if (position >= missing.size())
    {
        // nothing to do - completed or nothing missing
        for (int i = 0; i < N; i++)
        {
            for (int j = 0; j < N; j++)
            {
                cout << maze[i][j] << "";
            }
            cout << endl;
        }
        return true;
    }

    vector<int> possible_values = getValues(maze, missing[position].first, missing[position].second);
    for (auto i : possible_values)
    {
        maze[missing[position].first][missing[position].second] = i; // value set
        if (solveSudoku(maze, missing, position + 1))                // go to the next missing value
            return true;                                             // sudoku solved - exactly one solution - has been printed already
    }

    maze[missing[position].first][missing[position].second] = 0;
    return false; // missing is empty wrong configuration, update the value back to zero
}

int main()
{
    int maze[N][N];
    string inp;
    vector<pair<int, int>> missing;
    for (int i = 0; i < N; i++)
    {
        cin >> inp;
        for (int j = 0; j < N; j++)
        {
            maze[i][j] = int(inp[j]) - 48;
            if (maze[i][j] == 0)
                missing.push_back({i, j});
        }
    }
    solveSudoku(maze, missing, 0);
    // we need to fill the zeros of the array
    return 0;
}
