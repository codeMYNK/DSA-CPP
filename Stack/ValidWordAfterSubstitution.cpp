// Leetcode Problem No - 1003 : Check if word is valid after Substitutions(Medium)

/*
Given a string s, determine if it is valid.

A string s is valid if, starting with an empty string t = "", you can transform t into s after performing the following operation any number of times:

Insert string "abc" into any position in t. More formally, t becomes tleft + "abc" + tright, where t == tleft + tright. Note that tleft and tright may be empty.
Return true if s is a valid string, otherwise, return false.



Example 1:

Input: s = "aabcbc"
Output: true
Explanation:
"" -> "abc" -> "aabcbc"
Thus, "aabcbc" is valid.
Example 2:

Input: s = "abcabcababcc"
Output: true
Explanation:
"" -> "abc" -> "abcabc" -> "abcabcabc" -> "abcabcababcc"
Thus, "abcabcababcc" is valid.
Example 3:

Input: s = "abccba"
Output: false
Explanation: It is impossible to get "abccba" using the operation.


Constraints:

1 <= s.length <= 2 * 104
s consists of letters 'a', 'b', and 'c'
*/

#include <iostream>
#include <stack>
#include <string.h>

using namespace std;

class Solution
{
public:
    bool isValid(string s)
    {
        if (s[0] != 'a')
            return false;

        stack<char> st;

        for (char ch : s)
        {
            if (ch == 'a')
            {
                st.push(ch);
            }
            else if (ch == 'b')
            {
                if (!st.empty() && st.top() == 'a')
                {
                    st.push(ch);
                }
                else
                {
                    return false;
                }
            }
            else
            {
                if (!st.empty() && st.top() == 'b')
                {
                    st.pop();
                    if (!st.empty() && st.top() == 'a')
                    {
                        st.pop();
                    }
                    else
                    {
                        return false;
                    }
                }
                else
                {
                    return false;
                }
            }
        }
        return st.empty();
    }
};