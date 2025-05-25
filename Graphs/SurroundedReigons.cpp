// Leetcode Problem No : 130 - Surrounded Reigons(Medium)

/*
You are given an m x n matrix board containing letters 'X' and 'O', capture regions that are surrounded:

Connect: A cell is connected to adjacent cells horizontally or vertically.
Region: To form a region connect every 'O' cell.
Surround: The region is surrounded with 'X' cells if you can connect the region with 'X' cells and none of the region cells are on the edge of the board.
To capture a surrounded region, replace all 'O's with 'X's in-place within the original board. You do not need to return anything.



Example 1:

Input: board = [["X","X","X","X"],["X","O","O","X"],["X","X","O","X"],["X","O","X","X"]]

Output: [["X","X","X","X"],["X","X","X","X"],["X","X","X","X"],["X","O","X","X"]]

Explanation:


In the above diagram, the bottom region is not captured because it is on the edge of the board and cannot be surrounded.

Example 2:

Input: board = [["X"]]

Output: [["X"]]



Constraints:

m == board.length
n == board[i].length
1 <= m, n <= 200
board[i][j] is 'X' or 'O'.
*/

#include <bits/stdc++.h>

using namespace std;

class Solution
{
private:
    void dfs(int row, int col, vector<vector<int>> &visited, vector<vector<char>> &board, int delRow[], int delCol[])
    {
        int n = board.size();
        int m = board[0].size();
        visited[row][col] = 1;

        for (int i = 0; i < 4; i++)
        {
            int nRow = row + delRow[i];
            int nCol = col + delCol[i];

            if (nRow >= 0 && nRow < n && nCol >= 0 && nCol < m && !visited[nRow][nCol] && board[nRow][nCol] == 'O')
            {
                dfs(nRow, nCol, visited, board, delRow, delCol);
            }
        }
    }

public:
    void solve(vector<vector<char>> &board)
    {
        int n = board.size();
        int m = board[0].size();
        int delRow[] = {-1, 0, +1, 0};
        int delCol[] = {0, +1, 0, -1};
        vector<vector<int>> visited(n, vector<int>(m, 0));

        for (int j = 0; j < m; j++)
        {
            if (!visited[0][j] && board[0][j] == 'O')
            {
                dfs(0, j, visited, board, delRow, delCol);
            }
            if (!visited[n - 1][j] && board[n - 1][j] == 'O')
            {
                dfs(n - 1, j, visited, board, delRow, delCol);
            }
        }

        for (int i = 0; i < n; i++)
        {
            if (!visited[i][0] && board[i][0] == 'O')
            {
                dfs(i, 0, visited, board, delRow, delCol);
            }
            if (!visited[i][m - 1] && board[i][m - 1] == 'O')
            {
                dfs(i, m - 1, visited, board, delRow, delCol);
            }
        }

        for (int i = 0; i < n; i++)
        {
            for (int j = 0; j < m; j++)
            {
                if (!visited[i][j] && board[i][j] == 'O')
                {
                    board[i][j] = 'X';
                }
            }
        }
    }
};