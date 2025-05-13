#include <iostream>
#include <string>

using namespace std;

class TrieNode
{
public:
    char data;
    TrieNode *children[26];
    bool isTerminal;

    TrieNode(char d)
    {
        this->data = d;
        for (int i = 0; i < 26; i++)
        {
            children[i] = nullptr;
        }
        this->isTerminal = false;
    }

    ~TrieNode()
    {
        for (int i = 0; i < 26; ++i)
        {
            delete children[i];
        }
    }
};

void insertString(TrieNode *root, string word)
{
    if (word.length() == 0)
    {
        root->isTerminal = true;
        return;
    }

    char ch = word[0];
    int index = ch - 'a';
    TrieNode *child;
    if (root->children[index] != NULL)
    {
        child = root->children[index];
    }
    else
    {
        child = new TrieNode(ch);
        root->children[index] = child;
    }

    insertString(child, word.substr(1));
}

bool searchWord(TrieNode *root, string word)
{
    if (word.length() == 0)
    {
        return root->isTerminal;
    }

    char ch = word[0];
    int index = ch - 'a';
    TrieNode *child;

    // checking for present
    if (root->children[index] != NULL)
    {
        child = root->children[index];
    }
    else
    {
        return false;
    }
    // recursive call
    return searchWord(child, word.substr(1));
}

int main()
{
    TrieNode *root = new TrieNode('\0');
    int numOfInput;
    cout << "Enter the number of strings you want to insert : ";
    cin >> numOfInput;
    cin.ignore();

    cout << "Enter the strings : " << endl;
    for (int i = 0; i < numOfInput; i++)
    {
        string temp;
        getline(cin, temp);
        insertString(root, temp);
    }

    string userSearch;

    cout << "Enter the word you want to search(WARNING: Search is case sensitive): ";
    getline(cin, userSearch);
    bool isPresent = searchWord(root, userSearch);

    if (isPresent)
        cout << "The search query is present in the Trie." << endl;
    else
        cout << "The search query is not present in the Trie" << endl;
    delete root;
    return 0;
}