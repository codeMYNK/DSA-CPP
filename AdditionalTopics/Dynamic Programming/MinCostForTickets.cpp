// Leetcode Problem No : 983 - Minimum Cost For Tickets(Medium)

/*
You have planned some train traveling one year in advance. The days of the year in which you will travel are given as an integer array days. Each day is an integer from 1 to 365.

Train tickets are sold in three different ways:

a 1-day pass is sold for costs[0] dollars,
a 7-day pass is sold for costs[1] dollars, and
a 30-day pass is sold for costs[2] dollars.
The passes allow that many days of consecutive travel.

For example, if we get a 7-day pass on day 2, then we can travel for 7 days: 2, 3, 4, 5, 6, 7, and 8.
Return the minimum number of dollars you need to travel every day in the given list of days.



Example 1:

Input: days = [1,4,6,7,8,20], costs = [2,7,15]
Output: 11
Explanation: For example, here is one way to buy passes that lets you travel your travel plan:
On day 1, you bought a 1-day pass for costs[0] = $2, which covered day 1.
On day 3, you bought a 7-day pass for costs[1] = $7, which covered days 3, 4, ..., 9.
On day 20, you bought a 1-day pass for costs[0] = $2, which covered day 20.
In total, you spent $11 and covered all the days of your travel.
Example 2:

Input: days = [1,2,3,4,5,6,7,8,9,10,30,31], costs = [2,7,15]
Output: 17
Explanation: For example, here is one way to buy passes that lets you travel your travel plan:
On day 1, you bought a 30-day pass for costs[2] = $15 which covered days 1, 2, ..., 30.
On day 31, you bought a 1-day pass for costs[0] = $2 which covered day 31.
In total, you spent $17 and covered all the days of your travel.


Constraints:

1 <= days.length <= 365
1 <= days[i] <= 365
days is in strictly increasing order.
costs.length == 3
1 <= costs[i] <= 1000
*/

#include <iostream>
#include <algorithm>
#include <limits.h>
#include <vector>
#include <queue>

using namespace std;

class Solution
{
public:
    // int solve(vector<int> &days, vector<int> &costs, int index, vector<int> &dp){ - Top Down DP
    //     if(index >= days.size()){
    //         return 0;
    //     }

    //     if(dp[index] != -1) return dp[index];

    //     //1 Day
    //     int op1 = costs[0] + solve(days, costs, index + 1, dp);

    //     //7 Day
    //     int i;
    //     for( i = index; i < days.size() && days[i] < days[index] + 7; i++);
    //     int op7 = costs[1]  + solve(days, costs, i, dp);

    //     //30 Day
    //     for(i = index; i < days.size() && days[i] < days[index] + 30; i++);
    //     int op30 = costs[2] + solve(days,costs, i, dp);

    //     dp[index] = min(op1, min(op7, op30));
    //     return dp[index];
    // }
    //  int solveTab(vector<int>& days, vector<int> &costs){ - Bottom Up DP
    //      int n = days.size();
    //      vector<int> dp(days.size() + 1, INT_MAX);
    //      dp[n] = 0;

    //     for(int k = n - 1; k >= 0; k--){
    //     //1 Day
    //     int op1 = costs[0] + dp[k + 1];

    //     //7 Day
    //     int i;
    //     for( i = k; i < days.size() && days[i] < days[k] + 7; i++);
    //     int op7 = costs[1]  + dp[i];

    //     //30 Day
    //     for(i = k; i < days.size() && days[i] < days[k] + 30; i++);
    //     int op30 = costs[2] + dp[i];

    //     dp[k] = min(op1, min(op7, op30));
    //      }
    //      return dp[0];
    //  }

    int solveSO(vector<int> &days, vector<int> &costs) // Space Optimization
    {
        int ans = 0;
        queue<pair<int, int>> week;
        queue<pair<int, int>> month;

        for (int day : days)
        {
            while (!month.empty() && month.front().first + 30 <= day)
                month.pop();

            while (!week.empty() && week.front().first + 7 <= day)
                week.pop();

            week.push(make_pair(day, ans + costs[1]));
            month.push(make_pair(day, ans + costs[2]));
            ans = min(ans + costs[0], min(week.front().second, month.front().second));
        }
        return ans;
    }
    int mincostTickets(vector<int> &days, vector<int> &costs)
    {
        // vector<int> dp(days.size() + 1, -1);
        // return solve(days, costs, 0, dp);
        // return solveTab(days, costs);
        return solveSO(days, costs);
    }
};