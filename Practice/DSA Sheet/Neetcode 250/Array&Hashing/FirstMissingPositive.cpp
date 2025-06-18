/*
You are given an unsorted integer array nums. Return the smallest positive integer that is not present in nums.

You must implement an algorithm that runs in O(n) time and uses O(1) auxiliary space.

Example 1:

Input: nums = [-2,-1,0]

Output: 1
Example 2:

Input: nums = [1,2,4]

Output: 3
Example 3:

Input: nums = [1,2,4,5,6,3,1]

Output: 7
Constraints:

1 <= nums.length <= 100,000
-(2^31) <= nums[i] <= ((2^31)-1)

*/

#include <bits/stdc++.h>

using namespace std;

class Solution
{
public:
    int firstMissingPositive(vector<int> &nums)
    {
        int n = nums.size();

        for (int i = 0; i < n; i++)
        {
            if (nums[i] < 0)
                nums[i] = 0;
        }

        for (int i = 0; i < n; i++)
        {
            int val = abs(nums[i]);
            if (val >= 1 && val <= n)
            {
                if (nums[val - 1] > 0)
                {
                    nums[val - 1] *= -1;
                }
                else if (nums[val - 1] == 0)
                {
                    nums[val - 1] = -1 * (n + 1);
                }
            }
        }

        for (int i = 1; i < n + 1; i++)
        {
            if (nums[i - 1] >= 0)
                return i;
        }
        return n + 1;
    }
};