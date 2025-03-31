// Leetcode Problem No 46 : Permutations(Medium)

/*
Given an array nums of distinct integers, return all the possible permutations. You can return the answer in any order.



Example 1:

Input: nums = [1,2,3]
Output: [[1,2,3],[1,3,2],[2,1,3],[2,3,1],[3,1,2],[3,2,1]]
Example 2:

Input: nums = [0,1]
Output: [[0,1],[1,0]]
Example 3:

Input: nums = [1]
Output: [[1]]


Constraints:

1 <= nums.length <= 6
-10 <= nums[i] <= 10
All the integers of nums are unique.
*/

#include <iostream>
#include <vector>

using namespace std;

class Solution
{
public:
    void getPermutations(vector<int> &nums, vector<vector<int>> &result, int s, int i)
    {
        if (i == s)
        {
            result.push_back(nums);
            return;
        }

        for (int j = i; j < s; j++)
        {
            swap(nums[i], nums[j]);

            getPermutations(nums, result, s, i + 1);

            swap(nums[i], nums[j]);
        }
    }

    vector<vector<int>> permute(vector<int> &nums)
    {
        int size = nums.size();
        vector<vector<int>> resultArr;
        getPermutations(nums, resultArr, size, 0);
        return resultArr;
    }
};