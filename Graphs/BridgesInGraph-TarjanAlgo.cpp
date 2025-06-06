// Leetcode Problem No : 1192 - Critical Connections in a Network(Hard)

/*
There are n servers numbered from 0 to n - 1 connected by undirected server-to-server connections forming a network where connections[i] = [ai, bi] represents a connection between servers ai and bi. Any server can reach other servers directly or indirectly through the network.

A critical connection is a connection that, if removed, will make some servers unable to reach some other server.

Return all critical connections in the network in any order.



Example 1:


Input: n = 4, connections = [[0,1],[1,2],[2,0],[1,3]]
Output: [[1,3]]
Explanation: [[3,1]] is also accepted.
Example 2:

Input: n = 2, connections = [[0,1]]
Output: [[0,1]]


Constraints:

2 <= n <= 105
n - 1 <= connections.length <= 105
0 <= ai, bi <= n - 1
ai != bi
There are no repeated connections.
*/

#include <bits/stdc++.h>

using namespace std;

class Solution
{
private:
    int timer = 1;
    void dfs(int node, int parent, vector<int> &vis, vector<int> adj[], int time[], int lowTime[], vector<vector<int>> &bridges)
    {
        vis[node] = 1;
        time[node] = lowTime[node] = timer;
        timer++;
        for (auto it : adj[node])
        {
            if (it == parent)
                continue;
            if (!vis[it])
            {
                dfs(it, node, vis, adj, time, lowTime, bridges);
                lowTime[node] = min(lowTime[node], lowTime[it]);

                if (lowTime[it] > time[node])
                {
                    bridges.push_back({it, node});
                }
            }
            else
            {
                lowTime[node] = min(lowTime[node], lowTime[it]);
            }
        }
    }

public:
    vector<vector<int>> criticalConnections(int n, vector<vector<int>> &connections)
    {
        vector<int> adj[n];
        for (auto it : connections)
        {
            adj[it[0]].push_back(it[1]);
            adj[it[1]].push_back(it[0]);
        }
        vector<int> vis(n, 0);
        int time[n];
        int lowTime[n];
        vector<vector<int>> bridges;
        dfs(0, -1, vis, adj, time, lowTime, bridges);
        return bridges;
    }
};