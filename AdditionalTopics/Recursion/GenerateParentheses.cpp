// Leetcode Problem No 22 : Generate Parentheses (Medium)

/*
Given n pairs of parentheses, write a function to generate all combinations of well-formed parentheses.



Example 1:

Input: n = 3
Output: ["((()))","(()())","(())()","()(())","()()()"]
Example 2:

Input: n = 1
Output: ["()"]


Constraints:

1 <= n <= 8
*/

#include <iostream>
#include <vector>
#include <string.h>

using namespace std;

class Solution
{
public:
    void solve(vector<string> &ans, int n, int open, int close, string output)
    {
        if (open == 0 && close == 0)
        {
            ans.push_back(output);
            return;
        }

        // include open bracket
        if (open > 0)
        {
            output.push_back('(');
            solve(ans, n, open - 1, close, output);
            output.pop_back();
        }
        // include closing bracket
        if (close > open)
        {
            output.push_back(')');
            solve(ans, n, open, close - 1, output);
            output.pop_back();
        }
    }
    vector<string> generateParenthesis(int n)
    {
        vector<string> ans;
        int open = n;
        int close = n;
        string output = "";
        solve(ans, n, open, close, output);
        return ans;
    }
};