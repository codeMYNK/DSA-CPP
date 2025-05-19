// Leetcode Problem No - 122 : Best Time to Buy and Sell Stocks - II (Medium)

/*
You are given an integer array prices where prices[i] is the price of a given stock on the ith day.

On each day, you may decide to buy and/or sell the stock. You can only hold at most one share of the stock at any time. However, you can buy it then immediately sell it on the same day.

Find and return the maximum profit you can achieve.



Example 1:

Input: prices = [7,1,5,3,6,4]
Output: 7
Explanation: Buy on day 2 (price = 1) and sell on day 3 (price = 5), profit = 5-1 = 4.
Then buy on day 4 (price = 3) and sell on day 5 (price = 6), profit = 6-3 = 3.
Total profit is 4 + 3 = 7.
Example 2:

Input: prices = [1,2,3,4,5]
Output: 4
Explanation: Buy on day 1 (price = 1) and sell on day 5 (price = 5), profit = 5-1 = 4.
Total profit is 4.
Example 3:

Input: prices = [7,6,4,3,1]
Output: 0
Explanation: There is no way to make a positive profit, so we never buy the stock to achieve the maximum profit of 0.


Constraints:

1 <= prices.length <= 3 * 104
0 <= prices[i] <= 104
*/

#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

class Solution
{
public:
    // int solve(vector<int>& prices, int index, int buy){ - Recursive Solution
    //     if(index == prices.size()) return 0;
    //     int profit = 0;
    //     if(buy){
    //         profit = max((-prices[index] + solve(prices, index + 1, 0)), (solve(prices, index + 1, 1)));
    //     }else{
    //         profit = max((prices[index] + solve(prices, index + 1, 1)), (solve(prices,index + 1, 0)));
    //     }
    //     return profit;
    // }
    // int solveMem(vector<int>& prices, int index, int buy, vector<vector<int>> &dp){ - Top Down DP
    //     if(index == prices.size()) return 0;
    //     if(dp[index][buy] != -1) return dp[index][buy];
    //     int profit = 0;
    //     if(buy){
    //         profit = max((-prices[index] + solveMem(prices, index + 1, 0,dp)), (solveMem(prices, index + 1, 1, dp)));
    //     }else{
    //         profit = max((prices[index] + solveMem(prices, index + 1, 1, dp)), (solveMem(prices,index + 1, 0, dp)));
    //     }
    //     return dp[index][buy] = profit;
    // }
    //     int solveTab(vector<int> &prices){ - Bottom Up DP
    //     vector<vector<int>> dp(prices.size() + 1, vector<int> (2, 0));

    //     for(int index = prices.size() - 1; index >= 0; index--){
    //         for(int buy = 0; buy <= 1; buy++){
    //             int profit = 0;
    //             if(buy){
    //                 profit = max(-prices[index] + dp[index + 1][0], dp[index + 1][1]);
    //             }else{
    //                 profit = max(prices[index] + dp[index + 1][1], dp[index + 1][0]);
    //             }
    //             dp[index][buy] = profit;
    //         }
    //     }

    //     return dp[0][1];
    // }
    int solveSO(vector<int> &prices)
    { //- Space Optimized Solution
        vector<int> curr(2, 0);
        vector<int> next(2, 0);

        for (int index = prices.size() - 1; index >= 0; index--)
        {
            for (int buy = 0; buy <= 1; buy++)
            {
                int profit = 0;
                if (buy)
                {
                    profit = max(-prices[index] + next[0], next[1]);
                }
                else
                {
                    profit = max(prices[index] + next[1], next[0]);
                }
                curr[buy] = profit;
            }
            next = curr;
        }

        return curr[1];
    }
    int maxProfit(vector<int> &prices)
    {
        // return solve(prices, 0, 1);
        // vector<vector<int>> dp(prices.size() + 1, vector<int>(2, -1));
        // return solveMem(prices, 0 , 1, dp);
        // return solveTab(prices);
        return solveSO(prices);
    }
};