// Leetcode Problem No 5 : Longest Palindromic Substring(Medium)

/*
Given a string s, return the longest palindromic substring in s.



Example 1:

Input: s = "babad"
Output: "bab"
Explanation: "aba" is also a valid answer.
Example 2:

Input: s = "cbbd"
Output: "bb"


Constraints:

1 <= s.length <= 1000
s consist of only digits and English letters.
*/

#include <iostream>
#include <string.h>

using namespace std;

class Solution
{
public:
    string longestPalindromeFinder(string x, int start, int end)
    {
        string ans = "";
        while (start >= 0 && end < x.length() && x[start] == x[end])
        {

            start--;
            end++;
        }
        int validStart = start + 1;
        int validLength = end - start - 1;

        if (validStart >= 0 && validStart < x.length() && validLength > 0)
        {
            return x.substr(validStart, validLength);
        }
        else
        {
            return "";
        }
    }
    string longestPalindrome(string s)
    {
        string answer = "";
        for (int i = 0; i < s.length(); i++)
        {
            string oddLengthPalindrome = longestPalindromeFinder(s, i, i);
            string evenLengthPalindrome = longestPalindromeFinder(s, i, i + 1);

            if (oddLengthPalindrome.length() > answer.length())
            {
                answer = oddLengthPalindrome;
            }
            if (evenLengthPalindrome.length() > answer.length())
            {
                answer = evenLengthPalindrome;
            }
        }
        return answer;
    }
};