// Leetcode Problem No : 1130 - Minimum Cost Tree from Leaf Values(Medium)

/*
Given an array arr of positive integers, consider all binary trees such that:

Each node has either 0 or 2 children;
The values of arr correspond to the values of each leaf in an in-order traversal of the tree.
The value of each non-leaf node is equal to the product of the largest leaf value in its left and right subtree, respectively.
Among all possible binary trees considered, return the smallest possible sum of the values of each non-leaf node. It is guaranteed this sum fits into a 32-bit integer.

A node is a leaf if and only if it has zero children.



Example 1:


Input: arr = [6,2,4]
Output: 32
Explanation: There are two possible trees shown.
The first has a non-leaf node sum 36, and the second has non-leaf node sum 32.
Example 2:


Input: arr = [4,11]
Output: 44


Constraints:

2 <= arr.length <= 40
1 <= arr[i] <= 15
It is guaranteed that the answer fits into a 32-bit signed integer (i.e., it is less than 231).
*/

#include <iostream>
#include <vector>
#include <map>
#include <algorithm>
#include <limits.h>

using namespace std;

class Solution
{
public:
    // int solve(vector<int>&arr, map<pair<int,int>, int> &maxi, int left, int right){ - Recursive Approach
    //     if(left == right) return 0;

    //     int ans = INT_MAX;
    //     for(int i = left; i < right; i++){
    //         ans = min(ans, maxi[{left, i}] * maxi[{i + 1, right}] + solve(arr, maxi, left, i)) + solve(arr, maxi, i + 1, right);
    //     }
    //     return ans;
    // }
    // int solveMem(vector<int>&arr, map<pair<int,int>, int> &maxi, int left, int right, vector<vector<int>> &dp){ - Top Down DP
    //     if(left == right) return 0;
    //     if(dp[left][right] != -1) return dp[left][right];

    //     int ans = INT_MAX;
    //     for(int i = left; i < right; i++){
    //         ans = min(ans, maxi[{left, i}] * maxi[{i + 1, right}] + solveMem(arr, maxi, left, i, dp) + solveMem(arr, maxi, i + 1, right, dp));
    //     }
    //     return dp[left][right] = ans;
    // }
    int solveTab(vector<int> &arr, map<pair<int, int>, int> &maxi)
    { //-Bottom Up DP
        int n = arr.size();
        vector<vector<int>> dp(n, vector<int>(n, 0));

        for (int length = 2; length <= n; length++)
        {
            for (int left = 0; left <= n - length; left++)
            {
                int right = left + length - 1;
                int ans = INT_MAX;

                for (int i = left; i < right; i++)
                {
                    int cost = maxi[{left, i}] * maxi[{i + 1, right}] + dp[left][i] + dp[i + 1][right];
                    ans = min(ans, cost);
                }

                dp[left][right] = ans;
            }
        }

        return dp[0][n - 1];
    }
    int mctFromLeafValues(vector<int> &arr)
    {
        map<pair<int, int>, int> maxi;
        for (int i = 0; i < arr.size(); i++)
        {
            maxi[{i, i}] = arr[i];
            for (int j = i + 1; j < arr.size(); j++)
            {
                maxi[{i, j}] = max(arr[j], maxi[{i, j - 1}]);
            }
        }
        // return solve(arr, maxi, 0, arr.size() - 1);
        // vector<vector<int>> dp(arr.size() + 1, vector<int>(arr.size() + 1, -1));
        // return solveMem(arr,maxi, 0, arr.size() - 1, dp);
        return solveTab(arr, maxi);
    }
};