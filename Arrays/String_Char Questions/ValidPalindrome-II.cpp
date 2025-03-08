// Leetcode Question No - 680 : Valid Palindrome - II (Easy)

/*
Given a string s, return true if the s can be palindrome after deleting at most one character from it.

Example 1:

Input: s = "aba"
Output: true
Example 2:

Input: s = "abca"
Output: true
Explanation: You could delete the character 'c'.
Example 3:

Input: s = "abc"
Output: false


Constraints:

1 <= s.length <= 105
s consists of lowercase English letters.
*/

#include <iostream>
#include <string.h>

using namespace std;

class Solution
{
public:
    bool checkPalindrome(string x, int i, int j)
    {
        while (i <= j)
        {
            if (x[i] != x[j])
            {
                return false;
            }
            else
            {
                i++;
                j--;
            }
        }
        return true;
    }
    bool validPalindrome(string s)
    {
        int i = 0;
        int j = s.length() - 1;

        while (i <= j)
        {
            if (s[i] != s[j])
            {
                return checkPalindrome(s, i + 1, j) || checkPalindrome(s, i, j - 1);
            }
            else
            {
                i++;
                j--;
            }
        }
        return true;
    }
};