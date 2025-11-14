#include <iostream>
using namespace std;
#include <vector>
#define N 9

bool isGivenMazeValid(int board[][N])
{
    bool arr[N];

    //check rows and columns
    for (int i = 0; i < N; i++)
    {
        //1st row and first column
        // row
        for (int p = 0; p < N; p++)
            arr[p] = false;

        for (int j = 0; j < N; j++)
        {
            if (board[i][j] == 0)
                continue;
            if (arr[board[i][j] - 1])
                return false; // duplicate
            else
                arr[board[i][j] - 1] = true;
        }

        for (int p = 0; p < N; p++)
            arr[p] = false;

        for (int j = 0; j < N; j++)
        {
            if (board[j][i] == 0)
                continue;
            if (arr[board[j][i] - 1])
                return false; // duplicate
            else
                arr[board[j][i] - 1] = true;
        }
    }

    // check 3x3 cells
    for (int i = 0; i < N; i += 3)
    {
        for (int j = 0; j < N; j += 3)
        {
            // intialize the map
            for (int p = 0; p < N; p++)
                arr[p] = false;

            for (int k = i, endi = i + 3; k < endi; k++)
            {
                for (int l = 0, endj = j + 3; l < endj; l++)
                {
                    if (board[k][l] == 0)
                        continue;
                    if (arr[board[k][l] - 1])
                        return false; // duplicate
                    else
                        arr[board[k][l] - 1] == true;
                }
            }
        }
    }
    return true;
}

vector<pair<int, int>> catchMissing(int board[][N]) // gets the missing ones
{
    vector<pair<int, int>> missing;
    for (int i = 0; i < N; i++)
    {
        for (int j = 0; j < N; j++)
        {
            if (board[i][j] == 0)
                missing.push_back({i, j});
        }
    }
    return missing;
}

vector<int> generateChoices(int board[][N], int r, int c)
{
    vector<int> ret;
    // check the unit 3 x 3 cell
    bool arr[N];
    for (int i = 0; i < N; i++)
        arr[i] = false;

    int r3 = 3 * (r / 3), c3 = 3 * (c / 3);

    for (int i = r3, endi = r3 + 3; i < endi; i++)
    {
        for (int j = c3, endj = c3 + 3; j < endj; j++)
        {
            if (board[i][j] != 0)
                arr[board[i][j] - 1] = true; // present
        }
    }

    // check the rows and columns
    for (int i = 0; i < N; i++)
    {
        arr[board[i][c] - 1] = board[i][c] == board[r][c];
        arr[board[r][i] - 1] = board[r][i] == board[r][c];
    }

    for (int i = 0; i < N; i++)
    {
        if (arr[i] == false)
            ret.push_back(i + 1);
    }
    return ret;
}

bool helper(int board[][N], vector<pair<int, int>> missing, int current)
{
    // traverse the missing points and solve them
    // if stuck backtrack
    if (current == missing.size())
        return true; // all solved

    vector<int> choices = generateChoices(board, missing[current].first, missing[current].first);
    if (choices.size() != 0)
    {
        for (auto choice : choices)
        {
            // apply the choice
            board[missing[current].first][missing[current].first] = choice;
            if (helper(board, missing, current + 1))
                return true; //return even if a single solution found
            board[missing[current].first][missing[current].first] = 0;
        }
    }
    // no choices can solve it return false;
    return false;
}

bool sudokuSolver(int board[][N])
{
    if (isGivenMazeValid(board) == false)
        return false;
    vector<pair<int, int>> missing = catchMissing(board);
    return missing.size() == 0 || helper(board, missing, 0); // Okay if none missing or else solve it
}

int main()
{

    int n = N;
    int board[N][N];
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            cin >> board[i][j];
        }
    }
    if (sudokuSolver(board))
    {
        cout << "true";
    }
    else
    {
        cout << "false";
    }
}
