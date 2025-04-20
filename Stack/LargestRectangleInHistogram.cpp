// Leetcode Problem no : 84 - Largest Rectangle in Histogram(Hard)

/*
Given an array of integers heights representing the histogram's bar height where the width of each bar is 1, return the area of the largest rectangle in the histogram.



Example 1:


Input: heights = [2,1,5,6,2,3]
Output: 10
Explanation: The above is a histogram where width of each bar is 1.
The largest rectangle is shown in the red area, which has an area = 10 units.
Example 2:


Input: heights = [2,4]
Output: 4


Constraints:

1 <= heights.length <= 105
0 <= heights[i] <= 104
*/

#include <iostream>
#include <stack>
#include <vector>
#include <algorithm>
#include <limits.h>

using namespace std;

class Solution
{
public:
    vector<int> prevSmallerElement(const vector<int> &input)
    {
        stack<int> s;
        s.push(-1);
        vector<int> finalAns(input.size());
        for (int i = 0; i < input.size(); i++)
        {
            while (s.top() != -1 && input[s.top()] >= input[i])
            {
                s.pop();
            }
            finalAns[i] = s.top();
            s.push(i);
        }
        return finalAns;
    }

    vector<int> nextSmallerElement(const vector<int> &input)
    {
        stack<int> s;
        s.push(-1);
        vector<int> finalAns(input.size());
        for (int i = input.size() - 1; i >= 0; i--)
        {
            while (s.top() != -1 && input[s.top()] >= input[i])
            {
                s.pop();
            }
            finalAns[i] = s.top();
            s.push(i);
        }
        return finalAns;
    }

    int largestRectangleArea(vector<int> &heights)
    {
        vector<int> prevAns = prevSmallerElement(heights);
        vector<int> nextAns = nextSmallerElement(heights);
        int maxArea = INT_MIN;
        for (int i = 0; i < heights.size(); i++)
        {
            if (nextAns[i] == -1)
            {
                nextAns[i] = heights.size();
            }
            int width = nextAns[i] - prevAns[i] - 1;
            int area = heights[i] * width;
            maxArea = max(area, maxArea);
        }
        return maxArea;
    }
};