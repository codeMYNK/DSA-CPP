// GfG Problem - Longest Substring with K Uniques(Medium)

/*
Given a string s, you need to print the size of the longest possible substring with exactly k unique characters. If no possible substring exists, print -1.

Examples:

Input: s = "aabacbebebe", k = 3
Output: 7
Explanation: "cbebebe" is the longest substring with 3 distinct characters.
Input: s = "aaaa", k = 2
Output: -1
Explanation: There's no substring with 2 distinct characters.
Input: s = "aabaaab", k = 2
Output: 7
Explanation: "aabaaab" is the longest substring with 2 distinct characters.
Constraints:
1 ≤ s.size() ≤ 105
1 ≤ k ≤ 26
All characters are lowercase letters


*/

#include <bits/stdc++.h>

using namespace std;

// User function template for C++

class Solution
{
public:
    int longestKSubstr(string &s, int k)
    {
        // your code here
        int l = 0, r = 0, maxLen = -1, n = s.length();
        unordered_map<char, int> mpp;

        while (r < n)
        {
            mpp[s[r]]++;

            
            while (mpp.size() > k)
            {
                mpp[s[l]]--;
                if (mpp[s[l]] == 0)
                    mpp.erase(s[l]);
                l++;
            }

            if (mpp.size() == k)
            {
                maxLen = max(r - l + 1, maxLen);
            }

            r++;
        }
        return maxLen;
    }
};