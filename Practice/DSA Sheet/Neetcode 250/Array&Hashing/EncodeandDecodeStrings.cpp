/*
Design an algorithm to encode a list of strings to a single string. The encoded string is then decoded back to the original list of strings.

Please implement encode and decode

Example 1:

Input: ["neet","code","love","you"]

Output:["neet","code","love","you"]
Example 2:

Input: ["we","say",":","yes"]

Output: ["we","say",":","yes"]
Constraints:

0 <= strs.length < 100
0 <= strs[i].length < 200
strs[i] contains only UTF-8 characters.
*/

#include <bits/stdc++.h>

using namespace std;

class Solution
{
public:
    string encode(vector<string> &strs)
    {
        string ans = "";
        for (string str : strs)
        {
            ans += to_string(str.size()) + '#' + str;
        }
        return ans;
    }

    vector<string> decode(string s)
    {
        vector<string> result;
        int i = 0;
        while (i < s.size())
        {
            int j = i;
            while (s[j] != '#')
                j++;
            int len = stoi(s.substr(i, j - i));
            result.push_back(s.substr(j + 1, len));
            i = j + len + 1;
        }
        return result;
    }
};
