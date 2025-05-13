// GfG Problem - 0/1 Knapsack Problem (Medium)

/*
Given n items, each with a specific weight and value, and a knapsack with a capacity of W, the task is to put the items in the knapsack such that the sum of weights of the items <= W and the sum of values associated with them is maximized.

Note: You can either place an item entirely in the bag or leave it out entirely. Also, each item is available in single quantity.

Examples :

Input: W = 4, val[] = [1, 2, 3], wt[] = [4, 5, 1]
Output: 3
Explanation: Choose the last item, which weighs 1 unit and has a value of 3.
Input: W = 3, val[] = [1, 2, 3], wt[] = [4, 5, 6]
Output: 0
Explanation: Every item has a weight exceeding the knapsack's capacity (3).
Input: W = 5, val[] = [10, 40, 30, 50], wt[] = [5, 4, 2, 3]
Output: 80
Explanation: Choose the third item (value 30, weight 2) and the last item (value 50, weight 3) for a total value of 80.
Constraints:
2 ≤ val.size() = wt.size() ≤ 103
1 ≤ W ≤ 103
1 ≤ val[i] ≤ 103
1 ≤ wt[i] ≤ 103
*/

#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

class Solution
{
public:
    // int solve(int W,vector<int> &val, vector<int> &wt, int index){  - Recursive Approach
    //     if(index == 0){
    //         if(wt[0] <= W) return val[0];
    //         else return 0;
    //     }
    //     int include = 0;

    //     if(wt[index] <= W)
    //         include = val[index] + solve(W - wt[index], val, wt, index - 1);
    //     int exclude = solve(W, val, wt, index - 1);
    //     int ans = max(include, exclude);
    //     return ans;

    // }

    // int solveMem(int W,vector<int> &val, vector<int> &wt, int index, vector<vector<int> >&dp){
    //   if(index == 0){                                                         - Top Down DP Approach
    //         if(wt[0] <= W) return val[0];
    //         else return 0;
    //     }
    //     if(dp[index][W] != -1) return dp[index][W];
    //     int include = 0;

    //     if(wt[index] <= W)
    //         include = val[index] + solveMem(W - wt[index], val, wt, index - 1, dp);
    //     int exclude = solveMem(W, val, wt, index - 1, dp);
    //     dp[index][W] = max(include, exclude);
    //     return dp[index][W];
    // }

    // int solveTab(int W, vector<int> &val, vector<int> &wt, int n)
    // {
    //     vector<vector<int>> dp(n, vector<int>(W + 1, 0));  Bottom Up DP Approach

    //     for (int w = wt[0]; w <= W; w++)
    //     {
    //         dp[0][w] = val[0];
    //     }

    //     for (int i = 1; i < n; i++)
    //     {
    //         for (int w = 0; w <= W; w++)
    //         {
    //             int include = 0;
    //             if (wt[i] <= w)
    //                 include = val[i] + dp[i - 1][w - wt[i]];
    //             int exclude = dp[i - 1][w];
    //             dp[i][w] = max(include, exclude);
    //         }
    //     }

    //     return dp[n - 1][W];
    // }

    int solveSO(int W, vector<int> &val, vector<int> &wt, int n)
    {
        vector<int> prev(W + 1, 0);

        for (int w = wt[0]; w <= W; w++) //- Space Optimized Approach
        {
            prev[w] = val[0];
        }

        for (int i = 1; i < n; i++)
        {
            vector<int> curr(W + 1, 0);
            for (int w = 0; w <= W; w++)
            {
                int include = 0;
                if (wt[i] <= w)
                    include = val[i] + prev[w - wt[i]];
                int exclude = prev[w];
                curr[w] = max(include, exclude);
            }
            prev = curr;
        }

        return prev[W];
    }
    int knapsack(int W, vector<int> &val, vector<int> &wt)
    {
        return solveSO(W, val, wt, val.size());
    }
};
