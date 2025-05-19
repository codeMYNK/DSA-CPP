// Leetcode Problem No : 76 - Edit Distance(Medium)

/*
Given two strings word1 and word2, return the minimum number of operations required to convert word1 to word2.

You have the following three operations permitted on a word:

Insert a character
Delete a character
Replace a character


Example 1:

Input: word1 = "horse", word2 = "ros"
Output: 3
Explanation:
horse -> rorse (replace 'h' with 'r')
rorse -> rose (remove 'r')
rose -> ros (remove 'e')
Example 2:

Input: word1 = "intention", word2 = "execution"
Output: 5
Explanation:
intention -> inention (remove 't')
inention -> enention (replace 'i' with 'e')
enention -> exention (replace 'n' with 'x')
exention -> exection (replace 'n' with 'c')
exection -> execution (insert 'u')


Constraints:

0 <= word1.length, word2.length <= 500
word1 and word2 consist of lowercase English letters.
*/

#include <iostream>
#include <string.h>
#include <vector>
#include <algorithm>

using namespace std;

class Solution
{
public:
    // int solve(string &a, string &b, int i, int j){ - Recursive Approach
    //     if(i == a.length()) return b.length() - j;
    //     if(j == b.length()) return a.length() - i;

    //     int ans = 0;
    //     if(a[i] == b[j]){
    //         ans = solve(a, b, i + 1, j + 1);
    //     }else{
    //         int insertAns = 1 + solve(a, b, i, j + 1);
    //         int deleteAns = 1 + solve(a, b, i + 1, j);
    //         int replaceAns = 1 + solve(a, b, i + 1, j + 1);
    //        ans =  min(insertAns, min(deleteAns, replaceAns));
    //     }
    //     return ans;
    // }
    // int solveMem(string &a, string &b, int i, int j, vector<vector<int>> &dp){ - Top Down DP
    //     if(i == a.length()) return b.length() - j;
    //     if(j == b.length()) return a.length() - i;
    //     if(dp[i][j] != -1) return dp[i][j];

    //     int ans = 0;
    //     if(a[i] == b[j]){
    //         ans = solveMem(a, b, i + 1, j + 1, dp);
    //     }else{
    //         int insertAns = 1 + solveMem(a, b, i, j + 1,dp);
    //         int deleteAns = 1 + solveMem(a, b, i + 1, j, dp);
    //         int replaceAns = 1 + solveMem(a, b, i + 1, j + 1, dp);
    //        ans =  min(insertAns, min(deleteAns, replaceAns));
    //     }
    //     return dp[i][j] = ans;
    // }
    // int solveTab(string &a, string &b){ - Bottom Up DP
    //     vector<vector<int>> dp(a.length() + 1, vector<int>(b.length() + 1, 0));
    //     for(int j = 0; j < b.length(); j++){
    //         dp[a.length()][j] = b.length() - j;
    //     }
    //     for(int i = 0; i < a.length(); i++){
    //         dp[i][b.length()] = a.length() - i;
    //     }

    //     for(int i = a.length() - 1; i >= 0; i--){
    //         for(int j = b.length() - 1; j >= 0; j--){
    //             int ans = 0;
    //     if(a[i] == b[j]){
    //         ans = dp[i + 1][j + 1];
    //     }else{
    //         int insertAns = 1 + dp[i][j + 1];
    //         int deleteAns = 1 + dp[i + 1][j];
    //         int replaceAns = 1 + dp[i + 1][j + 1];
    //        ans =  min(insertAns, min(deleteAns, replaceAns));
    //     }
    //      dp[i][j] = ans;
    //         }
    //     }
    //     return dp[0][0];
    // }
    int solveSO(string &a, string &b)
    { // - Space Optimized
        if (a.length() == 0)
            return b.length();
        if (b.length() == 0)
            return a.length();
        vector<int> curr(b.length() + 1, 0);
        vector<int> next(b.length() + 1, 0);

        for (int j = 0; j <= b.length(); j++)
        {
            next[j] = b.length() - j;
        }

        for (int i = a.length() - 1; i >= 0; i--)
        {
            curr[b.length()] = a.length() - i;

            for (int j = b.length() - 1; j >= 0; j--)
            {
                if (a[i] == b[j])
                {
                    curr[j] = next[j + 1];
                }
                else
                {
                    int insertOp = 1 + curr[j + 1];
                    int deleteOp = 1 + next[j];
                    int replaceOp = 1 + next[j + 1];
                    curr[j] = min({insertOp, deleteOp, replaceOp});
                }
            }
            next = curr;
        }

        return curr[0];
    }
    int minDistance(string word1, string word2)
    {
        // return solve(word1, word2, 0 ,0);
        // vector<vector<int>> dp(word1.length(), vector<int>(word2.length(), -1));
        // return solveMem(word1, word2, 0, 0, dp);
        // return solveTab(word1, word2);
        return solveSO(word1, word2);
    }
};