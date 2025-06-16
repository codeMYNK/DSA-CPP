/*
You are given an integer array nums of size n, find all elements that appear more than ⌊ n/3 ⌋ times. You can return the result in any order.

Example 1:

Input: nums = [5,2,3,2,2,2,2,5,5,5]

Output: [2,5]
Example 2:

Input: nums = [4,4,4,4,4]

Output: [4]
Example 3:

Input: nums = [1,2,3]

Output: []
Constraints:

1 <= nums.length <= 50,000.
-1,000,000,000 <= nums[i] <= 1,000,000,000
Follow up: Could you solve the problem in linear time and in O(1) space?
*/

#include <bits/stdc++.h>

using namespace std;

class Solution
{
public:
    vector<int> majorityElement(vector<int> &nums)
    {
        int n = nums.size();
        int count1 = 0, count2 = 0;
        int candidate1 = INT_MIN, candidate2 = INT_MIN;
        for (int num : nums)
        {
            if (num == candidate1)
                count1++;
            else if (num == candidate2)
                count2++;
            else if (count1 == 0)
            {
                candidate1 = num;
                count1 = 1;
            }
            else if (count2 == 0)
            {
                candidate2 = num;
                count2 = 1;
            }
            else
            {
                count1--;
                count2--;
            }
        }
        count1 = count2 = 0;
        for (int num : nums)
        {
            if (num == candidate1)
                count1++;
            else if (num == candidate2)
                count2++;
        }
        vector<int> result;
        if (count1 > n / 3)
            result.push_back(candidate1);
        if (count2 > n / 3)
            result.push_back(candidate2);

        return result;
    }
};