# 1. Tries
Created Monday 22 June 2020

https://leetcode.com/problems/implement-trie-prefix-tree/

```cpp
class TrieNode {
public:
    char value;
    char wordEnd;
    vector<TrieNode*> children;

    TrieNode(char value = 0, bool wordEnd = false) {
        this->value = value;
        this->wordEnd = wordEnd;
        children.resize(26);
        for (int i = 0; i < 26; i++)
            children[i] = NULL;
    }
};

class Trie {
public:
    TrieNode* root;
    Trie() {
        // trie, first is an element
        root = new TrieNode;
    }

    void insert(string word) {
        TrieNode* trav = root;
        for (auto ch : word) {
            if (!trav->children[ch - 'a'])
                trav->children[ch - 'a'] = new TrieNode(ch - 'a');

            trav = trav->children[ch - 'a'];
        }
        trav->wordEnd = true;
    }

    bool search(string word) {
        TrieNode* trav = root;
        for (auto ch : word) {
            if (trav->children[ch - 'a'])
                trav = trav->children[ch - 'a'];
            else
                return false;
        }
        return trav->wordEnd;
    }

    bool startsWith(string prefix) {
        TrieNode* trav = root;
        for (auto ch : prefix) {
            if (trav->children[ch - 'a'])
                trav = trav->children[ch - 'a'];
            else
                return false;
        }
        return true;
    }
};

/**
 * Your Trie object will be instantiated and called as such:
 * Trie* obj = new Trie();
 * obj->insert(word);
 * bool param_2 = obj->search(word);
 * bool param_3 = obj->startsWith(prefix);
 */
```

