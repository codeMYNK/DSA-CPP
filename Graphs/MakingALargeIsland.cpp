// Leetcode Problem No : 827 - Making A Large Island (Hard)

/*
You are given an n x n binary matrix grid. You are allowed to change at most one 0 to be 1.

Return the size of the largest island in grid after applying this operation.

An island is a 4-directionally connected group of 1s.



Example 1:

Input: grid = [[1,0],[0,1]]
Output: 3
Explanation: Change one 0 to 1 and connect two 1s, then we get an island with area = 3.
Example 2:

Input: grid = [[1,1],[1,0]]
Output: 4
Explanation: Change the 0 to 1 and make the island bigger, only one island with area = 4.
Example 3:

Input: grid = [[1,1],[1,1]]
Output: 4
Explanation: Can't change any 0 to 1, only one island with area = 4.


Constraints:

n == grid.length
n == grid[i].length
1 <= n <= 500
grid[i][j] is either 0 or 1.
*/

#include <bits/stdc++.h>

using namespace std;

class DisjointSet
{
public:
    vector<int> parent, sizeVec;
    DisjointSet(int n)
    {
        parent.resize(n + 1);
        for (int i = 0; i < n; i++)
        {
            parent[i] = i;
        }
        sizeVec.resize(n + 1, 1);
    }

    // Path Compression to cache ultimate parent
    int findUParent(int node)
    {
        if (node == parent[node])
        {
            return node;
        }
        return parent[node] = findUParent(parent[node]);
    }

    void unionBySize(int u, int v)
    {
        int ultParentu = findUParent(u);
        int ultParentv = findUParent(v);
        if (ultParentu == ultParentv)
            return;
        if (sizeVec[ultParentu] < sizeVec[ultParentv])
        {
            parent[ultParentu] = ultParentv;
            sizeVec[ultParentv] += sizeVec[ultParentu];
        }
        else
        {
            parent[ultParentv] = ultParentu;
            sizeVec[ultParentu] += sizeVec[ultParentv];
        }
    }
};
class Solution
{
private:
    bool isValid(int nRow, int nCol, int n)
    {
        return nRow >= 0 && nRow < n && nCol >= 0 && nCol < n;
    }

public:
    int largestIsland(vector<vector<int>> &grid)
    {
        int n = grid.size();
        DisjointSet ds(n * n);
        for (int row = 0; row < n; row++)
        {
            for (int col = 0; col < n; col++)
            {
                if (grid[row][col] == 0)
                    continue;
                int dr[] = {-1, 0, +1, 0};
                int dc[] = {0, +1, 0, -1};
                for (int index = 0; index < 4; index++)
                {
                    int nRow = row + dr[index];
                    int nCol = col + dc[index];

                    if (isValid(nRow, nCol, n) && grid[nRow][nCol] == 1)
                    {
                        int nodeNo = row * n + col;
                        int adjNodeNo = nRow * n + nCol;
                        ds.unionBySize(nodeNo, adjNodeNo);
                    }
                }
            }
        }
        int mx = 0;
        for (int row = 0; row < n; row++)
        {
            for (int col = 0; col < n; col++)
            {
                if (grid[row][col] == 1)
                    continue;

                int dr[] = {-1, 0, +1, 0};
                int dc[] = {0, +1, 0, -1};
                set<int> compos;
                for (int index = 0; index < 4; index++)
                {
                    int nRow = row + dr[index];
                    int nCol = col + dc[index];
                    if (isValid(nRow, nCol, n))
                    {
                        if (grid[nRow][nCol] == 1)
                        {
                            compos.insert(ds.findUParent(nRow * n + nCol));
                        }
                    }
                }
                int sizeTotal = 0;
                for (auto it : compos)
                {
                    sizeTotal += ds.sizeVec[it];
                }
                mx = max(mx, sizeTotal + 1);
            }
        }
        for (int cellNo = 0; cellNo < n * n; cellNo++)
        {
            mx = max(mx, ds.sizeVec[ds.findUParent(cellNo)]);
        }
        return mx;
    }
};