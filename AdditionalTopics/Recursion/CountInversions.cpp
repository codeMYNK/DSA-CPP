// GeeksforGeeks : Count Inversions - Medium

/*
Given an array of integers arr[]. Find the Inversion Count in the array.
Two elements arr[i] and arr[j] form an inversion if arr[i] > arr[j] and i < j.

Inversion Count: For an array, inversion count indicates how far (or close) the array is from being sorted. If the array is already sorted then the inversion count is 0.
If an array is sorted in the reverse order then the inversion count is the maximum.

Examples:

Input: arr[] = [2, 4, 1, 3, 5]
Output: 3
Explanation: The sequence 2, 4, 1, 3, 5 has three inversions (2, 1), (4, 1), (4, 3).
Input: arr[] = [2, 3, 4, 5, 6]
Output: 0
Explanation: As the sequence is already sorted so there is no inversion count.
Input: arr[] = [10, 10, 10]
Output: 0
Explanation: As all the elements of array are same, so there is no inversion count.
Constraints:
1 ≤ arr.size() ≤ 105
1 ≤ arr[i] ≤ 104
*/

#include <iostream>
#include <vector>

using namespace std;

class Solution
{
public:
    // Function to count inversions in the array.
    void mergeTwoParts(vector<int> &arr, int s, int e, int &inv)
    {
        int mid = s + (e - s) / 2;

        int len1 = mid - s + 1;
        int len2 = e - mid;

        vector<int> leftArr(len1, 0);
        vector<int> rightArr(len2, 0);
        int k = s;
        for (int i = 0; i < len1; i++)
        {
            leftArr[i] = arr[k++];
        }
        k = mid + 1;
        for (int i = 0; i < len2; i++)
        {
            rightArr[i] = arr[k++];
        }

        int leftIndex = 0;
        int rightIndex = 0;
        int mainArrIndex = s;

        while (leftIndex < len1 && rightIndex < len2)
        {
            if (leftArr[leftIndex] <= rightArr[rightIndex])
            {
                arr[mainArrIndex++] = leftArr[leftIndex++];
            }
            else
            {
                inv = inv + (len1 - leftIndex);
                arr[mainArrIndex++] = rightArr[rightIndex++];
            }
        }
        while (leftIndex < len1)
        {
            arr[mainArrIndex++] = leftArr[leftIndex++];
        }

        while (rightIndex < len2)
        {
            arr[mainArrIndex++] = rightArr[rightIndex++];
        }
    }
    void inversionCounter(vector<int> &arr, int s, int e, int &inversions)
    {
        if (s >= e)
        {
            return;
        }

        int mid = s + (e - s) / 2;

        inversionCounter(arr, s, mid, inversions);
        inversionCounter(arr, mid + 1, e, inversions);
        mergeTwoParts(arr, s, e, inversions);
    }
    int inversionCount(vector<int> &arr)
    {
        // Your Code Here
        int s = 0;
        int e = arr.size() - 1;
        int countOfInversions = 0;

        inversionCounter(arr, s, e, countOfInversions);
        return countOfInversions;
    }
};