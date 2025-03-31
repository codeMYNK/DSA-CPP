// GeeksforGeeks Problem : Rat In A Maze(Medium)

/*
Consider a rat placed at position (0, 0) in an n x n square matrix mat. The rat's goal is to reach the destination at position (n-1, n-1). The rat can move in four possible directions: 'U'(up), 'D'(down), 'L' (left), 'R' (right).

The matrix contains only two possible values:

0: A blocked cell through which the rat cannot travel.
1: A free cell that the rat can pass through.
Note: In a path, no cell can be visited more than one time. If the source cell is 0, the rat cannot move to any other cell. In case of no path, return an empty list.+

The task is to find all possible paths the rat can take to reach the destination, starting from (0, 0) and ending at (n-1, n-1), under the condition that the rat cannot revisit any cell along the same path. Furthermore, the rat can only move to adjacent cells that are within the bounds of the matrix and not blocked.

Return the final result vector in lexicographically smallest order.

Examples:

Input: mat[][] = [[1, 0, 0, 0], [1, 1, 0, 1], [1, 1, 0, 0], [0, 1, 1, 1]]
Output: ["DDRDRR", "DRDDRR"]
Explanation: The rat can reach the destination at (3, 3) from (0, 0) by two paths - DRDDRR and DDRDRR, when printed in sorted order we get DDRDRR DRDDRR.
Input: mat[][] = [[1, 0], [1, 0]]
Output: []
Explanation: No path exists and the destination cell is blocked.
Input: mat = [[1, 1, 1], [1, 0, 1], [1, 1, 1]]
Output: ["DDRR", "RRDD"]
Explanation: The rat has two possible paths to reach the destination: 1. "DDRR" 2. "RRDD", These are returned in lexicographically sorted order.
Constraints:
2 ≤ mat.size() ≤ 5
0 ≤ mat[i][j] ≤ 1

Company
*/

#include <iostream>
#include <vector>

using namespace std;

class Solution
{
public:
    bool isSafe(int x, int y, int row, int col, vector<vector<int>> &arr, vector<vector<bool>> &visited)
    {
        if (((x >= 0 && x < row) && (y >= 0 && y < col)) && (arr[x][y] == 1) && (visited[x][y] == false))
        {
            return true;
        }
        else
        {
            return false;
        }
    }

    void solveMaze(vector<vector<int>> &arr, int row, int col, int srcx, int srcy,
                   vector<vector<bool>> &visited, vector<string> &path, string output)
    {
        // Base Case
        if (srcx == row - 1 && srcy == col - 1)
        {
            path.push_back(output);
            return;
        }
        // Checking once for every case

        // Down
        if (isSafe(srcx + 1, srcy, row, col, arr, visited))
        {
            visited[srcx + 1][srcy] = true;
            solveMaze(arr, row, col, srcx + 1, srcy, visited, path, output + 'D');
            visited[srcx + 1][srcy] = false;
        }
        // Left
        if (isSafe(srcx, srcy - 1, row, col, arr, visited))
        {
            visited[srcx][srcy - 1] = true;
            solveMaze(arr, row, col, srcx, srcy - 1, visited, path, output + 'L');
            visited[srcx][srcy - 1] = false;
        }
        // Right
        if (isSafe(srcx, srcy + 1, row, col, arr, visited))
        {
            visited[srcx][srcy + 1] = true;
            solveMaze(arr, row, col, srcx, srcy + 1, visited, path, output + 'R');
            visited[srcx][srcy + 1] = false;
        }
        // Up
        if (isSafe(srcx - 1, srcy, row, col, arr, visited))
        {
            visited[srcx - 1][srcy] = true;
            solveMaze(arr, row, col, srcx - 1, srcy, visited, path, output + 'U');
            visited[srcx - 1][srcy] = false;
        }
    }

    vector<string> findPath(vector<vector<int>> &mat)
    {
        // code here
        int rows = mat.size();
        int cols = mat[0].size();
        vector<vector<bool>> visited(rows, vector<bool>(cols, false));
        visited[0][0] = true;
        vector<string> paths;
        string ans = "";
        solveMaze(mat, rows, cols, 0, 0, visited, paths, ans);
        return paths;
    }
};