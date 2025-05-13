// Leetcode Problem No: 767 - Reorganize Strings (Medium)

/*
Given a string s, rearrange the characters of s so that any two adjacent characters are not the same.

Return any possible rearrangement of s or return "" if not possible.



Example 1:

Input: s = "aab"
Output: "aba"
Example 2:

Input: s = "aaab"
Output: ""


Constraints:

1 <= s.length <= 500
s consists of lowercase English letters.
*/

#include <iostream>
#include <queue>
#include <string.h>

using namespace std;

class node
{
public:
    char data;
    int count;

    node(char data, int count)
    {
        this->data = data;
        this->count = count;
    }
};

class compare
{
public:
    bool operator()(node *a, node *b)
    {
        return a->count < b->count;
    }
};

class Solution
{
public:
    string reorganizeString(string s)
    {
        int freq[26] = {0};

        for (char c : s)
        {
            freq[c - 'a']++;
        }

        priority_queue<node *, vector<node *>, compare> maxHeap;

        for (int i = 0; i < 26; i++)
        {
            if (freq[i] != 0)
            {
                node *temp = new node(i + 'a', freq[i]);
                maxHeap.push(temp);
            }
        }

        string ans = "";
        while (maxHeap.size() > 1)
        {
            node *first = maxHeap.top();
            maxHeap.pop();

            node *second = maxHeap.top();
            maxHeap.pop();

            ans += first->data;
            ans += second->data;

            first->count--;
            second->count--;

            if (first->count > 0)
                maxHeap.push(first);
            if (second->count > 0)
                maxHeap.push(second);
        }

        if (!maxHeap.empty())
        {
            node *tmp = maxHeap.top();
            if (tmp->count == 1)
            {
                ans += tmp->data;
            }
            else
            {
                return "";
            }
        }

        return ans;
    }
};