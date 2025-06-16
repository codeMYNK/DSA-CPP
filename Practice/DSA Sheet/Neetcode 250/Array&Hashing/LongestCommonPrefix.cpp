/*
You are given an array of strings strs. Return the longest common prefix of all the strings.

If there is no longest common prefix, return an empty string "".

Example 1:

Input: strs = ["bat","bag","bank","band"]

Output: "ba"
Example 2:

Input: strs = ["dance","dag","danger","damage"]

Output: "da"
Example 3:

Input: strs = ["neet","feet"]

Output: ""
Constraints:

1 <= strs.length <= 200
0 <= strs[i].length <= 200
strs[i] is made up of lowercase English letters if it is non-empty.

*/

#include <bits/stdc++.h>

using namespace std;

class Solution
{
public:
    string longestCommonPrefix(vector<string> &strs)
    {
        string temp = strs[0];
        string ans = "";

        for (int i = 1; i < strs.size(); i++)
        {
            ans = "";
            for (int j = 0; j < strs[i].length() && j < temp.length(); j++)
            {
                if (temp[j] != strs[i][j])
                    break;
                ans += temp[j];
            }
            temp = ans;
            if (temp == "")
                break;
        }
        return temp;
    }
};