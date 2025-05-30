// Leetcode Problem No : 279 - Perfect Square(Medium)

/*
Given an integer n, return the least number of perfect square numbers that sum to n.

A perfect square is an integer that is the square of an integer; in other words, it is the product of some integer with itself. For example, 1, 4, 9, and 16 are perfect squares while 3 and 11 are not.



Example 1:

Input: n = 12
Output: 3
Explanation: 12 = 4 + 4 + 4.
Example 2:

Input: n = 13
Output: 2
Explanation: 13 = 4 + 9.


Constraints:

1 <= n <= 104
*/

#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

class Solution
{
public:
    // int solveMemo(int n, vector<int> &dp){
    //     if(n == 0) return 0;
    //     int ans = n;
    //     if(dp[n] != -1) return dp[n];
    //     for(int i = 1; i * i <= n; i++){
    //         ans = min(ans, solve(n - i*i, dp) + 1);
    //     }
    //     dp[n] = ans;
    //     return dp[n];
    // }
    int solveTab(int n)
    {
        vector<int> dp(n + 1, INT_MAX);
        dp[0] = 0;

        for (int target = 1; target <= n; ++target)
        {
            for (int j = 1; j * j <= target; ++j)
            {
                int square = j * j;
                if (target - square >= 0)
                    dp[target] = min(dp[target], 1 + dp[target - square]);
            }
        }

        return dp[n];
    }
    int numSquares(int n)
    {
        return solveTab(n);
    }
};