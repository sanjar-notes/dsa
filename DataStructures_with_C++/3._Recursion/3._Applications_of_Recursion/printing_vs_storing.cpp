#include <iostream>
using namespace std;

void print_subsequences(string output, string input);

int main()
{
    string input;
    getline(cin, input);
    print_subsequences("", input);
    cout << endl;
    return 0;
}

void print_subsequences(string output, string input)
{
    if (input.empty())
    {
        cout << output << endl;
        return;
    }
    print_subsequences(output, input.substr(1));    // this will have all the "" part
    print_subsequences(output + input[0], input.substr(1));
}
