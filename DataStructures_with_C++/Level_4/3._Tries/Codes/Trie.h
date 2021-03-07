// let us make the trie system
#include "TrieNode.h"
#include <string>
using namespace std;

class Trie
{
private:
    TrieNode *root;
    int size;

    void insertWord(TrieNode *root, string word)
    {
        // writing it recursively
        if (word.size() == 0) // last element
        {
            root->isTerminal = true;
            return;
        }
        // we need to have the start symbol
        if (root->children[word[0] - 'a'] == NULL) // the letter is absent
            root->children[word[0] - 'a'] = new TrieNode(word[0]), size++;

        insertWord(root->children[word[0] - 'a'], word.substr(1));
    }

    bool searchWord(TrieNode *root, string word)
    {
        if (word.size() == 0)
            return root->isTerminal; // last letter should be a terminal

        if (root->children[word[0] - 'a'] == NULL) // the letter is absent
            return false;

        return searchWord(root->children[word[0] - 'a'], word.substr(1));
    }

    void removeWord(TrieNode *root, string word)
    {
        if (word.size() == 0)
        {
            root->isTerminal = false; // irrespective of whether the root was a terminal or not
            return;
        }

        if (root->children[word[0] - 'a'] == NULL)
            return; // word not found

        // letter found propagate
        removeWord(root->children[word[0] - 'a'], word.substr(1));

        // check if child is a leaf, no other way to do this. Increases the constant of the delete operation.
        for (int i = 0; i < 26; i++)
        {
            if (root->children[word[0] - 'a']->children[i] != NULL)
                return; // we can't delete it
        }
        // child is a leaf, can be deleted
        delete root->children[word[0] - 'a'];
        root->children[word[0] - 'a'] = NULL;
    }

public:
    Trie()
    {
        root = new TrieNode('\0');
        size = 0;
        // all its children are NULL by default
    }

    int trieSize()
    {
        return size;
    }
    void insertWord(string word) // overloaded with a private function
    {
        insertWord(root, word);
    }

    bool searchWord(string word)
    {
        return searchWord(root, word); // overloaded with a private function
    }

    void removeWord(string word)
    {
        removeWord(root, word);
    }
};
