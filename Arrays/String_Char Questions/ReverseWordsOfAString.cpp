// Leetcode Problem No 151 : Reverse Words Of A String(Medium)

/*
Given an input string s, reverse the order of the words.

A word is defined as a sequence of non-space characters. The words in s will be separated by at least one space.

Return a string of the words in reverse order concatenated by a single space.

Note that s may contain leading or trailing spaces or multiple spaces between two words. The returned string should only have a single space separating the words. Do not include any extra spaces.



Example 1:

Input: s = "the sky is blue"
Output: "blue is sky the"
Example 2:

Input: s = "  hello world  "
Output: "world hello"
Explanation: Your reversed string should not contain leading or trailing spaces.
Example 3:

Input: s = "a good   example"
Output: "example good a"
Explanation: You need to reduce multiple spaces between two words to a single space in the reversed string.


Constraints:

1 <= s.length <= 104
s contains English letters (upper-case and lower-case), digits, and spaces ' '.
There is at least one word in s.


Follow-up: If the string data type is mutable in your language, can you solve it in-place with O(1) extra space?
*/

#include <iostream>
#include <vector>
#include <string.h>
#include <algorithm>

using namespace std;

class Solution
{
public:
    string reverseWords(string s)
    {
        string resultAns = "";
        vector<string> word;

        for (int i = 0; i < s.size(); i++)
        {
            if (s[i] != ' ')
            {
                resultAns = resultAns + s[i]; // Building the word
            }
            else if (!resultAns.empty())
            {
                word.push_back(resultAns);
                resultAns = "";
            }
        }
        if (!resultAns.empty())
        {
            word.push_back(resultAns);
            resultAns = "";
        } // Pushing and checking for the last word

        reverse(word.begin(), word.end());

        for (int i = 0; i < word.size(); i++)
        {
            resultAns += word[i];
            if (i != word.size() - 1)
            {
                resultAns += " "; // Adding spaces but ensuring they are bit added on the last word
            }
        }
        return resultAns;
    }
};