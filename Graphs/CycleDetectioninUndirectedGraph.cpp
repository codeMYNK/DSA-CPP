// GfG Problem : Undirected Graph Cycle (Medium)

/*
Given an undirected graph with V vertices and E edges, represented as a 2D vector edges[][], where each entry edges[i] = [u, v] denotes an edge between vertices u and v, determine whether the graph contains a cycle or not.

Examples:

Input: V = 4, E = 4, edges[][] = [[0, 1], [0, 2], [1, 2], [2, 3]]
Output: true
Explanation:

1 -> 2 -> 0 -> 1 is a cycle.
Input: V = 4, E = 3, edges[][] = [[0, 1], [1, 2], [2, 3]]
Output: false
Explanation:

No cycle in the graph.
Constraints:
1 ≤ V ≤ 105
1 ≤ E = edges.size() ≤ 105
*/
#include <bits/stdc++.h>

using namespace std;

class Solution
{
public:
    bool isCyclicBFS(int src, unordered_map<int, bool> &visited, unordered_map<int, list<int>> &adj)
    {
        unordered_map<int, int> parent;
        parent[src] = -1;
        visited[src] = true;

        queue<int> q;
        q.push(src);

        while (!q.empty())
        {
            int frontNode = q.front();
            q.pop();

            for (auto neighbour : adj[frontNode])
            {
                if (visited[neighbour] && neighbour != parent[frontNode])
                {
                    return true;
                }
                else if (!visited[neighbour])
                {
                    q.push(neighbour);
                    visited[neighbour] = true;
                    parent[neighbour] = frontNode;
                }
            }
        }

        return false;
    }

    bool isCyclicDFS(int node, int parent, unordered_map<int, bool> &visited, unordered_map<int, list<int>> &adj)
    {
        visited[node] = true;
        for (auto neighbour : adj[node])
        {
            if (!visited[neighbour])
            {
                bool cycleDetected = isCyclicDFS(neighbour, node, visited, adj);
                if (cycleDetected)
                    return true;
            }
            else if (neighbour != parent)
            {
                return true;
            }
        }
        return false;
    }

    bool isCycle(int V, vector<vector<int>> &edges)
    {
        unordered_map<int, list<int>> adj;

        for (auto &edge : edges)
        {
            int u = edge[0];
            int v = edge[1];
            adj[u].push_back(v);
            adj[v].push_back(u);
        }

        unordered_map<int, bool> visited;

        for (int i = 0; i < V; i++)
        {
            if (!visited[i])
            {
                // if (isCyclicBFS(i, visited, adj)) {
                //     return true;
                // }
                if (isCyclicDFS(i, -1, visited, adj))
                {
                    return true;
                }
            }
        }

        return false;
    }
};