// Leetcode Problem No :1405 - Longest Happy String(Medium)

/*
A string s is called happy if it satisfies the following conditions:

s only contains the letters 'a', 'b', and 'c'.
s does not contain any of "aaa", "bbb", or "ccc" as a substring.
s contains at most a occurrences of the letter 'a'.
s contains at most b occurrences of the letter 'b'.
s contains at most c occurrences of the letter 'c'.
Given three integers a, b, and c, return the longest possible happy string. If there are multiple longest happy strings, return any of them. If there is no such string, return the empty string "".

A substring is a contiguous sequence of characters within a string.



Example 1:

Input: a = 1, b = 1, c = 7
Output: "ccaccbcc"
Explanation: "ccbccacc" would also be a correct answer.
Example 2:

Input: a = 7, b = 1, c = 0
Output: "aabaa"
Explanation: It is the only correct answer in this case.


Constraints:

0 <= a, b, c <= 100
a + b + c > 0
*/

#include <iostream>
#include <string.h>
#include <queue>

using namespace std;

class Solution
{
public:
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
    string longestDiverseString(int a, int b, int c)
    {
        priority_queue<node *, vector<node *>, compare> maxHeap;

        if (a > 0)
        {
            node *temp = new node('a', a);
            maxHeap.push(temp);
        }

        if (b > 0)
        {
            node *temp = new node('b', b);
            maxHeap.push(temp);
        }

        if (c > 0)
        {
            node *temp = new node('c', c);
            maxHeap.push(temp);
        }

        string ans = "";

        while (maxHeap.size() > 1)
        {
            node *first = maxHeap.top();
            maxHeap.pop();

            node *second = maxHeap.top();
            maxHeap.pop();

            if (first->count >= 2)
            {
                ans += first->data;
                ans += first->data;

                first->count -= 2;
            }
            else
            {
                ans += first->data;
                first->count--;
            }

            if (second->count >= 2 && second->count >= first->count)
            {
                ans += second->data;
                ans += second->data;

                second->count -= 2;
            }
            else
            {
                ans += second->data;
                second->count--;
            }

            if (first->count > 0)
                maxHeap.push(first);
            if (second->count > 0)
                maxHeap.push(second);
        }

        if (maxHeap.size() == 1)
        {
            node *temp = maxHeap.top();
            maxHeap.pop();
            if (temp->count >= 2)
            {
                ans += temp->data;
                ans += temp->data;
                temp->count -= 2;
            }
            else
            {
                ans += temp->data;
                temp->count--;
            }
        }
        return ans;
    }
};