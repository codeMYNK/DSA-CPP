// GfG Problem : Directed Graph Cycle(Medium)

/*
Given a Directed Graph with V vertices (Numbered from 0 to V-1) and E edges, check whether it contains any cycle or not.
The graph is represented as a 2D vector edges[][], where each entry edges[i] = [u, v] denotes an edge from verticex u to v.

Examples:

Input: V = 4, edges[][] = [[0, 1], [0, 2], [1, 2], [2, 0], [2, 3]]

Output: true
Explanation: The diagram clearly shows a cycle 0 → 2 → 0
Input: V = 4, edges[][] = [[0, 1], [0, 2], [1, 2], [2, 3]

Output: false
Explanation: no cycle in the graph
Constraints:
1 ≤ V, E ≤ 105
*/

#include <bits/stdc++.h>

using namespace std;

class Solution
{
public:
    bool isCyclicDFS(int node, unordered_map<int, bool> &visited, unordered_map<int, bool> &dfsVisited, unordered_map<int, list<int>> &adj)
    {
        visited[node] = true;
        dfsVisited[node] = true;

        for (auto neighbour : adj[node])
        {
            if (!visited[neighbour])
            {
                bool cycleDetected = isCyclicDFS(neighbour, visited, dfsVisited, adj);
                if (cycleDetected)
                    return true;
            }
            else if (dfsVisited[neighbour])
            {
                return true;
            }
        }
        dfsVisited[node] = false;
        return false;
    }
    bool isCyclic(int V, vector<vector<int>> &edges)
    {
        // code here
        unordered_map<int, list<int>> adj;

        for (int i = 0; i < edges.size(); i++)
        {
            int u = edges[i][0];
            int v = edges[i][1];
            adj[u].push_back(v);
        }

        unordered_map<int, bool> visited;
        unordered_map<int, bool> dfsVisited;

        for (int i = 1; i <= V; i++)
        {
            if (!visited[i])
            {
                bool cycleDetected = isCyclicDFS(i, visited, dfsVisited, adj);
                if (cycleDetected)
                    return true;
            }
        }
        return false;
    }
};