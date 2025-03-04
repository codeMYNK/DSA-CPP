// Leetcode Problem No. 658 : Find K Closest Elements(Medium)

/*
Given a sorted integer array arr, two integers k and x, return the k closest integers to x in the array.
The result should also be sorted in ascending order.

An integer a is closer to x than an integer b if:

|a - x| < |b - x|, or
|a - x| == |b - x| and a < b


Example 1:

Input: arr = [1,2,3,4,5], k = 4, x = 3

Output: [1,2,3,4]

Example 2:

Input: arr = [1,1,2,3,4,5], k = 4, x = -1

Output: [1,1,2,3]



Constraints:

1 <= k <= arr.length
1 <= arr.length <= 104
arr is sorted in ascending order.
-104 <= arr[i], x <= 104

Key Takeaways : Was a bit confused while applying traditional binary search on the array and pushing k closest elements to
a new array and returning it(initial approach it was not passing the required testcases.)
So decided to consider values from 0 to abs(X) as an entire search space and then return the closest values if present in the array.
Efficiently tackling the time complexity to O(log n) and solving it.

*/

#include <iostream>
#include <vector>

using namespace std;

class Solution
{
public:
    vector<int> findClosestElements(vector<int> &arr, int k, int x)
    {
        int left = 0, right = arr.size() - 1;

        while (left < right)
        {
            int mid = left + (right - left) / 2;
            if (arr[mid] < x)
                left = mid + 1;
            else
                right = mid;
        }

        int l = left - 1, r = left;
        while (k--)
        {
            if (l < 0)
                r++;
            else if (r >= arr.size())
                l--;
            else if (abs(arr[l] - x) <= abs(arr[r] - x))
                l--;
            else
                r++;
        }

        return vector<int>(arr.begin() + l + 1, arr.begin() + r);
    }
};