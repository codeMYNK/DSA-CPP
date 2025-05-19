// Leetcode Problem No : 44 - Wildcard Matching (Hard)

/*
Given an input string (s) and a pattern (p), implement wildcard pattern matching with support for '?' and '*' where:

'?' Matches any single character.
'*' Matches any sequence of characters (including the empty sequence).
The matching should cover the entire input string (not partial).



Example 1:

Input: s = "aa", p = "a"
Output: false
Explanation: "a" does not match the entire string "aa".
Example 2:

Input: s = "aa", p = "*"
Output: true
Explanation: '*' matches any sequence.
Example 3:

Input: s = "cb", p = "?a"
Output: false
Explanation: '?' matches 'c', but the second letter is 'a', which does not match 'b'.


Constraints:

0 <= s.length, p.length <= 2000
s contains only lowercase English letters.
p contains only lowercase English letters, '?' or '*'.
*/

#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    // bool solve(string &str, string &pattern, int i, int j){ - Recursive Approach
    //     if(i < 0 && j < 0) return true;
    //     if(i >= 0 && j < 0) return false;
    //     if(i > 0 && j >= 0){
    //         for(int k = 0; k <= j; k++){
    //             if(pattern[k] != '*'){
    //                 return false;
    //             }
    //         }
    //         return true;
    //     }
    //     if(str[i] == pattern[j] || pattern[j] == '?') return solve(str, pattern, i - 1, j - 1);
    //     else if(pattern[j] == '*'){
    //         return (solve(str, pattern, i - 1, j) || solve(str, pattern, i, j - 1));
    //     }
    //     else return false;
    // }
    // bool solveMem(string &str, string &pattern, int i, int j, vector<vector<int>> &dp){ - Top Down DP
    //     if(i == 0 && j == 0) return true;
    //     if(i > 0 && j == 0) return false;
    //     if(i == 0 && j > 0){
    //         for(int k = 0; k < j; k++){
    //             if(pattern[k] != '*'){
    //                 return false;
    //             }
    //         }
    //         return true;
    //     }
    //     if(dp[i][j] != -1) return dp[i][j];
    //     bool isMatch = false;
    //     if(str[i - 1] == pattern[j - 1] || pattern[j - 1] == '?') isMatch = solveMem(str, pattern, i - 1, j - 1, dp);
    //     else if(pattern[j - 1] == '*'){
    //         isMatch = (solveMem(str, pattern, i - 1, j, dp) || solveMem(str, pattern, i, j - 1, dp));
    //     }
    //     else isMatch = false;
    //     return dp[i][j] = isMatch;
    // }
    //      bool solveTab(string &str, string &pattern){ - Bottom Up DP
    //          vector<vector<int>> dp(str.length() + 1, vector<int> (pattern.length() + 1, 0));
    //          dp[0][0] = 1;
    //          for (int i = 1; i <= str.length(); i++) {
    //             dp[i][0] = 0;
    //         }
    //          for (int j = 1; j <= pattern.length(); j++) {
    //     bool allStars = true;
    //     for (int k = 0; k < j; k++) {
    //         if (pattern[k] != '*') {
    //             allStars = false;
    //             break;
    //         }
    //     }
    //     dp[0][j] = allStars ? 1 : 0;
    // }
    //     for(int i = 1; i <= str.size(); i++){
    //         for(int j = 1; j <= pattern.size(); j++){
    //             bool isMatch = false;
    //         if(str[i - 1] == pattern[j - 1] || pattern[j - 1] == '?') isMatch = dp[i - 1][j - 1];
    //         else if(pattern[j - 1] == '*'){
    //             isMatch = (dp[i - 1][j] || dp[i][j - 1]);
    //         }
    //         else isMatch = false;
    //          dp[i][j] = isMatch;
    //         }
    //     }
    //     return dp[str.length()][pattern.length()];
    //      }
    bool solveSO(string &str, string &pattern)
    { // - Space Optimized
        vector<int> prev(pattern.size() + 1, 0);
        vector<int> curr(pattern.size() + 1, 0);

        prev[0] = 1;

        for (int j = 1; j <= pattern.length(); j++)
        {
            bool allStars = true;
            for (int k = 0; k < j; k++)
            {
                if (pattern[k] != '*')
                {
                    allStars = false;
                    break;
                }
            }
            prev[j] = allStars ? 1 : 0;
        }

        for (int i = 1; i <= str.size(); i++)
        {
            curr[0] = 0;
            for (int j = 1; j <= pattern.size(); j++)
            {
                bool isMatch = false;
                if (str[i - 1] == pattern[j - 1] || pattern[j - 1] == '?')
                {
                    isMatch = prev[j - 1];
                }
                else if (pattern[j - 1] == '*')
                {
                    isMatch = prev[j] || curr[j - 1];
                }
                curr[j] = isMatch;
            }
            prev = curr;
        }

        return prev[pattern.length()];
    }

    bool isMatch(string s, string p)
    {
        // return solve(s, p , s.length() - 1, p.length() - 1);
        // vector<vector<int>> dp(s.length() + 1, vector<int> (p.length() + 1, -1));
        // return solveMem(s, p , s.length(), p.length(), dp);
        // return solveTab(s, p);
        return solveSO(s, p);
    }
};
