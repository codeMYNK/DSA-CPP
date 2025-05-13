// Leetcode Problem No : 1268 - Search Suggestion System(Medium)

/*
You are given an array of strings products and a string searchWord.

Design a system that suggests at most three product names from products after each character of searchWord is typed. Suggested products should have common prefix with searchWord. If there are more than three products with a common prefix return the three lexicographically minimums products.

Return a list of lists of the suggested products after each character of searchWord is typed.



Example 1:

Input: products = ["mobile","mouse","moneypot","monitor","mousepad"], searchWord = "mouse"
Output: [["mobile","moneypot","monitor"],["mobile","moneypot","monitor"],["mouse","mousepad"],["mouse","mousepad"],["mouse","mousepad"]]
Explanation: products sorted lexicographically = ["mobile","moneypot","monitor","mouse","mousepad"].
After typing m and mo all products match and we show user ["mobile","moneypot","monitor"].
After typing mou, mous and mouse the system suggests ["mouse","mousepad"].
Example 2:

Input: products = ["havana"], searchWord = "havana"
Output: [["havana"],["havana"],["havana"],["havana"],["havana"],["havana"]]
Explanation: The only word "havana" will be always suggested while typing the search word.


Constraints:

1 <= products.length <= 1000
1 <= products[i].length <= 3000
1 <= sum(products[i].length) <= 2 * 104
All the strings of products are unique.
products[i] consists of lowercase English letters.
1 <= searchWord.length <= 1000
searchWord consists of lowercase English letters.

*/

#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

class TrieNode
{
public:
    char data;
    TrieNode *children[26];
    bool isTerminal;
    vector<string> suggestions;

    TrieNode(char d)
    {
        data = d;
        for (int i = 0; i < 26; i++)
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

class Solution
{
private:
    void insertString(TrieNode *root, const string &word)
    {
        TrieNode *current = root;
        for (char ch : word)
        {
            int index = ch - 'a';
            if (!current->children[index])
            {
                current->children[index] = new TrieNode(ch);
            }
            current = current->children[index];

            if (current->suggestions.size() < 3)
                current->suggestions.push_back(word);
        }
        current->isTerminal = true;
    }

public:
    vector<vector<string>> suggestedProducts(vector<string> &products, string searchWord)
    {
        sort(products.begin(), products.end());

        TrieNode *root = new TrieNode('\0');
        for (const string &word : products)
        {
            insertString(root, word);
        }

        vector<vector<string>> result;
        TrieNode *current = root;
        for (char ch : searchWord)
        {
            int index = ch - 'a';
            if (current && current->children[index])
            {
                current = current->children[index];
                result.push_back(current->suggestions);
            }
            else
            {
                current = nullptr;
                result.push_back({});
            }
        }

        delete root;
        return result;
    }
};