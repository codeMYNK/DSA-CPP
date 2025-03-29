// Leetcode Problem No 493 : Reverse Pairs (Hard)

/*
Given an integer array nums, return the number of reverse pairs in the array.

A reverse pair is a pair (i, j) where:

0 <= i < j < nums.length and
nums[i] > 2 * nums[j].


Example 1:

Input: nums = [1,3,2,3,1]
Output: 2
Explanation: The reverse pairs are:
(1, 4) --> nums[1] = 3, nums[4] = 1, 3 > 2 * 1
(3, 4) --> nums[3] = 3, nums[4] = 1, 3 > 2 * 1
Example 2:

Input: nums = [2,4,3,5,1]
Output: 3
Explanation: The reverse pairs are:
(1, 4) --> nums[1] = 4, nums[4] = 1, 4 > 2 * 1
(2, 4) --> nums[2] = 3, nums[4] = 1, 3 > 2 * 1
(3, 4) --> nums[3] = 5, nums[4] = 1, 5 > 2 * 1


Constraints:

1 <= nums.length <= 5 * 104
-231 <= nums[i] <= 231 - 1
*/

#include <iostream>
#include <vector>

using namespace std;

class Solution
{
public:
    void finalOps(vector<int> &nums, int s, int e, int &revPairCount)
    {
        int mid = s + (e - s) / 2;

        int len1 = mid - s + 1;
        int len2 = e - mid;
        vector<int> leftArr(len1);
        vector<int> rightArr(len2);

        for (int i = 0; i < len1; i++)
            leftArr[i] = nums[s + i];
        for (int i = 0; i < len2; i++)
            rightArr[i] = nums[mid + 1 + i];

        int leftIndex = 0, rightIndex = 0;

        while (leftIndex < len1)
        {
            while (rightIndex < len2 && leftArr[leftIndex] > 2LL * rightArr[rightIndex])
            {
                rightIndex++;
            }
            revPairCount += rightIndex;
            leftIndex++;
        }

        leftIndex = 0, rightIndex = 0;
        int mainArrIndex = s;

        while (leftIndex < len1 && rightIndex < len2)
        {
            if (leftArr[leftIndex] <= rightArr[rightIndex])
            {
                nums[mainArrIndex++] = leftArr[leftIndex++];
            }
            else
            {
                nums[mainArrIndex++] = rightArr[rightIndex++];
            }
        }

        while (leftIndex < len1)
            nums[mainArrIndex++] = leftArr[leftIndex++];
        while (rightIndex < len2)
            nums[mainArrIndex++] = rightArr[rightIndex++];
    }

    void mergeSort(vector<int> &nums, int s, int e, int &revPairCount)
    {
        if (s >= e)
            return;

        int mid = s + (e - s) / 2;

        mergeSort(nums, s, mid, revPairCount);
        mergeSort(nums, mid + 1, e, revPairCount);
        finalOps(nums, s, e, revPairCount);
    }

    int reversePairs(vector<int> &nums)
    {
        int numOfReversePairs = 0;
        mergeSort(nums, 0, nums.size() - 1, numOfReversePairs);
        return numOfReversePairs;
    }
};
