#include <iostream>
using namespace std;
#include "Trie.h"

int main()
{
    Trie p;
    p.insertWord("bread");
    p.insertWord("break");
    cout << p.searchWord("break");
    p.removeWord("break");
    cout << p.searchWord("break");
    cout << endl;
    return 0;
}
