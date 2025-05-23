// Leetcode Problem No : 994 - Rotting Oranges (Medium)

/*
You are given an m x n grid where each cell can have one of three values:

0 representing an empty cell,
1 representing a fresh orange, or
2 representing a rotten orange.
Every minute, any fresh orange that is 4-directionally adjacent to a rotten orange becomes rotten.

Return the minimum number of minutes that must elapse until no cell has a fresh orange. If this is impossible, return -1.



Example 1:


Input: grid = [[2,1,1],[1,1,0],[0,1,1]]
Output: 4
Example 2:

Input: grid = [[2,1,1],[0,1,1],[1,0,1]]
Output: -1
Explanation: The orange in the bottom left corner (row 2, column 0) is never rotten, because rotting only happens 4-directionally.
Example 3:

Input: grid = [[0,2]]
Output: 0
Explanation: Since there are already no fresh oranges at minute 0, the answer is just 0.


Constraints:

m == grid.length
n == grid[i].length
1 <= m, n <= 10
grid[i][j] is 0, 1, or 2.
*/

#include <bits/stdc++.h>

using namespace std;

class Solution
{
public:
    int orangesRotting(vector<vector<int>> &grid)
    {
        int row = grid.size();
        int col = grid[0].size();

        queue<pair<pair<int, int>, int>> q;
        vector<vector<int>> visited(row, vector<int>(col, 0));

        for (int i = 0; i < row; i++)
        {
            for (int j = 0; j < col; j++)
            {
                if (grid[i][j] == 2)
                {
                    q.push({{i, j}, 0});
                    visited[i][j] = 2;
                }
                else
                {
                    visited[i][j] = 0;
                }
            }
        }

        int time = 0;
        int dRow[] = {-1, 0, 1, 0};
        int dCol[] = {0, 1, 0, -1};

        while (!q.empty())
        {
            int r = q.front().first.first;
            int c = q.front().first.second;
            int t = q.front().second;
            q.pop();
            time = max(time, t);

            for (int i = 0; i < 4; i++)
            {
                int nRow = r + dRow[i];
                int nCol = c + dCol[i];

                if (nRow >= 0 && nRow < row && nCol >= 0 && nCol < col &&
                    visited[nRow][nCol] == 0 && grid[nRow][nCol] == 1)
                {
                    q.push({{nRow, nCol}, t + 1});
                    visited[nRow][nCol] = 2;
                }
            }
        }

        for (int i = 0; i < row; i++)
        {
            for (int j = 0; j < col; j++)
            {
                if (visited[i][j] != 2 && grid[i][j] == 1)
                    return -1;
            }
        }

        return time;
    }
};
