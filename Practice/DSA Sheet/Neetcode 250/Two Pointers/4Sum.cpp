/*
You are given an integer array nums of size n, return an array of all the unique quadruplets [nums[a], nums[b], nums[c], nums[d]] such that:

0 <= a, b, c, d < n
a, b, c, and d are distinct.
nums[a] + nums[b] + nums[c] + nums[d] == target
You may return the answer in any order.

Note: [1,0,3,2] and [3,0,1,2] are considered as same quadruplets.

Example 1:

Input: nums = [3,2,3,-3,1,0], target = 3

Output: [[-3,0,3,3],[-3,1,2,3]]
Example 2:

Input: nums = [1,-1,1,-1,1,-1], target = 2

Output: [[-1,1,1,1]]
Constraints:

1 <= nums.length <= 200
-1,000,000,000 <= nums[i] <= 1,000,000,000
-1,000,000,000 <= target <= 1,000,000,000

*/

#include <bits/stdc++.h>

using namespace std;

class Solution
{
public:
    vector<vector<int>> fourSum(vector<int> &nums, int target)
    {
        vector<vector<int>> result;

        int n = nums.size();
        sort(nums.begin(), nums.end());
        for (int i = 0; i < n; i++)
        {
            if (i > 0 && nums[i] == nums[i - 1])
                continue;
            for (int j = i + 1; j < n; j++)
            {
                if (j > i + 1 && nums[j] == nums[j - 1])
                    continue;
                int l = j + 1;
                int k = n - 1;
                while (l < k)
                {
                    long long sum = 1LL * nums[i] + nums[j] + nums[k] + nums[l];
                    if (sum == target)
                    {
                        vector<int> quadro = {nums[i], nums[j], nums[l], nums[k]};
                        result.push_back(quadro);
                        while (l < k && nums[l] == nums[l + 1])
                            l++;
                        while (l < k && nums[k] == nums[k - 1])
                            k--;
                        l++;
                        k--;
                    }
                    else if (sum < target)
                        l++;
                    else
                        k--;
                }
            }
        }
        return result;
    }
};