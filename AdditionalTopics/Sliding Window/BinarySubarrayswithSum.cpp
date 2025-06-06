// Leetcode Problem No : 930 - Binary Subarrays with Sum(Medium)

/*
Given a binary array nums and an integer goal, return the number of non-empty subarrays with a sum goal.

A subarray is a contiguous part of the array.



Example 1:

Input: nums = [1,0,1,0,1], goal = 2
Output: 4
Explanation: The 4 subarrays are bolded and underlined below:
[1,0,1,0,1]
[1,0,1,0,1]
[1,0,1,0,1]
[1,0,1,0,1]
Example 2:

Input: nums = [0,0,0,0,0], goal = 0
Output: 15


Constraints:

1 <= nums.length <= 3 * 104
nums[i] is either 0 or 1.
0 <= goal <= nums.length
*/

#include <bits/stdc++.h>

using namespace std;

class Solution
{
private:
    int subArrayCounter(vector<int> &nums, int goal)
    {
        if (goal < 0)
            return 0;

        int l = 0, r = 0, cnt = 0, sum = 0;

        while (r < nums.size())
        {
            sum += nums[r];
            while (sum > goal)
            {
                sum = sum - nums[l];
                l++;
            }
            cnt = cnt + r - l + 1;
            r++;
        }
        return cnt;
    }

public:
    int numSubarraysWithSum(vector<int> &nums, int goal)
    {
        int num1 = subArrayCounter(nums, goal);
        int num2 = subArrayCounter(nums, goal - 1);
        return num1 - num2;
    }
};