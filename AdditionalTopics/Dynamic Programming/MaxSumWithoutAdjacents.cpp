// GfG Problem : Max Sum Without Adjacents (Medium)

/*
Given an array arr containing positive integers. Find the maximum sum of any possible subsequence such that no two numbers in the subsequence should be adjacent in array arr.

Examples:

Input: arr[] = [5, 5, 10, 100, 10, 5]
Output: 110
Explanation: If you take indices 0, 3 and 5, then = 5+100+5 = 110.
Input: arr[] = [3, 2, 7, 10]
Output: 13
Explanation: 3 and 10 forms a non continuous subsequence with maximum sum.
Input: arr[] = [9, 1, 6, 10]
Output: 19
Explanation: 9 and 10 forms a non continuous subsequence with maximum sum.
Constraints:
1 ≤ arr.size() ≤ 105
1 ≤ arri ≤ 105

*/

#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

class Solution
{
public:
    // calculate the maximum sum with out adjacent
    int solve(vector<int> &arr)
    {
        int n = arr.size();
        vector<int> dp(n + 1, 0);

        dp[0] = arr[0];

        for (int i = 1; i < n; i++)
        {
            int incl = dp[i - 2] + arr[i];
            int excl = dp[i - 1];

            dp[i] = max(incl, excl);
        }

        return dp[n - 1];
    }
    int findMaxSum(vector<int> &arr)
    {
        // code here
        return solve(arr);
    }
};