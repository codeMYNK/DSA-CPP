// Leetcode Problem No : 300 - Longest Increasing Subsequence(Medium)

/*
Given an integer array nums, return the length of the longest strictly increasing subsequence.



Example 1:

Input: nums = [10,9,2,5,3,7,101,18]
Output: 4
Explanation: The longest increasing subsequence is [2,3,7,101], therefore the length is 4.
Example 2:

Input: nums = [0,1,0,3,2,3]
Output: 4
Example 3:

Input: nums = [7,7,7,7,7,7,7]
Output: 1


Constraints:

1 <= nums.length <= 2500
-104 <= nums[i] <= 104


Follow up: Can you come up with an algorithm that runs in O(n log(n)) time complexity?
*/

#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

class Solution
{
public:
    // int solve(vector<int> &nums, int curr, int prev){ - Recursive Approach
    //     if(curr == nums.size()) return 0;

    //     int include = 0;
    //     if(prev == -1 || nums[curr] > nums[prev]){
    //         include = 1 + solve(nums, curr + 1, curr);
    //     }
    //     int exclude = solve(nums, curr + 1, prev);

    //     return max(include, exclude);
    // }
    // int solveMem(vector<int> &nums, int curr, int prev, vector<vector<int> > &dp){ - Top Down DP
    //     if(curr == nums.size()) return 0;

    //     if(dp[curr][prev + 1] != -1) return dp[curr][prev + 1];
    //     int include = 0;
    //     if(prev == -1 || nums[curr] > nums[prev]){
    //         include = 1 + solveMem(nums, curr + 1, curr, dp);
    //     }
    //     int exclude = solveMem(nums, curr + 1, prev, dp);

    //     dp[curr][prev + 1] = max(include, exclude);
    //     return dp[curr][prev + 1];
    // }

    // int solveTab(vector<int> &nums){ - Bottom Up DP
    //     vector<vector<int> > dp(nums.size() + 1, vector<int> (nums.size() + 1, 0));

    //     for(int curr = nums.size() - 1; curr >= 0; curr --){
    //         for(int prev = curr - 1; prev >= -1; prev--){
    //             int include = 0;
    //             if(prev == -1 || nums[curr] > nums[prev]){
    //                 include = 1 + dp[curr + 1][curr + 1];
    //              }
    //             int exclude = dp[curr + 1][prev+1];

    //             dp[curr][prev + 1] = max(include, exclude);
    //         }
    //     }
    //     return dp[0][0];
    // }

    // int solveSO(vector<int> &nums){ Space Optimized
    //     vector<int> currRow(nums.size() + 1, 0);
    //     vector<int> next(nums.size() + 1, 0);
    //     for(int curr = nums.size() - 1; curr >= 0; curr --){
    //         for(int prev = curr - 1; prev >= -1; prev--){
    //             int include = 0;
    //             if(prev == -1 || nums[curr] > nums[prev]){
    //                 include = 1 + next[curr + 1];
    //              }
    //             int exclude = next[prev+1];

    //             currRow[prev + 1] = max(include, exclude);
    //         }
    //         next = currRow;
    //     }
    //     return next[0];
    // }
    int solveOp(vector<int> &nums)
    {
        int n = nums.size();
        if (n == 0)
            return 0;

        vector<int> ans;
        ans.push_back(nums[0]);

        for (int i = 1; i < n; i++)
        {
            if (nums[i] > ans.back())
            {
                ans.push_back(nums[i]);
            }
            else
            {
                int index = lower_bound(ans.begin(), ans.end(), nums[i]) - ans.begin();
                ans[index] = nums[i];
            }
        }

        return ans.size();
    }
    int lengthOfLIS(vector<int> &nums)
    {
        // return solve(nums, 0, -1);
        // vector<vector<int> > dp(nums.size() + 1, vector<int>(nums.size() + 1, -1));
        // return solveMem(nums, 0, -1, dp);
        // return solveTab(nums);
        // return solveSO(nums);
        return solveOp(nums);
    }
};