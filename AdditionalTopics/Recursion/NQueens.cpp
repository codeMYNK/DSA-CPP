// Leetcode Problem No 51 : N - Queens (Hard)

/*
The n-queens puzzle is the problem of placing n queens on an n x n chessboard such that no two queens attack each other.

Given an integer n, return all distinct solutions to the n-queens puzzle. You may return the answer in any order.

Each solution contains a distinct board configuration of the n-queens' placement, where 'Q' and '.' both indicate a queen and an empty space, respectively.



Example 1:


Input: n = 4
Output: [[".Q..","...Q","Q...","..Q."],["..Q.","Q...","...Q",".Q.."]]
Explanation: There exist two distinct solutions to the 4-queens puzzle as shown above
Example 2:

Input: n = 1
Output: [["Q"]]


Constraints:

1 <= n <= 9

Optimization : Used unordered map for faster comparision reducing the time complexity of isSafe from O(N) to O(1)!
*/

#include <iostream>
#include <vector>
#include <unordered_map>

using namespace std;

class Solution
{
public:
    unordered_map<int, bool> rowCheck;
    unordered_map<int, bool> upperLeftDiagonalCheck;
    unordered_map<int, bool> lowerLeftDiagonalCheck;
    bool isSafe(int row, int col, vector<string> &board, int n)
    {
        // int i = row, j = col;

        // Check left row
        // while (j >= 0) {
        //     if (board[i][j] == 'Q') return false;
        //     j--;
        // }
        if (rowCheck[row] == true)
        {
            return false;
        }

        // Check upper left diagonal
        // i = row, j = col;
        // while (i >= 0 && j >= 0) {
        //     if (board[i][j] == 'Q') return false;
        //     i--;
        //     j--;
        // }
        if (upperLeftDiagonalCheck[n - 1 + col - row] == true)
        {
            return false;
        }

        // Check lower left diagonal
        // i = row, j = col;
        // while (i < n && j >= 0) {
        //     if (board[i][j] == 'Q') return false;
        //     i++;
        //     j--;
        // }
        if (lowerLeftDiagonalCheck[row + col] == true)
        {
            return false;
        }

        return true;
    }

    void solve(vector<string> &board, vector<vector<string>> &result, int col, int n)
    {
        if (col >= n)
        {
            result.push_back(board);
            return;
        }

        for (int row = 0; row < n; row++)
        {
            if (isSafe(row, col, board, n))
            {
                board[row][col] = 'Q';
                rowCheck[row] = true;
                upperLeftDiagonalCheck[n - 1 + col - row] = true;
                lowerLeftDiagonalCheck[row + col] = true;
                solve(board, result, col + 1, n);
                board[row][col] = '.';
                rowCheck[row] = false;
                upperLeftDiagonalCheck[n - 1 + col - row] = false;
                lowerLeftDiagonalCheck[row + col] = false;
            }
        }
    }

    vector<vector<string>> solveNQueens(int n)
    {
        vector<string> board(n, string(n, '.'));
        vector<vector<string>> result;
        solve(board, result, 0, n);
        return result;
    }
};
