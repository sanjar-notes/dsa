#include <iostream>
using namespace std;

int subs(string input, string output[]);
int main()
{
    string input;
    getline(cin, input);
    string *output = new string[1024];
    // output[0] = "Op";
    // cout << "Number of subsequneces: " << count;
    int count = subs(input, output);
    cout << "\n-------------------------------------------------------------\n";
    for (int i = 0; i < count; i++)
        cout << output[i] << endl;

    cout << "\n-------------------------------------------------------------\n";
    cout << "Count: " << count << "\n";
    return 0;
}

int subs(string input, string output[])
{
    if (input.empty())
    {
        // output[0] = " OK!";
        return 1;
    }

    int smallOutputSize = subs(input.substr(1), output);
    for (int i = 0; i < smallOutputSize; i++)
    {
        // have to append the character of this Activation record to every other subsequence in the output
        // also have to preserve the previous output, without prepend
        output[i + smallOutputSize] = input[0] + output[i];
    }
    return smallOutputSize * 2;
}
