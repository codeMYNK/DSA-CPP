// Leetcode Problem No : 221 - Maximal Square(Medium)

/*
Given an m x n binary matrix filled with 0's and 1's, find the largest square containing only 1's and return its area.



Example 1:


Input: matrix = [["1","0","1","0","0"],["1","0","1","1","1"],["1","1","1","1","1"],["1","0","0","1","0"]]
Output: 4
Example 2:


Input: matrix = [["0","1"],["1","0"]]
Output: 1
Example 3:

Input: matrix = [["0"]]
Output: 0


Constraints:

m == matrix.length
n == matrix[i].length
1 <= m, n <= 300
matrix[i][j] is '0' or '1'.
*/

#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

class Solution
{
public:
    // int solve(vector<vector<char>> &matrix, int i, int j, int& maxi){
    //     if(i >= matrix.size() || j >= matrix[0].size())return 0; - recursive approach

    //     int right = solve(matrix, i, j + 1, maxi);
    //     int diagonal = solve(matrix, i + 1, j + 1,maxi);
    //     int bottom = solve(matrix, i + 1, j, maxi);

    //     if(matrix[i][j] == '1'){
    //         int ans = 1 + min(right, min(diagonal,bottom));
    //         maxi = max(maxi, ans);
    //         return ans;
    //     }else return 0;
    // }
    // int solveMem(vector<vector<char>> &matrix, int i, int j, int& maxi, vector<vector<int>> &dp){ - Top Down DP
    //     if(i >= matrix.size() || j >= matrix[0].size())return 0;
    //      if(dp[i][j] != -1) return dp[i][j];

    //     int right = solveMem(matrix, i, j + 1, maxi, dp);
    //     int diagonal = solveMem(matrix, i + 1, j + 1,maxi, dp);
    //     int bottom = solveMem(matrix, i + 1, j, maxi, dp);

    //     if(matrix[i][j] == '1'){
    //         dp[i][j] = 1 + min(right, min(diagonal,bottom));
    //         maxi = max(maxi, dp[i][j]);
    //         return dp[i][j];
    //     }else return dp[i][j] = 0;
    // }

    //     int solveTab(vector<vector<char>>& matrix, int &maxi){ - Bottom Up DP
    //     int rows = matrix.size();
    //     int cols = matrix[0].size();

    //     vector<vector<int>> dp(rows + 1, vector<int>(cols + 1, 0));

    //     for (int i = rows - 1; i >= 0; i--) {
    //         for (int j = cols - 1; j >= 0; j--) {
    //             if (matrix[i][j] == '1') {
    //                 dp[i][j] = 1 + min({dp[i + 1][j], dp[i][j + 1], dp[i + 1][j + 1]});
    //                 maxi = max(maxi, dp[i][j]);
    //             }
    //         }
    //     }
    //     return maxi;
    // }
    int solveSO(vector<vector<char>> &matrix, int &maxi)
    { // Space Optimization
        int rows = matrix.size();
        int cols = matrix[0].size();
        vector<int> curr(cols + 1, 0);
        vector<int> next(cols + 1, 0);

        for (int i = rows - 1; i >= 0; i--)
        {
            for (int j = cols - 1; j >= 0; j--)
            {
                if (matrix[i][j] == '1')
                {
                    curr[j] = 1 + min(next[j], min(curr[j + 1], next[j + 1]));
                    maxi = max(maxi, curr[j]);
                }
                else
                {
                    curr[j] = 0;
                }
            }
            next = curr;
        }
        return maxi;
    }

    int maximalSquare(vector<vector<char>> &matrix)
    {
        int maxi = 0;
        // solve(matrix, 0, 0, maxi);

        // vector<vector<int> > dp(matrix.size(), vector<int>(matrix[0].size(), -1));
        // solveMem(matrix, 0, 0, maxi, dp);
        // solveTab(matrix, maxi);
        solveSO(matrix, maxi);
        return maxi * maxi;
    }
};