// Leetcode Problem No 242 : Valid Anagram(Easy)

/*
Given two strings s and t, return true if t is an anagram of s, and false otherwise.



Example 1:

Input: s = "anagram", t = "nagaram"

Output: true

Example 2:

Input: s = "rat", t = "car"

Output: false



Constraints:

1 <= s.length, t.length <= 5 * 104
s and t consist of lowercase English letters.
*/

#include <iostream>
#include <string.h>
#include <vector>

using namespace std;

class Solution
{
public:
    bool isAnagram(string s, string t)
    {
        if (s.length() != t.length())
        {
            return false;
        }

        vector<int> keepCount(26, 0);
        for (int i = 0; i < s.length(); i++)
        {
            keepCount[s[i] - 'a']++;
            keepCount[t[i] - 'a']--;
        }

        for (int count : keepCount)
        {
            if (count != 0)
                return false;
        }
        return true;
    }
};