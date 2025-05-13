// Leetcode Problem No - 14 : Longest Common Prefix (Easy)

/*
Write a function to find the longest common prefix string amongst an array of strings.

If there is no common prefix, return an empty string "".



Example 1:

Input: strs = ["flower","flow","flight"]
Output: "fl"
Example 2:

Input: strs = ["dog","racecar","car"]
Output: ""
Explanation: There is no common prefix among the input strings.


Constraints:

1 <= strs.length <= 200
0 <= strs[i].length <= 200
strs[i] consists of only lowercase English letters if it is non-empty.
*/

#include <iostream>
#include <string>
#include <vector>

using namespace std;

class TrieNode
{
public:
    char data;
    TrieNode *children[26];
    bool isTerminal;
    int childCount;

    TrieNode(char d)
    {
        this->data = d;
        for (int i = 0; i < 26; i++)
        {
            children[i] = nullptr;
        }
        this->isTerminal = false;
        childCount = 0;
    }

    ~TrieNode()
    {
        for (int i = 0; i < 26; ++i)
        {
            delete children[i];
        }
    }
};

class Solution
{
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
            root->childCount++;
        }

        insertString(child, word.substr(1));
    }

public:
    void findLCP(TrieNode *root, string first, string &ans)
    {
        if (root->isTerminal)
            return;
        for (int i = 0; i < first.length(); i++)
        {
            char ch = first[i];
            if (root->childCount == 1)
            {
                ans.push_back(ch);
                root = root->children[ch - 'a'];
            }
            else
            {
                break;
            }

            if (root->isTerminal)
            {
                break;
            }
        }
    }
    string longestCommonPrefix(vector<string> &strs)
    {
        TrieNode *root = new TrieNode('\0');

        for (int i = 0; i < strs.size(); i++)
        {
            insertString(root, strs[i]);
        }

        string ans = "";
        findLCP(root, strs[0], ans);
        return ans;
    }
};