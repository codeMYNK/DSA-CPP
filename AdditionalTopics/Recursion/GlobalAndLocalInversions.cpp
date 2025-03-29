// Leetcode Problem No 775 : Global and Local Inversions (Medium)

/*
You are given an integer array nums of length n which represents a permutation of all the integers in the range [0, n - 1].

The number of global inversions is the number of the different pairs (i, j) where:

0 <= i < j < n
nums[i] > nums[j]
The number of local inversions is the number of indices i where:

0 <= i < n - 1
nums[i] > nums[i + 1]
Return true if the number of global inversions is equal to the number of local inversions.



Example 1:

Input: nums = [1,0,2]
Output: true
Explanation: There is 1 global inversion and 1 local inversion.
Example 2:

Input: nums = [1,2,0]
Output: false
Explanation: There are 2 global inversions and 1 local inversion.


Constraints:

n == nums.length
1 <= n <= 105
0 <= nums[i] < n
All the integers of nums are unique.
nums is a permutation of all the numbers in the range [0, n - 1].
*/

#include <iostream>
#include <vector>

using namespace std;

class Solution
{
public:
    void finalOps(vector<int> &nums, int s, int e, bool &isEqual)
    {
        int mid = s + (e - s) / 2;
        int len1 = mid - s + 1;
        int len2 = e - mid;

        vector<int> leftArr(len1);
        vector<int> rightArr(len2);

        for (int i = 0; i < len1; i++)
        {
            leftArr[i] = nums[s + i];
        }
        for (int i = 0; i < len2; i++)
        {
            rightArr[i] = nums[mid + 1 + i];
        }

        int maxLeft = leftArr[0];
        for (int i = 1; i < len1; i++)
        {
            maxLeft = max(maxLeft, leftArr[i]);
        }

        for (int j = 0; j < len2; j++)
        {
            if (maxLeft > rightArr[j])
            {
                isEqual = false;
                return;
            }
        }

        int leftIndex = 0, rightIndex = 0, mainIndex = s;
        while (leftIndex < len1 && rightIndex < len2)
        {
            if (leftArr[leftIndex] <= rightArr[rightIndex])
            {
                nums[mainIndex++] = leftArr[leftIndex++];
            }
            else
            {
                nums[mainIndex++] = rightArr[rightIndex++];
            }
        }
        while (leftIndex < len1)
            nums[mainIndex++] = leftArr[leftIndex++];
        while (rightIndex < len2)
            nums[mainIndex++] = rightArr[rightIndex++];
    }

    void mergeSort(vector<int> &nums, int s, int e, bool &isEqual)
    {
        if (s >= e)
            return;

        int mid = s + (e - s) / 2;
        mergeSort(nums, s, mid, isEqual);
        mergeSort(nums, mid + 1, e, isEqual);
        finalOps(nums, s, e, isEqual);
    }

    bool isIdealPermutation(vector<int> &nums)
    {
        int s = 0, e = nums.size() - 1;
        bool isEqual = true;
        mergeSort(nums, s, e, isEqual);
        return isEqual;
    }
};
