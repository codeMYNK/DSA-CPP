// Leetcode Problem No : 96 - Unique Binary Search Trees(Medium)

/*
Given an integer n, return the number of structurally unique BST's (binary search trees) which has exactly n nodes of unique values from 1 to n.



Example 1:


Input: n = 3
Output: 5
Example 2:

Input: n = 1
Output: 1


Constraints:

1 <= n <= 19
*/

#include <iostream>
#include <vector>

using namespace std;

class Solution
{
public:
    // int solve(int n){ - Recursive Approach
    //     if(n <= 1) return 1;

    //     int ans = 0;
    //     for(int i = 1; i <= n; i++){
    //         ans += numTrees(i - 1) * numTrees(n - i);
    //     }
    //     return ans;
    // }
    int solveMemo(int n, vector<int> &dp)
    { //- Top Down DP
        if (n <= 1)
            return 1;
        if (dp[n] != -1)
            return dp[n];
        int ans = 0;
        for (int i = 1; i <= n; i++)
        {
            ans += solveMemo(i - 1, dp) * solveMemo(n - i, dp);
        }
        return dp[n] = ans;
    }
    // int solveTab(int n){ - Bottom Up DP
    //     vector<int> dp(n + 1, 0);
    //     dp[0] = dp[1] = 1;
    //     for(int i = 2; i <= n; i++){
    //         for(int j = 1; j <= i; j++){
    //             dp[i] += dp[j - 1]*dp[i - j];
    //         }
    //     }
    //     return dp[n];
    // }
    // int solveSO(int n){ - Space Optimized(Catalan Series)
    //     if(n <= 1) return 1;
    //     int ans = 0;
    //     for(int i = 0; i < n; i++){
    //         ans += solveSO(i) * solveSO(n - i - 1);
    //     }
    //     return ans;
    // }
    int numTrees(int n)
    {
        // return solve(n);
        vector<int> dp(n + 1, -1);
        return solveMemo(n, dp);
        // return solveTab(n);
        // return solveSO(n);
    }
};