// GfG Problem : Minimum Spanning Tree (Medium)

/*
Given a weighted, undirected, and connected graph with V vertices and E edges, your task is to find the sum of the weights of the edges in the Minimum Spanning Tree (MST) of the graph. The graph is represented by an adjacency list, where each element adj[i] is a vector containing vector of integers. Each vector represents an edge, with the first integer denoting the endpoint of the edge and the second integer denoting the weight of the edge.

Input:
3 3
0 1 5
1 2 3
0 2 1

Output: 4
Explanation:

The Spanning Tree resulting in a weight
of 4 is shown above.
Input:
2 1
0 1 5



Output: 5

Explanation: Only one Spanning Tree is possible which has a weight of 5.
Constraints:
2 ≤ V ≤ 1000
V-1 ≤ E ≤ (V*(V-1))/2
1 ≤ w ≤ 1000
The graph is connected and doesn't contain self-loops & multiple edges.
*/

#include <bits/stdc++.h>

using namespace std;

class DisjointSet
{
    vector<int> rank, parent, sizeVec;

public:
    DisjointSet(int n)
    {
        rank.resize(n + 1, 0);
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

    void unionByRank(int u, int v)
    {
        int ultParentu = findUParent(u);
        int ultParentv = findUParent(v);

        if (ultParentu == ultParentv)
            return;
        if (rank[ultParentu] < rank[ultParentv])
        {
            parent[ultParentu] = ultParentv;
        }
        else if (rank[ultParentv] < rank[ultParentu])
        {
            parent[ultParentv] = ultParentu;
        }
        else
        {
            parent[ultParentv] = ultParentu;
            rank[ultParentu]++;
        }
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
public:
    // Function to find sum of weights of edges of the Minimum Spanning Tree.
    int spanningTree(int V, vector<vector<int>> adj[])
    {
        // code here
        vector<pair<int, pair<int, int>>> edges;
        for (int i = 0; i < V; i++)
        {
            for (auto it : adj[i])
            {
                int adjNode = it[0];
                int wt = it[1];
                int node = i;
                edges.push_back({wt, {node, adjNode}});
            }
        }
        sort(edges.begin(), edges.end());
        DisjointSet ds(V);
        int mstWt = 0;
        for (auto it : edges)
        {
            int wt = it.first;
            int u = it.second.first;
            int v = it.second.second;

            if (ds.findUParent(u) != ds.findUParent(v))
            {
                mstWt += wt;
                ds.unionBySize(u, v);
            }
        }
        return mstWt;
    }
};