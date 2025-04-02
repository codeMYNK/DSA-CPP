// Leetcode Problem No 52 : N- Queens II (Hard)
/*
The n-queens puzzle is the problem of placing n queens on an n x n chessboard such that no two queens attack each other.

Given an integer n, return the number of distinct solutions to the n-queens puzzle.



Example 1:


Input: n = 4
Output: 2
Explanation: There are two distinct solutions to the 4-queens puzzle as shown.
Example 2:

Input: n = 1
Output: 1


Constraints:

1 <= n <= 9
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

    bool isSafe(int row, int col, int n)
    {
        if (rowCheck[row] == true)
        {
            return false;
        }
        if (upperLeftDiagonalCheck[n - 1 + col - row] == true)
        {
            return false;
        }
        if (lowerLeftDiagonalCheck[row + col] == true)
        {
            return false;
        }
        return true;
    }

    void solve(vector<string> &board, vector<vector<string>> &result, int col, int n, int &count)
    {
        if (col >= n)
        {
            count++;
            return;
        }

        for (int row = 0; row < n; row++)
        {
            if (isSafe(row, col, n))
            {
                board[row][col] = 'Q';
                rowCheck[row] = true;
                upperLeftDiagonalCheck[n - 1 + col - row] = true;
                lowerLeftDiagonalCheck[row + col] = true;

                solve(board, result, col + 1, n, count);
                board[row][col] = '.';
                rowCheck[row] = false;
                upperLeftDiagonalCheck[n - 1 + col - row] = false;
                lowerLeftDiagonalCheck[row + col] = false;
            }
        }
    }

    int totalNQueens(int n)
    {
        vector<string> board(n, string(n, '.'));
        vector<vector<string>> result;
        int count = 0;
        solve(board, result, 0, n, count);
        return count;
    }
};