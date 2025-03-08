// Leetcode Question No : 14 - Longest Common Prefix(Easy)

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
#include <string.h>
#include <algorithm>
#include <vector>

using namespace std;

class Solution
{
public:
    string longestCommonPrefix(vector<string> &strs)
    {
        if (strs.empty())
        {
            return "";
        }
        string prefixRef = strs[0];

        for (int i = 0; i < strs.size(); i++)
        {
            while (strs[i].find(prefixRef) != 0)
            {
                prefixRef = prefixRef.substr(0, prefixRef.length() - 1);
                if (prefixRef.empty())
                    return "";
            }
        }
        return prefixRef;
    }
};