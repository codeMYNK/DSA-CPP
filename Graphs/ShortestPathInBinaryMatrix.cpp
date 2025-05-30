// Leetcode Problem : 1091 - Shortest Path In Binary Matrix(Medium)

/*
Given an n x n binary matrix grid, return the length of the shortest clear path in the matrix. If there is no clear path, return -1.

A clear path in a binary matrix is a path from the top-left cell (i.e., (0, 0)) to the bottom-right cell (i.e., (n - 1, n - 1)) such that:

All the visited cells of the path are 0.
All the adjacent cells of the path are 8-directionally connected (i.e., they are different and they share an edge or a corner).
The length of a clear path is the number of visited cells of this path.



Example 1:


Input: grid = [[0,1],[1,0]]
Output: 2
Example 2:


Input: grid = [[0,0,0],[1,1,0],[1,1,0]]
Output: 4
Example 3:

Input: grid = [[1,0,0],[1,1,0],[1,1,0]]
Output: -1


Constraints:

n == grid.length
n == grid[i].length
1 <= n <= 100
grid[i][j] is 0 or 1
*/

#include <bits/stdc++.h>

using namespace std;

class Solution
{
public:
    int shortestPathBinaryMatrix(vector<vector<int>> &grid)
    {
        int n = grid.size();
        int m = grid[0].size();

        if (grid[0][0] != 0 || grid[n - 1][m - 1] != 0)
            return -1;
        if (n == 1 && m == 1)
            return 1;

        queue<pair<int, pair<int, int>>> q;
        vector<vector<int>> dist(n, vector<int>(m, 1e9));
        dist[0][0] = 1;
        q.push({1, {0, 0}});

        int drow[] = {-1, -1, -1, 0, +1, +1, +1, 0};
        int dcol[] = {-1, 0, +1, +1, +1, 0, -1, -1};

        while (!q.empty())
        {
            auto it = q.front();
            q.pop();
            int dis = it.first;
            int row = it.second.first;
            int col = it.second.second;

            for (int i = 0; i < 8; i++)
            {
                int nrow = row + drow[i];
                int ncol = col + dcol[i];

                if (nrow >= 0 && nrow < n && ncol >= 0 && ncol < m &&
                    grid[nrow][ncol] == 0 && dis + 1 < dist[nrow][ncol])
                {

                    dist[nrow][ncol] = dis + 1;

                    if (nrow == n - 1 && ncol == m - 1)
                        return dis + 1;

                    q.push({dis + 1, {nrow, ncol}});
                }
            }
        }
        return -1;
    }
};