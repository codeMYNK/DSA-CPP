// GfG Problem : Number of Islands(Medium)

/*
You are given a n,m which means the row and column of the 2D matrix and an array of  size k denoting the number of operations. Matrix elements is 0 if there is water or 1 if there is land. Originally, the 2D matrix is all 0 which means there is no land in the matrix. The array has k operator(s) and each operator has two integer A[i][0], A[i][1] means that you can change the cell matrix[A[i][0]][A[i][1]] from sea to island. Return how many island are there in the matrix after each operation.You need to return an array of size k.
Note : An island means group of 1s such that they share a common side.



Example 1:

Input: n = 4
m = 5
k = 4
A = {{1,1},{0,1},{3,3},{3,4}}

Output: 1 1 2 2
Explanation:
0.  00000
    00000
    00000
    00000
1.  00000
    01000
    00000
    00000
2.  01000
    01000
    00000
    00000
3.  01000
    01000
    00000
    00010
4.  01000
    01000
    00000
    00011




Example 2:

Input: n = 4
m = 5
k = 4
A = {{0,0},{1,1},{2,2},{3,3}}

Output: 1 2 3 4
Explanation:
0.  00000
    00000
    00000
    00000
1.  10000
    00000
    00000
    00000
2.  10000
    01000
    00000
    00000
3.  10000
    01000
    00100
    00000
4.  10000
    01000
    00100
    00010


Your Task:
You don't need to read or print anything. Your task is to complete the function numOfIslands() which takes an integer n denoting no. of rows in the matrix, an integer m denoting the number of columns in the matrix and a 2D array of size k denoting  the number of operators.

Expected Time Complexity: O(m * n)
Expected Auxiliary Space: O(m * n)

Constraints:

1 <= n,m <= 100
1 <= k <= 1000


*/

#include <bits/stdc++.h>

using namespace std;

// User function Template for C++
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
    bool isValid(int nRow, int nCol, int n, int m)
    {
        return nRow >= 0 && nRow < n && nCol >= 0 && nCol < m;
    }

public:
    vector<int> numOfIslands(int n, int m, vector<vector<int>> &operators)
    {
        // code here
        DisjointSet ds(n * m);
        int vis[n][m];
        memset(vis, 0, sizeof vis);
        int cnt = 0;
        vector<int> ans;
        for (auto it : operators)
        {
            int row = it[0];
            int col = it[1];
            if (vis[row][col] == 1)
            {
                ans.push_back(cnt);
                continue;
            }
            vis[row][col] = 1;
            cnt++;

            int delRow[] = {-1, 0, +1, 0};
            int delCol[] = {0, +1, 0, -1};
            for (int ind = 0; ind < 4; ind++)
            {
                int nRow = row + delRow[ind];
                int nCol = col + delCol[ind];

                if (isValid(nRow, nCol, n, m))
                {
                    if (vis[nRow][nCol] == 1)
                    {
                        int nodeNo = row * m + col;
                        int adjNodeNo = nRow * m + nCol;
                        if (ds.findUParent(nodeNo) != ds.findUParent(adjNodeNo))
                        {
                            cnt--;
                            ds.unionBySize(nodeNo, adjNodeNo);
                        }
                    }
                }
            }
            ans.push_back(cnt);
        }
        return ans;
    }
};
