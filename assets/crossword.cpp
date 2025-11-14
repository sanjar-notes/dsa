#include <iostream>
#include <vector>
using namespace std;

#define N 10

// How to solve it?
/*
    1. We'll take the input.
    2. We'll keep the missing letter as a pair input.
    3. We'll travel over the missing and try to fill the array.
    4.  Helper functions:
        a.  bool isValid(char maze[][N],string word, int r, int c, char mode) - checks if a word can be filled horizontally starting from a position.
        b.  vector<bool> setWord(char maze[][N],string word, int r, int c, vector<bool>individual) - The vectors keeps track of the letters which are unshared
        c.  void resetMissing(char maze[][N],string word, int r, int c, vector<bool>individual)
    5. solveCrossword(char maze[][N],ctor<string>, vector<missing>) - iterates over the missing and inserts values
    6. We stop if all the positions in missing are occupied.
*/

bool isValid(char maze[][N], string word, int r, int c, char mode);
vector<bool> setWord(char maze[][N], string word, int r, int c, char mode);
void resetMissing(char maze[][N], string word, int r, int c, vector<bool> &individual, char mode);
bool solveCrossword(char maze[][N], vector<pair<int, int>> missing, vector<pair<string, bool>> &words);
vector<pair<string, bool>> userInputWords();

// Main starts------------>
int main()
{
    char maze[N][N]; // max N = 1000, 1000^2 = 1 MB
    vector<pair<int, int>> missing;

    // take the maze and records missing places
    for (int i = 0; i < N; i++)
    {
        for (int j = 0; j < N; j++)
        {
            cin >> maze[i][j];
            if (maze[i][j] == '-')
                missing.push_back({i, j});
        }
    }
    // takes the words
    // vector<pair<string, bool>>& words = userInputWords();

    // Trial
    string allinp;
    cin >> allinp;
    vector<pair<string, bool>> words;
    for (int start = 0, end = 0, leng = allinp.size(); start < leng;) // start - start of word, end - end of word
    {
        while (end != leng && allinp[end] != ';')
            end++;
        words.push_back({allinp.substr(start, end - start), false}); // not including the !, at the end - not including '/0'
        start = ++end;                                               // both start and end move to the letter after ;
    }

    // all inputs taken
    // if solvable print - In our case it is given that it is solvable
    // printing here because there's only one possible solution
    if (solveCrossword(maze, missing, words))
    {

        for (int i = 0; i < N; i++)
        {
            for (int j = 0; j < N; j++)
                cout << maze[i][j];
            cout << endl;
        }
        return true;
    }
}

vector<pair<string, bool>> userInputWords() // OK
{
    // words seperated by ; // there's no ; at the end
    string allinp;
    cin >> allinp;
    vector<pair<string, bool>> words;
    for (int start = 0, end = 0, leng = allinp.size(); start < leng;) // start - start of word, end - end of word
    {
        while (end != leng && allinp[end] != ';')
            end++;
        words.push_back({allinp.substr(start, end - start), false}); // not including the !, at the end - not including '/0'
        start = ++end;                                               // both start and end move to the letter after ;
    }
    return words;
}

// End of main ------------>
bool isValid(char maze[][N], string word, int r, int c, char mode)
{
    /*
        1. Check if length is sufficient.
        2. Check if we can place everything, empty or the same.
    */
    int a, b, *i;                        // 2 values: 2 iterators and an end
    if (mode == 'H' || mode == 'h')      // row fixed
        a = r, b = c, i = &b;            //column changes
    else if (mode == 'V' || mode == 'v') // column fixed
        a = r, b = c, i = &a;            // row changes
    else
    {
        cout << "Invalid mode - should be H or V" << endl;
        return false;
    }

    // the character can be a - or a matching character
    for (int end = word.size(); i[0] < end && i[0] < N; i[0]++)
    {
        if (maze[a][b] == '-' || maze[a][b] == word[i[0]])
            continue;
        else
            return false;
    }
    return true;
}

vector<bool> setWord(char maze[][N], string word, int r, int c, char mode)
{
    vector<bool> ret;                    // for return
    int a, b, *i;                        // 2 values: 2 iterators and an end
    if (mode == 'H' || mode == 'h')      // row fixed
        a = r, b = c, i = &b;            //column changes
    else if (mode == 'V' || mode == 'v') // column fixed
        a = r, b = c, i = &a;            // row changes
    else
    {
        cout << "Invalid mode - should be H or V" << endl;
        return ret;
    }
    for (int end = word.size(); i[0] < end; i[0]++) // no need to check for N
    {
        ret.push_back(maze[a][b] == '-');
        maze[a][b] = word[i[0]];
    }
    return ret;
}

void resetMissing(char maze[][N], string word, int r, int c, vector<bool> &individual, char mode)
{
    int a, b, *i;                        // 2 values: 2 iterators and an end
    if (mode == 'H' || mode == 'h')      // row fixed
        a = r, b = c, i = &b;            //column changes
    else if (mode == 'V' || mode == 'v') // column fixed
        a = r, b = c, i = &a;            // row changes
    else
    {
        cout << "Invalid mode - should be H or V" << endl;
        return;
    }
    auto curr = individual.begin(), end = individual.end();
    for (int end = word.size(), indi = 0; i[0] < end; i[0]++, indi++) // no need to check for N
    {
        if (individual[indi]) //true means -
            maze[a][b] = '-';
    }
}

bool solveCrossword(char maze[][N], vector<pair<int, int>> missing, vector<pair<string, bool>> &words)
{
    // if (words.size() == 0) // all words placed
    //     return true;
    // cout << "p";
    bool allFilled = true;
    // some words remain
    for (auto &point : missing)
    {
        //try to fit unused words
        for (auto &word : words)
        {
            if (!word.second) //choose an unused word
            {
                allFilled = false;
                for (char mode : {'H', 'V'}) // try both modes
                {
                    if (isValid(maze, word.first, point.first, point.second, mode))
                    {
                        word.second = true; // being used
                        vector<bool> indiv = setWord(maze, word.first, point.first, point.second, mode);
                        if (solveCrossword(maze, missing, words)) // all solved
                            return true;
                        // return true;
                        resetMissing(maze, word.first, point.first, point.second, indiv, mode);
                        word.second = false;
                    }
                }
                // word not suitable, set it to unused again
            }
        }
    }
    return allFilled; // true only if all filled
    // couldn't solve
}

// Trials
int mains()
{
    cout << "Trial Start\n";
    vector<pair<string, bool>> words = userInputWords();

    for (auto &word : words)
        cout << word.first << endl;
    cout << "Trial End" << endl;
    return 0;
}
