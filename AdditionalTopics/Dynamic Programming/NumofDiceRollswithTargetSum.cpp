// Leetcode Problem No : 1155 - Number of Dice Rolls with Target Sum(Medium)

/*
You have n dice, and each dice has k faces numbered from 1 to k.

Given three integers n, k, and target, return the number of possible ways (out of the kn total ways) to roll the dice, so the sum of the face-up numbers equals target. Since the answer may be too large, return it modulo 109 + 7.



Example 1:

Input: n = 1, k = 6, target = 3
Output: 1
Explanation: You throw one die with 6 faces.
There is only one way to get a sum of 3.
Example 2:

Input: n = 2, k = 6, target = 7
Output: 6
Explanation: You throw two dice, each with 6 faces.
There are 6 ways to get a sum of 7: 1+6, 2+5, 3+4, 4+3, 5+2, 6+1.
Example 3:

Input: n = 30, k = 30, target = 500
Output: 222616187
Explanation: The answer must be returned modulo 109 + 7.


Constraints:

1 <= n, k <= 30
1 <= target <= 1000
*/

#include <iostream>
#include <vector>

using namespace std;

class Solution
{
public:
    const int MOD = 1e9 + 7;
    // int solve(int dice, int faces, int target){ - Recursive Sol
    //     if(target <= 0 || (dice == 0 && target != 0) || (target == 0 && dice != 0)) return 0;
    //     if(target == 0 && dice == 0) return 1;
    //     int ans = 0;
    //     for(int i = 1; i <= faces; i++){
    //         ans = ans + solve(dice - 1, faces, target - i);
    //     }
    //     return ans;
    // }

    // int solveMemo(int dice, int faces, int target, vector<vector<int>>& dp) { - Top Down DP

    //     if (target < 0) return 0;

    //     if (dice == 0 && target == 0) return 1;

    //     if (dice == 0 || target == 0) return 0;

    //     if (dp[dice][target] != -1) return dp[dice][target];

    //     int ans = 0;
    //     for (int i = 1; i <= faces; i++) {
    //         if (target - i >= 0) {
    //             ans = (ans + solveMemo(dice - 1, faces, target - i, dp)) % MOD;
    //         }
    //     }

    //     dp[dice][target] = ans;
    //     return ans;
    // }
    // int solveTab(int d, int f, int t){ - Bottom Up DP
    //     vector<vector<int> > dp(d + 1, vector<int>(t + 1, 0));

    //     dp[0][0] = 1;

    //     for(int dice = 1; dice <= d; dice++){
    //         for(int target = 1; target <= t; target++){
    //             int ans = 0;
    //             for (int i = 1; i <= f; i++) {
    //                 if (target - i >= 0) {
    //                     ans = (ans + dp[dice - 1][target - i]) % MOD;
    //                 }
    //             }

    //             dp[dice][target] = ans;
    //         }
    //     }
    //     return dp[d][t];
    // }
    int solveSO(int d, int f, int t)
    { // - Space Optimized
        vector<int> curr(t + 1, 0);
        vector<int> prev(t + 1, 0);

        prev[0] = 1;

        for (int dice = 1; dice <= d; dice++)
        {
            for (int target = 1; target <= t; target++)
            {
                int ans = 0;
                for (int i = 1; i <= f; i++)
                {
                    if (target - i >= 0)
                    {
                        ans = (ans + prev[target - i]) % MOD;
                    }
                }

                curr[target] = ans;
            }
            prev = curr;
        }
        return curr[t];
    }

    int numRollsToTarget(int n, int k, int target)
    {
        // return solve(n, k, target);
        // vector<vector<int>> dp(n+1, vector<int>(target + 1, -1));
        // return solveMemo(n, k, target, dp);
        // return solveTab(n, k, target);
        return solveSO(n, k, target);
    }
};