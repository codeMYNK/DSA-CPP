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

    // checking if the character is arleady present
    if (root->children[index] != NULL)
    {
        child = root->children[index];
    }
    else
    {
        // not present
        child = new TrieNode(ch);
        root->children[index] = child;
    }

    // recursive call to insert remaining characters of word
    insertString(child, word.substr(1));
}

int main()
{
    TrieNode *root = new TrieNode('\0');
    // insertion
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

    delete root;
    return 0;
}