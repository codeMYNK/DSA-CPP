// Leetcode Problem No : 188 - Best Time to Buy and Sell Stocks - IV (Hard)

/*
You are given an integer array prices where prices[i] is the price of a given stock on the ith day, and an integer k.

Find the maximum profit you can achieve. You may complete at most k transactions: i.e. you may buy at most k times and sell at most k times.

Note: You may not engage in multiple transactions simultaneously (i.e., you must sell the stock before you buy again).



Example 1:

Input: k = 2, prices = [2,4,1]
Output: 2
Explanation: Buy on day 1 (price = 2) and sell on day 2 (price = 4), profit = 4-2 = 2.
Example 2:

Input: k = 2, prices = [3,2,6,5,0,3]
Output: 7
Explanation: Buy on day 2 (price = 2) and sell on day 3 (price = 6), profit = 6-2 = 4. Then buy on day 5 (price = 0) and sell on day 6 (price = 3), profit = 3-0 = 3.


Constraints:

1 <= k <= 100
1 <= prices.length <= 1000
0 <= prices[i] <= 1000

*/

#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

class Solution
{
public:
    // int solveSO(vector<int> &prices, int k)
    // {  - Part 3 sol with modifications
    //     vector<vector<int>> curr(2, vector<int>(k + 1, 0));
    //     vector<vector<int>> next(2, vector<int>(k + 1, 0));

    //     for (int index = prices.size() - 1; index >= 0; index--)
    //     {
    //         for (int buy = 0; buy <= 1; buy++)
    //         {
    //             for (int limit = 1; limit <= k; limit++)
    //             {
    //                 int profit = 0;
    //                 if (buy)
    //                 {
    //                     profit = max(-prices[index] + next[0][limit], next[1][limit]);
    //                 }
    //                 else
    //                 {
    //                     profit = max(prices[index] + next[1][limit - 1], next[0][limit]);
    //                 }
    //                 curr[buy][limit] = profit;
    //             }
    //         }
    //         next = curr;
    //     }
    //     return curr[1][k];
    // }
    // int solve(int index, int operationNo, int k, vector<int> &prices){ - Recursive solution
    //     if(index == prices.size()) return 0;
    //     if(operationNo == 2 * k) return 0;

    //     int profit = 0;
    //     if(operationNo % 2 == 0){
    //         profit = max((-prices[index] + solve(index + 1, operationNo + 1, k , prices)),(solve(index + 1, operationNo, k , prices)));
    //     }else{
    //         profit = max((prices[index] + solve(index + 1, operationNo + 1, k, prices)), (solve(index + 1, operationNo, k, prices)));
    //     }
    //     return profit;
    // }
    // int solveMem(int index, int operationNo, int k, vector<int> &prices, vector<vector<int>> &dp){ - Top Down DP
    //     if(index == prices.size()) return 0;
    //     if(operationNo == 2 * k) return 0;

    //     if(dp[index][operationNo] != -1) return dp[index][operationNo];

    //     int profit = 0;
    //     if(operationNo % 2 == 0){
    //         profit = max((-prices[index] + solveMem(index + 1, operationNo + 1, k , prices,dp)),(solveMem(index + 1, operationNo, k , prices, dp)));
    //     }else{
    //         profit = max((prices[index] + solveMem(index + 1, operationNo + 1, k, prices, dp)), (solveMem(index + 1, operationNo, k, prices, dp)));
    //     }
    //     return dp[index][operationNo] = profit;
    // }
    // int solveTab(int k, vector<int> &prices){ - Bottom Up DP
    //     vector<vector<int>> dp(prices.size() + 1, vector<int>(2*k + 1, 0));

    //     for(int index = prices.size() - 1; index >= 0; index--){
    //         for(int operationNo = 2 * k - 1; operationNo >= 0; operationNo--){
    //             int profit = 0;
    //     if(operationNo % 2 == 0){
    //         profit = max(-prices[index] + dp[index + 1][operationNo + 1],dp[index + 1][operationNo]);
    //     }else{
    //         profit = max(prices[index] + dp[index + 1][operationNo + 1], dp[index + 1][operationNo]);
    //     }
    //         dp[index][operationNo] = profit;
    //         }
    //     }
    //     return dp[0][0];
    // }
    int solveSO(int k, vector<int> &prices)
    { //- Space Optimized
        vector<int> curr(2 * k + 1, 0);
        vector<int> next(2 * k + 1, 0);
        for (int index = prices.size() - 1; index >= 0; index--)
        {
            for (int operationNo = 2 * k - 1; operationNo >= 0; operationNo--)
            {
                int profit = 0;
                if (operationNo % 2 == 0)
                {
                    profit = max(-prices[index] + next[operationNo + 1], next[operationNo]);
                }
                else
                {
                    profit = max(prices[index] + next[operationNo + 1], next[operationNo]);
                }
                curr[operationNo] = profit;
            }
            next = curr;
        }
        return curr[0];
    }
    int maxProfit(int k, vector<int> &prices)
    {
        // return solveSO(prices, k);
        // return solve(0, 0, k, prices);
        // vector<vector<int>> dp(prices.size(), vector<int>(2 * k, -1));
        // return solveMem(0,0,k,prices,dp);
        // return solveTab(k, prices);
        return solveSO(k, prices);
    }
};