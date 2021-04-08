// creating a node, like all trees
class TrieNode
{
public:
    char data;
    TrieNode **children; // array of addresses of children nodes
    bool isTerminal;     // true if terminal, false otherwise

    TrieNode(char ip = '\0')
    {
        data = ip | ' '; // 0, only smaller case allowed
        children = new TrieNode *[26] {};
        isTerminal = false;
    }
    ~TrieNode()
    {
        for (int i = 0; i < 26; i++)
            delete children[i]; // all 26 children deleted
        delete[] children;
    }
};
