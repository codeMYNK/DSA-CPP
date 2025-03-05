// Leetcode Problem No - 410 : Split Array's Largest Sum - (Hard)

/*
Given an integer array nums and an integer k, split nums into k non-empty subarrays such that the largest sum of any subarray is minimized.

Return the minimized largest sum of the split.

A subarray is a contiguous part of the array.



Example 1:

Input: nums = [7,2,5,10,8], k = 2
Output: 18
Explanation: There are four ways to split nums into two subarrays.
The best way is to split it into [7,2,5] and [10,8], where the largest sum among the two subarrays is only 18.
Example 2:

Input: nums = [1,2,3,4,5], k = 2
Output: 9
Explanation: There are four ways to split nums into two subarrays.
The best way is to split it into [1,2,3] and [4,5], where the largest sum among the two subarrays is only 9.


Constraints:

1 <= nums.length <= 1000
0 <= nums[i] <= 106
1 <= k <= min(50, nums.length)
*/
#include <iostream>
#include <vector>
#include <bits/stdc++.h>
#include <algorithm>

using namespace std;

class Solution
{
public:
    bool checker(const vector<int> &arr, int end, int k)
    {
        int currEl = 0, currValueOfk = 1;

        for (int i = 0; i < arr.size(); i++)
        {
            if (arr[i] + currEl > end)
            {
                currValueOfk++;
                currEl = arr[i];
                if (currValueOfk > k)
                {
                    return false;
                }
            }
            else
            {
                currEl = currEl + arr[i];
            }
        }
        return true;
    }
    int minOfMaxFinder(const vector<int> &arr, int k)
    {
        int start = *max_element(arr.begin(), arr.end());
        int end = accumulate(arr.begin(), arr.end(), 0);
        int result = end;

        while (start <= end)
        {
            int mid = start + (end - start) / 2;
            if (checker(arr, mid, k))
            {
                result = mid;
                end = mid - 1;
            }
            else
            {
                start = mid + 1;
            }
        }
        return result;
    }
    int splitArray(vector<int> &nums, int k)
    {
        int findMinofMax = minOfMaxFinder(nums, k);
        return findMinofMax;
    }
};