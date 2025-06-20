/*
You are given an integer array heights where heights[i] represents the height of the
i
t
h
i
th
  bar.

You may choose any two bars to form a container. Return the maximum amount of water a container can store.

Example 1:



Input: height = [1,7,2,5,4,7,3,6]

Output: 36
Example 2:

Input: height = [2,2,2]

Output: 4
Constraints:

2 <= height.length <= 1000
0 <= height[i] <= 1000

*/

#include <bits/stdc++.h>

using namespace std;

class Solution
{
public:
    int maxArea(vector<int> &heights)
    {
        int n = heights.size();
        int maxArea = INT_MIN;
        int i = 0;
        int j = n - 1;
        while (i < j)
        {
            int length = j - i;
            int breadth = min(heights[i], heights[j]);
            int area = length * breadth;
            maxArea = max(area, maxArea);
            if (heights[i] < heights[j])
                i++;
            else if (heights[i] > heights[j])
                j--;
            else
            {
                i++;
                j--;
            }
        }
        return maxArea;
    }
};
