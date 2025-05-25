// Leetcode Problem No : 1020 - Nummber of Enclaves(Medium)

/*
You are given an m x n binary matrix grid, where 0 represents a sea cell and 1 represents a land cell.

A move consists of walking from one land cell to another adjacent (4-directionally) land cell or walking off the boundary of the grid.

Return the number of land cells in grid for which we cannot walk off the boundary of the grid in any number of moves.



Example 1:


Input: grid = [[0,0,0,0],[1,0,1,0],[0,1,1,0],[0,0,0,0]]
Output: 3
Explanation: There are three 1s that are enclosed by 0s, and one 1 that is not enclosed because its on the boundary.
Example 2:


Input: grid = [[0,1,1,0],[0,0,1,0],[0,0,1,0],[0,0,0,0]]
Output: 0
Explanation: All 1s are either on the boundary or can reach the boundary.


Constraints:

m == grid.length
n == grid[i].length
1 <= m, n <= 500
grid[i][j] is either 0 or 1.
*/

#include <bits/stdc++.h>

using namespace std;

class Solution
{
private:
    void bfs(int r, int c, queue<pair<int, int>> &q, vector<vector<int>> &visited, vector<vector<int>> &grid, int delRow[], int delCol[])
    {
        visited[r][c] = 1;
        q.push({r, c});
        int n = grid.size();
        int m = grid[0].size();

        while (!q.empty())
        {
            int row = q.front().first;
            int col = q.front().second;
            q.pop();
            for (int i = 0; i < 4; i++)
            {
                int nRow = row + delRow[i];
                int nCol = col + delCol[i];

                if (nRow >= 0 && nRow < n && nCol >= 0 && nCol < m && !visited[nRow][nCol] && grid[nRow][nCol] == 1)
                {
                    visited[nRow][nCol] = 1;
                    q.push({nRow, nCol});
                }
            }
        }
    }

public:
    int numEnclaves(vector<vector<int>> &grid)
    {
        int n = grid.size();
        int m = grid[0].size();
        int delRow[] = {-1, 0, +1, 0};
        int delCol[] = {0, +1, 0, -1};
        vector<vector<int>> visited(n, vector<int>(m, 0));
        queue<pair<int, int>> q;
        int ans = 0;

        for (int j = 0; j < m; j++)
        {
            if (!visited[0][j] && grid[0][j] == 1)
            {
                bfs(0, j, q, visited, grid, delRow, delCol);
            }
            if (!visited[n - 1][j] && grid[n - 1][j] == 1)
            {
                bfs(n - 1, j, q, visited, grid, delRow, delCol);
            }
        }

        for (int i = 0; i < n; i++)
        {
            if (!visited[i][0] && grid[i][0] == 1)
            {
                bfs(i, 0, q, visited, grid, delRow, delCol);
            }
            if (!visited[i][m - 1] && grid[i][m - 1] == 1)
            {
                bfs(i, m - 1, q, visited, grid, delRow, delCol);
            }
        }

        for (int i = 0; i < n; i++)
        {
            for (int j = 0; j < m; j++)
            {
                if (!visited[i][j] && grid[i][j] == 1)
                {
                    ans = ans + 1;
                }
            }
        }
        return ans;
    }
};