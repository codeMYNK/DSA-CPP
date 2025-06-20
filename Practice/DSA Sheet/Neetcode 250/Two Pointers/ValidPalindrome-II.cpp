/*
You are given a string s, return true if the s can be a palindrome after deleting at most one character from it.

A palindrome is a string that reads the same forward and backward.

Note: Alphanumeric characters consist of letters (A-Z, a-z) and numbers (0-9).

Example 1:

Input: s = "aca"

Output: true
Explanation: "aca" is already a palindrome.

Example 2:

Input: s = "abbadc"

Output: false
Explanation: "abbadc" is not a palindrome and can't be made a palindrome after deleting at most one character.

Example 3:

Input: s = "abbda"

Output: true
Explanation: "We can delete the character 'd'.

Constraints:

1 <= s.length <= 100,000
s is made up of only lowercase English letters.

*/

#include <bits/stdc++.h>

using namespace std;

class Solution
{
private:
    bool helper(string x, int i, int j)
    {
        while (i <= j)
        {
            if (x[i] != x[j])
                return false;
            i++;
            j--;
        }
        return true;
    }

public:
    bool validPalindrome(string s)
    {
        int i = 0;
        int j = s.length() - 1;

        while (i < j)
        {
            if (s[i] != s[j])
            {
                return helper(s, i + 1, j) || helper(s, i, j - 1);
            }
            i++;
            j--;
        }
        return true;
    }
};