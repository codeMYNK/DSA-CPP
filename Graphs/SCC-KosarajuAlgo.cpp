// GfG Problem - Strongly Connected(Medium)

/*
Given an adjacency list, adj of Directed Graph, Find the number of strongly connected components in the graph.


Examples :

Input: adj[][] = [[2, 3], [0], [1], [4], []]

Output: 3
Explanation: We can clearly see that there are 3 Strongly Connected Components in the Graph.

Input: adj[][] = [[1], [2], [0]]

Output: 1
Explanation: All of the nodes are connected to each other. So, there's only one SCC.
Input: adj[][] = [[1], []]
Output: 2
Constraints:
2<=adj.size()<=106
0<=edges<=adj.size()-1
*/

#include <bits/stdc++.h>

using namespace std;

// Position this line where user code will be pasted.
class Solution
{
private:
    void dfs(int node, vector<int> &vis, stack<int> &st, vector<vector<int>> &adj)
    {
        vis[node] = 1;
        for (auto it : adj[node])
        {
            if (!vis[it])
            {
                dfs(it, vis, st, adj);
            }
        }
        st.push(node);
    }
    void dfs3(int node, vector<int> &vis, vector<vector<int>> &revAdj)
    {
        vis[node] = 1;
        for (auto it : revAdj[node])
        {
            if (!vis[it])
            {
                dfs3(it, vis, revAdj);
            }
        }
    }

public:
    int kosaraju(vector<vector<int>> &adj)
    {
        // code here
        // Step 1 : Sort the nodes and store them in a stack - Topo
        int V = adj.size();
        vector<int> vis(V, 0);
        stack<int> st;
        for (int i = 0; i < V; i++)
        {
            if (!vis[i])
            {
                dfs(i, vis, st, adj);
            }
        }
        // Step 2 : Reverse the graph
        vector<vector<int>> revAdj(V);
        for (int i = 0; i < V; i++)
        {
            vis[i] = 0;
            for (auto it : adj[i])
            {
                revAdj[it].push_back(i);
            }
        }
        // Step 3 : Perform the DFS on the sorted weights a/c to the reversed Graph
        int count = 0;
        while (!st.empty())
        {
            int node = st.top();
            st.pop();
            if (!vis[node])
            {
                dfs3(node, vis, revAdj);
                count++;
            }
        }
        return count;
    }
};