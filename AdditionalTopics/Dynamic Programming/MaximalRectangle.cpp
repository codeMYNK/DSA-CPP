// Leetcode Problem No : 85 - Maximal Rectangle(Hard)

/*
Given a rows x cols binary matrix filled with 0's and 1's, find the largest rectangle containing only 1's and return its area.



Example 1:


Input: matrix = [["1","0","1","0","0"],["1","0","1","1","1"],["1","1","1","1","1"],["1","0","0","1","0"]]
Output: 6
Explanation: The maximal rectangle is shown in the above picture.
Example 2:

Input: matrix = [["0"]]
Output: 0
Example 3:

Input: matrix = [["1"]]
Output: 1


Constraints:

rows == matrix.length
cols == matrix[i].length
1 <= row, cols <= 200
matrix[i][j] is '0' or '1'.
*/
#include <bits/stdc++.h>
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
    int maximalRectangle(vector<vector<char>> &matrix)
    {
        vector<int> histogram(matrix[0].size(), 0);
        int maxi = INT_MIN;
        for (int i = 0; i < matrix.size(); i++)
        {
            for (int j = 0; j < histogram.size(); j++)
            {
                if (matrix[i][j] == '1')
                {
                    histogram[j]++;
                }
                else
                {
                    histogram[j] = 0;
                }
            }
            maxi = max(maxi, largestRectangleArea(histogram));
        }
        return maxi;
    }
};