// Leetcode Problem No : 632 -Smallest Range Covering Elements from K Lists(Hard)

/*
You have k lists of sorted integers in non-decreasing order. Find the smallest range that includes at least one number from each of the k lists.

We define the range [a, b] is smaller than range [c, d] if b - a < d - c or a < c if b - a == d - c.



Example 1:

Input: nums = [[4,10,15,24,26],[0,9,12,20],[5,18,22,30]]
Output: [20,24]
Explanation:
List 1: [4, 10, 15, 24,26], 24 is in range [20,24].
List 2: [0, 9, 12, 20], 20 is in range [20,24].
List 3: [5, 18, 22, 30], 22 is in range [20,24].
Example 2:

Input: nums = [[1,2,3],[1,2,3],[1,2,3]]
Output: [1,1]


Constraints:

nums.length == k
1 <= k <= 3500
1 <= nums[i].length <= 50
-105 <= nums[i][j] <= 105
nums[i] is sorted in non-decreasing order.
*/

#include <iostream>
#include <queue>
#include <limits.h>
#include <vector>
#include <algorithm>

using namespace std;

class Solution
{
public:
    class node
    {
    public:
        int data;
        int row;
        int col;

        node(int data, int row, int col)
        {
            this->data = data;
            this->row = row;
            this->col = col;
        }
    };

    class compare
    {
    public:
        bool operator()(node *a, node *b)
        {
            return a->data > b->data;
        }
    };

    vector<int> smallestRange(vector<vector<int>> &nums)
    {
        int mini = INT_MAX, maxi = INT_MIN;
        priority_queue<node *, vector<node *>, compare> minHeap;

        for (int i = 0; i < nums.size(); i++)
        {
            int element = nums[i][0];
            mini = min(mini, element);
            maxi = max(maxi, element);
            minHeap.push(new node(element, i, 0));
        }

        int startRange = mini, endRange = maxi;

        while (!minHeap.empty())
        {
            node *temp = minHeap.top();
            minHeap.pop();

            mini = temp->data;

            if (maxi - mini < endRange - startRange)
            {
                startRange = mini;
                endRange = maxi;
            }

            if (temp->col + 1 < nums[temp->row].size())
            {
                int nextVal = nums[temp->row][temp->col + 1];
                maxi = max(maxi, nextVal);
                minHeap.push(new node(nextVal, temp->row, temp->col + 1));
            }
            else
            {
                break;
            }
        }

        return {startRange, endRange};
    }
};
