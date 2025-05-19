// Leetcode Problem No : 1143 - Longest Common Subsequence (Medium)

/*
Given two strings text1 and text2, return the length of their longest common subsequence. If there is no common subsequence, return 0.

A subsequence of a string is a new string generated from the original string with some characters (can be none) deleted without changing the relative order of the remaining characters.

For example, "ace" is a subsequence of "abcde".
A common subsequence of two strings is a subsequence that is common to both strings.



Example 1:

Input: text1 = "abcde", text2 = "ace"
Output: 3
Explanation: The longest common subsequence is "ace" and its length is 3.
Example 2:

Input: text1 = "abc", text2 = "abc"
Output: 3
Explanation: The longest common subsequence is "abc" and its length is 3.
Example 3:

Input: text1 = "abc", text2 = "def"
Output: 0
Explanation: There is no such common subsequence, so the result is 0.


Constraints:

1 <= text1.length, text2.length <= 1000
text1 and text2 consist of only lowercase English characters.
*/

#include <iostream>
#include <vector>
#include <algorithm>
#include <string.h>

using namespace std;

class Solution
{
public:
    // int solve(string& a, string &b, int i, int j){ - Recursive Sol
    //     if(i == a.length() || j == b.length()) return 0;
    //     int ans = 0;
    //     if(a[i] == b[j]){
    //         ans = 1 + solve(a, b, i + 1, j + 1);
    //     }else{
    //         ans = max(solve(a, b, i + 1, j), solve(a, b, i, j + 1));
    //     }
    //     return ans;
    // }
    // int solveMem(string& a, string &b, int i, int j, vector<vector<int>> &dp){ - Top Down DP
    //     if(i == a.length() || j == b.length()) return 0;
    //     if(dp[i][j] != -1) return dp[i][j];
    //     int ans = 0;
    //     if(a[i] == b[j]){
    //         ans = 1 + solveMem(a, b, i + 1, j + 1, dp);
    //     }else{
    //         ans = max(solveMem(a, b, i + 1, j, dp), solveMem(a, b, i, j + 1, dp));
    //     }
    //     return dp[i][j] = ans;
    // }
    // int solveTab(string &a, string &b){ - Bottom Up DP
    //     vector<vector<int>> dp(a.length() + 1, vector<int>(b.length() + 1, 0));
    //     for(int i = a.length() - 1; i >= 0; i--){
    //         for(int j = b.length() - 1; j >= 0; j--){
    //             int ans = 0;
    //     if(a[i] == b[j]){
    //         ans = 1 + dp[i + 1][j + 1];
    //     }else{
    //         ans = max(dp[i + 1][j], dp[i][j + 1]);
    //     }
    //      dp[i][j] = ans;
    //         }
    //     }
    //     return dp[0][0];
    // }
    int solveSO(string &a, string &b)
    { //- Space Optimized sol
        vector<int> curr(b.length() + 1, 0);
        vector<int> next(b.length() + 1, 0);

        for (int i = a.length() - 1; i >= 0; i--)
        {
            for (int j = b.length() - 1; j >= 0; j--)
            {
                int ans = 0;
                if (a[i] == b[j])
                {
                    ans = 1 + next[j + 1];
                }
                else
                {
                    ans = max(next[j], curr[j + 1]);
                }
                curr[j] = ans;
            }
            next = curr;
        }
        return curr[0];
    }
    int longestCommonSubsequence(string text1, string text2)
    {
        // return solve(text1, text2, 0, 0);
        // vector<vector<int>> dp(text1.length(), vector<int>(text2.length(), -1));
        // return solveMem(text1, text2, 0, 0, dp);
        // return solveTab(text1, text2);
        return solveSO(text1, text2);
    }
};