// Leetcode Problem No 53 : Maximum SubArray - (Medium)

/*
Given an integer array nums, find the subarray with the largest sum, and return its sum.



Example 1:

Input: nums = [-2,1,-3,4,-1,2,1,-5,4]
Output: 6
Explanation: The subarray [4,-1,2,1] has the largest sum 6.
Example 2:

Input: nums = [1]
Output: 1
Explanation: The subarray [1] has the largest sum 1.
Example 3:

Input: nums = [5,4,-1,7,8]
Output: 23
Explanation: The subarray [5,4,-1,7,8] has the largest sum 23.


Constraints:

1 <= nums.length <= 105
-104 <= nums[i] <= 104


Follow up: If you have figured out the O(n) solution, try coding another solution using the divide and conquer approach, which is more subtle.

Sol 1 : Kadane's Algo - O(N)
Sol 2 : DnC
*/

#include <iostream>
#include <vector>
#include <climits>

using namespace std;

class Solution
{
public:
    int maxSubArray(vector<int> &nums)
    {
        int sum = 0, maxi = INT_MIN;
        for (int i = 0; i < nums.size(); i++)
        {
            sum += nums[i];

            if (sum > maxi)
            {
                maxi = sum;
            }

            if (sum < 0)
            {
                sum = 0;
            }
        }
        return maxi;
    }
};

// Approach 2: using dnc

/*
class Solution {
public:
    int maxSubArrayHelper(vector<int>& v, int start, int end){
        if(start == end) return v[start];

        int maxLeftBorderSum = INT_MIN, maxRightBorderSum = INT_MIN;
        int leftBorderSum = 0, rightBorderSum = 0;

        int mid = start + (end - start)/2;
        int maxLeftSum = maxSubArrayHelper(v, start, mid);
        int maxRightSum = maxSubArrayHelper(v, mid + 1, end);

        //Max Cross Border Sum

        for(int i = mid; i >= start; i--){
            leftBorderSum += v[i];
            if(leftBorderSum >= maxLeftBorderSum){
                maxLeftBorderSum = leftBorderSum;
            }
        }
        for(int i = mid + 1; i <= end; i++){
            rightBorderSum += v[i];
            if(rightBorderSum >= maxRightBorderSum){
                maxRightBorderSum = rightBorderSum;
            }
        }
        int crossBorderSum = maxLeftBorderSum + maxRightBorderSum;
        return max(crossBorderSum, max(maxRightSum, maxLeftSum ));
    }
    int maxSubArray(vector<int>& nums) {
        return maxSubArrayHelper(nums, 0, nums.size() - 1);
    }
};
*/