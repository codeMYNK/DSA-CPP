// Leetcode Problem No : 1004 - Maximum Consecutive 1s - III (Medium)

/*
1,1,0,0,1,1,1,1,1,1]
Bolded numbers were flipped from 0 to 1. The longest subarray is underlined.
Example 2:

Input: nums = [0,0,1,1,0,0,1,1,1,0,1,1,0,0,0,1,1,1,1], k = 3
Output: 10
Explanation: [0,0,1,1,1,1,1,1,1,1,1,1,0,0,0,1,1,1,1]
Bolded numbers were flipped from 0 to 1. The longest subarray is underlined.


Constraints:

1 <= nums.length <= 105
nums[i] is either 0 or 1.
0 <= k <= nums.length

*/

#include <bits/stdc++.h>

using namespace std;

class Solution
{
public:
    int longestOnes(vector<int> &nums, int k)
    {
        int l = 0, r = 0, len = 0, maxLen = 0, numOfZeroes = 0, n = nums.size();

        while (r < n)
        {
            if (nums[r] == 0)
                numOfZeroes++;

            if (numOfZeroes > k)
            {
                if (nums[l] == 0)
                    numOfZeroes--;
                l++;
            }

            if (numOfZeroes <= k)
            {
                len = r - l + 1;
                maxLen = max(len, maxLen);
            }
            r++;
        }
        return maxLen;
    }
};