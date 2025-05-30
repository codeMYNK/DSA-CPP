// Leetcode Problem No 322 : Coin Change (Medium)

/*
You are given an integer array coins representing coins of different denominations and an integer amount representing a total amount of money.

Return the fewest number of coins that you need to make up that amount. If that amount of money cannot be made up by any combination of the coins, return -1.

You may assume that you have an infinite number of each kind of coin.



Example 1:

Input: coins = [1,2,5], amount = 11
Output: 3
Explanation: 11 = 5 + 5 + 1
Example 2:

Input: coins = [2], amount = 3
Output: -1
Example 3:

Input: coins = [1], amount = 0
Output: 0


Constraints:

1 <= coins.length <= 12
1 <= coins[i] <= 231 - 1
0 <= amount <= 104
*/

#include <iostream>
#include <vector>
#include <climits>

using namespace std;

class Solution
{
public:
    int solve(vector<int> &coins, int amount, vector<int> &dp)
    {
        if (amount == 0)
            return 0;
        if (amount < 0)
            return INT_MAX;

        if (dp[amount] != -1)
            return dp[amount];

        int mini = INT_MAX;
        for (int i = 0; i < coins.size(); i++)
        {
            int ans = solve(coins, amount - coins[i], dp);
            if (ans != INT_MAX)
            {
                mini = min(ans + 1, mini);
            }
        }
        return dp[amount] = mini;
    }

    int coinChange(vector<int> &coins, int amount)
    {
        vector<int> dp(amount + 1, -1);
        int ans = solve(coins, amount, dp);
        return (ans == INT_MAX) ? -1 : ans;
    }
};
