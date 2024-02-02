#include <iostream>
using namespace std;

void print_subsequences(string output, string input);
void print_keypad(int num, string output);

int main()
{
    // string input;
    // getline(cin, input);
    // print_subsequences("", input);

    int num = 0;
    cin >> num;
    print_keypad(num, "");
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
    print_subsequences(output, input.substr(1)); // this will have all the "" part
    print_subsequences(output + input[0], input.substr(1));
}

void print_keypad(int num, string output)
{

    if (num == 0)
    {
        cout << output << endl;
        return;
    }

    int a = num % 10;

    if (a <= 1)
    {
        print_keypad(num / 10, output);
        return;
    }
    string toPut = "";

    // switch case starts
    {
        switch (a)
        {
        case 2:
            toPut = "abc";
            break;
        case 3:
            toPut = "def";
            break;
        case 4:
            toPut = "ghi";
            break;
        case 5:
            toPut = "jkl";
            break;
        case 6:
            toPut = "mno";
            break;
        case 7:
            toPut = "pqrs";
            break;
        case 8:
            toPut = "tuv";
            break;
        case 9:
            toPut = "wxyz";
            break;
        default:
            toPut = ""; // end of everything
        }
    }

    // recursive call
    for (int i = 0; i < toPut.size(); i++) // this does not run if toPut() is empty, which means a was 0 or 1
        print_keypad(num / 10, toPut[i] + output);
}

/*
int a = num % 10;
        string toPut = "";

        switch (a)
        {
        case 2:
            toPut = "abc";
            break;
        case 3:
            toPut = "def";
            break;
        case 4:
            toPut = "ghi";
            break;
        case 5:
            toPut = "jkl";
            break;
        case 6:
            toPut = "mno";
            break;
        case 7:
            toPut = "pqrs";
            break;
        case 8:
            toPut = "tuv";
            break;
        case 9:
            toPut = "wxyz";
            break;
        // default: return 1; // end of everything
        }

*/
