// Leetcode Problem No : 547  - Number of Provinces(Medium)

/*
There are n cities. Some of them are connected, while some are not. If city a is connected directly with city b, and city b is connected directly with city c, then city a is connected indirectly with city c.

A province is a group of directly or indirectly connected cities and no other cities outside of the group.

You are given an n x n matrix isConnected where isConnected[i][j] = 1 if the ith city and the jth city are directly connected, and isConnected[i][j] = 0 otherwise.

Return the total number of provinces.



Example 1:


Input: isConnected = [[1,1,0],[1,1,0],[0,0,1]]
Output: 2
Example 2:


Input: isConnected = [[1,0,0],[0,1,0],[0,0,1]]
Output: 3


Constraints:

1 <= n <= 200
n == isConnected.length
n == isConnected[i].length
isConnected[i][j] is 1 or 0.
isConnected[i][i] == 1
isConnected[i][j] == isConnected[j][i]
*/

#include <bits/stdc++.h>

using namespace std;

class Solution
{
public:
    void dfs(int node, vector<bool> &visited, vector<vector<int>> &isConnected)
    {
        visited[node] = true;

        for (int i = 0; i < isConnected.size(); i++)
        {
            if (isConnected[node][i] == 1 && !visited[i])
            {
                dfs(i, visited, isConnected);
            }
        }
    }
    int findCircleNum(vector<vector<int>> &isConnected)
    {
        vector<bool> visited(isConnected.size(), false);
        int numOfProvinces = 0;
        for (int i = 0; i < isConnected.size(); i++)
        {
            if (!visited[i])
            {
                dfs(i, visited, isConnected);
                numOfProvinces++;
            }
        }
        return numOfProvinces;
    }
};