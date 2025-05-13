// Leetcode Problem No : 208 - Implementing A Trie(Prefix Tree) (Medium)
/*
A trie (pronounced as "try") or prefix tree is a tree data structure used to efficiently store and retrieve keys in a dataset of strings. There are various applications of this data structure, such as autocomplete and spellchecker.

Implement the Trie class:

Trie() Initializes the trie object.
void insert(String word) Inserts the string word into the trie.
boolean search(String word) Returns true if the string word is in the trie (i.e., was inserted before), and false otherwise.
boolean startsWith(String prefix) Returns true if there is a previously inserted string word that has the prefix prefix, and false otherwise.


Example 1:

Input
["Trie", "insert", "search", "search", "startsWith", "insert", "search"]
[[], ["apple"], ["apple"], ["app"], ["app"], ["app"], ["app"]]
Output
[null, null, true, false, true, null, true]

Explanation
Trie trie = new Trie();
trie.insert("apple");
trie.search("apple");   // return True
trie.search("app");     // return False
trie.startsWith("app"); // return True
trie.insert("app");
trie.search("app");     // return True


Constraints:

1 <= word.length, prefix.length <= 2000
word and prefix consist only of lowercase English letters.
At most 3 * 104 calls in total will be made to insert, search, and startsWith.
*/

#include <iostream>
#include <string>

using namespace std;

class TrieNode
{
public:
    TrieNode *children[26];
    bool isTerminal;

    TrieNode()
    {
        for (int i = 0; i < 26; ++i)
        {
            children[i] = nullptr;
        }
        isTerminal = false;
    }

    ~TrieNode()
    {
        for (int i = 0; i < 26; ++i)
        {
            delete children[i];
        }
    }
};

class Trie
{
private:
    TrieNode *root;

    string toLowercase(const string &s)
    {
        string result = s;
        for (char &ch : result)
        {
            ch = tolower(ch);
        }
        return result;
    }

    void insertHelper(TrieNode *node, const string &word, int idx)
    {
        if (idx == word.size())
        {
            node->isTerminal = true;
            return;
        }

        char ch = word[idx];
        int index = ch - 'a';
        if (index < 0 || index >= 26)
            return;

        if (node->children[index] == nullptr)
        {
            node->children[index] = new TrieNode();
        }

        insertHelper(node->children[index], word, idx + 1);
    }

    bool searchHelper(TrieNode *node, const string &word, int idx)
    {
        if (idx == word.size())
        {
            return node->isTerminal;
        }

        char ch = word[idx];
        int index = ch - 'a';
        if (index < 0 || index >= 26 || node->children[index] == nullptr)
        {
            return false;
        }

        return searchHelper(node->children[index], word, idx + 1);
    }

    bool startsWithHelper(TrieNode *node, const string &prefix, int idx)
    {
        if (idx == prefix.size())
        {
            return true;
        }

        char ch = prefix[idx];
        int index = ch - 'a';
        if (index < 0 || index >= 26 || node->children[index] == nullptr)
        {
            return false;
        }

        return startsWithHelper(node->children[index], prefix, idx + 1);
    }

public:
    Trie()
    {
        root = new TrieNode();
    }

    ~Trie()
    {
        delete root;
    }

    void insert(const string &word)
    {
        insertHelper(root, toLowercase(word), 0);
    }

    bool search(const string &word)
    {
        return searchHelper(root, toLowercase(word), 0);
    }

    bool startsWith(const string &prefix)
    {
        return startsWithHelper(root, toLowercase(prefix), 0);
    }
};