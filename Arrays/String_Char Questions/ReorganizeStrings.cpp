// Leetcode Problem No : 767 - Reorganize String(Medium)

/*
Given a string s, rearrange the characters of s so that any two adjacent characters are not the same.

Return any possible rearrangement of s or return "" if not possible.



Example 1:

Input: s = "aab"
Output: "aba"
Example 2:

Input: s = "aaab"
Output: ""


Constraints:

1 <= s.length <= 500
s consists of lowercase English letters.
*/

#include <iostream>
#include <string.h>
#include <vector>

using namespace std;

class Solution
{
public:
    string reorganizeString(string s)
    {
        int n = s.length();
        vector<int> freq(26, 0);

        // Step 1: Count character frequencies
        for (char c : s)
        {
            freq[c - 'a']++;
        }

        // Step 2: Find the most frequent character
        int maxFreq = 0, maxChar = 0;
        for (int i = 0; i < 26; i++)
        {
            if (freq[i] > maxFreq)
            {
                maxFreq = freq[i];
                maxChar = i;
            }
        }

        // Step 3: Check if the highest frequency is valid
        if (maxFreq > (n + 1) / 2)
            return "";

        // Step 4: Fill the result array
        string result(n, ' ');
        int index = 0;

        while (freq[maxChar] > 0)
        {
            result[index] = 'a' + maxChar;
            freq[maxChar]--;
            index += 2;
        }

        // Step 5: Place the remaining characters
        for (int i = 0; i < 26; i++)
        {
            while (freq[i] > 0)
            {
                if (index >= n)
                    index = 1;
                result[index] = 'a' + i;
                freq[i]--;
                index += 2;
            }
        }

        return result;
    }
};