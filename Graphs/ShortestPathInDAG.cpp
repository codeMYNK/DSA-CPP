// GfG Problem : Shortest Path in a Directed Acyclic Graph(Medium)

/*
Given a Directed Acyclic Graph of V vertices from 0 to n-1 and a 2D Integer array(or vector) edges[ ][ ] of length E, where there is a directed edge from edge[i][0] to edge[i][1] with a distance of edge[i][2] for all i.

Find the shortest path from src(0) vertex to all the vertices and if it is impossible to reach any vertex, then return -1 for that vertex.

Examples :

Input: V = 4, E = 2, edges = [[0,1,2], [0,2,1]]
Output: [0, 2, 1, -1]
Explanation: Shortest path from 0 to 1 is 0->1 with edge weight 2. Shortest path from 0 to 2 is 0->2 with edge weight 1. There is no way we can reach 3, so it's -1 for 3.
Input: V = 6, E = 7, edges = [[0,1,2], [0,4,1], [4,5,4], [4,2,2], [1,2,3], [2,3,6], [5,3,1]]
Output: [0, 2, 3, 6, 1, 5]
Explanation: Shortest path from 0 to 1 is 0->1 with edge weight 2. Shortest path from 0 to 2 is 0->4->2 with edge weight 1+2=3. Shortest path from 0 to 3 is 0->4->5->3 with edge weight 1+4+1=6. Shortest path from 0 to 4 is 0->4 with edge weight 1.Shortest path from 0 to 5 is 0->4->5 with edge weight 1+4=5.
Constraint:
1 <= V <= 100
1 <= E <= min((N*(N-1))/2,4000)
0 <= edgesi,0, edgesi,1 < n
0 <= edgei,2 <=105


*/

#include <bits/stdc++.h>

using namespace std;

class Solution
{
private:
    void topoSort(int node, vector<pair<int, int>> adj[], int visited[],
                  stack<int> &st)
    {
        visited[node] = 1;
        for (auto it : adj[node])
        {
            int v = it.first;
            if (!visited[v])
                topoSort(v, adj, visited, st);
        }
        st.push(node);
    }

public:
    vector<int> shortestPath(int V, int E, vector<vector<int>> &edges)
    {
        // code here
        vector<pair<int, int>> adj[V];
        for (int i = 0; i < E; i++)
        {
            int u = edges[i][0];
            int v = edges[i][1];
            int wt = edges[i][2];
            adj[u].push_back({v, wt});
        }
        int visited[V] = {0};
        stack<int> st;
        for (int i = 0; i < V; i++)
        {
            if (!visited[i])
            {
                topoSort(i, adj, visited, st);
            }
        }

        vector<int> distance(V, INT_MAX);
        distance[0] = 0;
        while (!st.empty())
        {
            int node = st.top();
            st.pop();

            for (auto it : adj[node])
            {
                int v = it.first;
                int w = it.second;

                if (distance[node] != INT_MAX && distance[node] + w < distance[v])
                {
                    distance[v] = distance[node] + w;
                }
            }
        }
        for (int i = 0; i < V; i++)
        {
            if (distance[i] == INT_MAX)
                distance[i] = -1;
        }
        return distance;
    }
};