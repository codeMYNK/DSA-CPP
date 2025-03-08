// Problem No 647 : Palindromic Substrings (Medium)

/*
Given a string s, return the number of palindromic substrings in it.

A string is a palindrome when it reads the same backward as forward.

A substring is a contiguous sequence of characters within the string.



Example 1:

Input: s = "abc"
Output: 3
Explanation: Three palindromic strings: "a", "b", "c".
Example 2:

Input: s = "aaa"
Output: 6
Explanation: Six palindromic strings: "a", "a", "a", "aa", "aa", "aaa".


Constraints:

1 <= s.length <= 1000
s consists of lowercase English letters.
*/

#include <iostream>
#include <string.h>

using namespace std;

class Solution
{
public:
    int expandAroundIndex(string x, int i, int j)
    {
        int count = 0;
        while (i >= 0 && j < x.length() && x[i] == x[j])
        {
            count++;
            i--;
            j++;
        }
        return count;
    }
    int countSubstrings(string s)
    {
        int count = 0;
        int stringLength = s.length();

        for (int i = 0; i < stringLength; i++)
        {
            count += expandAroundIndex(s, i, i);
            count += expandAroundIndex(s, i, i + 1);
        }
        return count;
    }
};