// Leetcode Problem No : 200 - Number of Islands(Medium)

/*
Given an m x n 2D binary grid grid which represents a map of '1's (land) and '0's (water), return the number of islands.

An island is surrounded by water and is formed by connecting adjacent lands horizontally or vertically. You may assume all four edges of the grid are all surrounded by water.



Example 1:

Input: grid = [
  ["1","1","1","1","0"],
  ["1","1","0","1","0"],
  ["1","1","0","0","0"],
  ["0","0","0","0","0"]
]
Output: 1
Example 2:

Input: grid = [
  ["1","1","0","0","0"],
  ["1","1","0","0","0"],
  ["0","0","1","0","0"],
  ["0","0","0","1","1"]
]
Output: 3


Constraints:

m == grid.length
n == grid[i].length
1 <= m, n <= 300
grid[i][j] is '0' or '1'.
*/

#include <bits/stdc++.h>

using namespace std;

class Solution
{
public:
    void bfs(int nodeRow, int nodeCol, vector<vector<bool>> &visited, vector<vector<char>> &grid)
    {
        queue<pair<int, int>> q;
        q.push({nodeRow, nodeCol});
        visited[nodeRow][nodeCol] = true;

        int dRow[] = {-1, 0, 1, 0};
        int dCol[] = {0, 1, 0, -1};

        while (!q.empty())
        {
            int frontRow = q.front().first;
            int frontCol = q.front().second;
            q.pop();

            for (int i = 0; i < 4; i++)
            {
                int nRow = frontRow + dRow[i];
                int nCol = frontCol + dCol[i];

                if (nRow >= 0 && nRow < grid.size() &&
                    nCol >= 0 && nCol < grid[0].size() &&
                    grid[nRow][nCol] == '1' && !visited[nRow][nCol])
                {
                    visited[nRow][nCol] = true;
                    q.push({nRow, nCol});
                }
            }
        }
    }

    int numIslands(vector<vector<char>> &grid)
    {
        int numOfIslands = 0;
        vector<vector<bool>> visited(grid.size(), vector<bool>(grid[0].size(), false));

        for (int i = 0; i < grid.size(); i++)
        {
            for (int j = 0; j < grid[0].size(); j++)
            {
                if (grid[i][j] == '1' && !visited[i][j])
                {
                    bfs(i, j, visited, grid);
                    numOfIslands++;
                }
            }
        }
        return numOfIslands;
    }
};