// Leetcode Problem No : 123 - Best Time to Buy and Sell Stocks III (Hard)

/*
You are given an array prices where prices[i] is the price of a given stock on the ith day.

Find the maximum profit you can achieve. You may complete at most two transactions.

Note: You may not engage in multiple transactions simultaneously (i.e., you must sell the stock before you buy again).



Example 1:

Input: prices = [3,3,5,0,0,3,1,4]
Output: 6
Explanation: Buy on day 4 (price = 0) and sell on day 6 (price = 3), profit = 3-0 = 3.
Then buy on day 7 (price = 1) and sell on day 8 (price = 4), profit = 4-1 = 3.
Example 2:

Input: prices = [1,2,3,4,5]
Output: 4
Explanation: Buy on day 1 (price = 1) and sell on day 5 (price = 5), profit = 5-1 = 4.
Note that you cannot buy on day 1, buy on day 2 and sell them later, as you are engaging multiple transactions at the same time. You must sell before buying again.
Example 3:

Input: prices = [7,6,4,3,1]
Output: 0
Explanation: In this case, no transaction is done, i.e. max profit = 0.


Constraints:

1 <= prices.length <= 105
0 <= prices[i] <= 105
*/

#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

class Solution
{
public:
    // int solve(vector<int>& prices, int index, int buy, int limit){ - Recursive Approach
    //      if(index == prices.size()) return 0;
    //      if(limit == 0) return 0;
    //      int profit = 0;
    //      if(buy){
    //          profit = max((-prices[index] + solve(prices, index + 1, 0, limit)), (solve(prices, index + 1, 1, limit)));
    //      }else{
    //          profit = max((prices[index] + solve(prices, index + 1, 1, limit - 1)), (solve(prices,index + 1, 0, limit)));
    //      }
    //      return profit;
    //  }
    //  int solveMem(vector<int>& prices, int index, int buy, int limit, vector<vector<vector<int>>> &dp){ - Top Down DP
    //      if(index == prices.size()) return 0;
    //      if(limit == 0) return 0;

    //      if(dp[index][buy][limit] != -1) return dp[index][buy][limit];
    //      int profit = 0;
    //      if(buy){
    //          profit = max((-prices[index] + solveMem(prices, index + 1, 0, limit, dp)), (solveMem(prices, index + 1, 1, limit, dp)));
    //      }else{
    //          profit = max((prices[index] + solveMem(prices, index + 1, 1, limit - 1, dp)), (solveMem(prices,index + 1, 0, limit, dp)));
    //      }
    //      return dp[index][buy][limit] = profit;
    //  }
    //      int solveTab(vector<int> &prices){ - Bottom Up DP
    //     vector<vector<vector<int>>> dp(prices.size() + 1, vector<vector<int>>(2, vector<int>(3, 0)));

    //     for(int index = prices.size() - 1; index >= 0; index--){
    //         for(int buy = 0; buy <= 1; buy++){
    //             for(int limit = 1; limit < 3; limit++){
    //                 int profit = 0;
    //                 if(buy){
    //                     profit = max(-prices[index] + dp[index + 1][0][limit], dp[index + 1][1][limit]);
    //                 }else{
    //                     profit = max(prices[index] + dp[index + 1][1][limit - 1], dp[index + 1][0][limit]);
    //                 }
    //                 dp[index][buy][limit] = profit;
    //             }
    //         }
    //     }
    //     return dp[0][1][2];
    // }
    int solveSO(vector<int> &prices)
    { //- Space Optimized
        vector<vector<int>> curr(2, vector<int>(3, 0));
        vector<vector<int>> next(2, vector<int>(3, 0));

        for (int index = prices.size() - 1; index >= 0; index--)
        {
            for (int buy = 0; buy <= 1; buy++)
            {
                for (int limit = 1; limit < 3; limit++)
                {
                    int profit = 0;
                    if (buy)
                    {
                        profit = max(-prices[index] + next[0][limit], next[1][limit]);
                    }
                    else
                    {
                        profit = max(prices[index] + next[1][limit - 1], next[0][limit]);
                    }
                    curr[buy][limit] = profit;
                }
            }
            next = curr;
        }
        return curr[1][2];
    }
    int maxProfit(vector<int> &prices)
    {
        // return solve(prices, 0, 1, 2);
        // vector<vector<vector<int>>> dp(prices.size() + 1, vector<vector<int>> (2, vector<int>(3, -1)));
        // return solveMem(prices, 0, 1, 2, dp);
        // return solveTab(prices);
        return solveSO(prices);
    }
};