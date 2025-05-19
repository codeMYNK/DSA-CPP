// Leetcode Problem No : 416 - Partition Equal Subset Sum(Medium)
/*
Given an integer array nums, return true if you can partition the array into two subsets such that the sum of the elements in both subsets is equal or false otherwise.



Example 1:

Input: nums = [1,5,11,5]
Output: true
Explanation: The array can be partitioned as [1, 5, 5] and [11].
Example 2:

Input: nums = [1,2,3,5]
Output: false
Explanation: The array cannot be partitioned into equal sum subsets.


Constraints:

1 <= nums.length <= 200
1 <= nums[i] <= 100
*/

#include <iostream>
#include <vector>

using namespace std;

class Solution
{
public:
    int findTarget(vector<int> &nums)
    { // - Function to find the target
        int total = 0;
        for (int i = 0; i < nums.size(); i++)
        {
            total += nums[i];
        }
        if (total & 1)
            return 0;
        return total / 2;
    }
    // bool solve(vector<int>&nums, int index, int target){ - Recursive Approach
    //     if(index >= nums.size()) return false;
    //     if(target < 0) return false;
    //     if(target == 0) return true;

    //     bool include = solve(nums, index + 1, target - nums[index]);
    //     bool exclude = solve(nums, index + 1, target);

    //     return include || exclude;
    // }
    // bool solveMemo(vector<int>&nums, int index, int target, vector<vector<int>>&dp){ - Top Down DP
    //     if(index >= nums.size()) return false;
    //     if(target < 0) return false;
    //     if(target == 0) return true;
    //     if (dp[index][target] != -1) return dp[index][target];

    //     bool include = solveMemo(nums, index + 1, target - nums[index], dp);
    //     bool exclude = solveMemo(nums, index + 1, target, dp);

    //     dp[index][target] =  include || exclude;
    //     return dp[index][target];
    // }
    // bool solveTab(vector<int> &nums, int t){ - Bottom Up DP
    //     vector<vector<int>> dp(nums.size() + 1, vector<int>(t + 1, 0));

    //     int i = nums.size() - 1;
    //     for(int j = 0; j <= nums.size(); j++){
    //         dp[j][0] = 1;
    //     }

    //     for(int index = i - 1; index >= 0; index--){
    //         for(int target = 1; target <= t; target++){
    //             bool include = 0;
    //             if(target - nums[index] >= 0)
    //                 include = dp[index + 1][target - nums[index]];
    //             bool exclude = dp[index + 1][target];

    //             dp[index][target] =  include || exclude;
    //         }
    //     }
    //     return dp[0][t];
    // }
    bool solveSO(vector<int> &nums, int t)
    { // - Space optimization
        vector<int> curr(t + 1, 0);
        vector<int> next(t + 1, 0);
        int i = nums.size() - 1;
        curr[0] = 1;
        next[0] = 1;

        for (int index = i - 1; index >= 0; index--)
        {
            for (int target = 1; target <= t; target++)
            {
                bool include = 0;
                if (target - nums[index] >= 0)
                    include = next[target - nums[index]];
                bool exclude = next[target];

                curr[target] = include || exclude;
            }
            next = curr;
        }
        return curr[t];
    }
    bool canPartition(vector<int> &nums)
    {
        int target = findTarget(nums);
        if (target == 0)
            return false;
        // return solve(nums, 0, target);
        // vector<vector<int>> dp(nums.size(), vector<int>(target + 1, -1));
        // return solveMemo(nums, 0, target, dp);
        // return solveTab(nums, target);
        return solveSO(nums, target);
    }
};