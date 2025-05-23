// GfG Problem : Topological Sort(Medium)

/*
Given a Directed Acyclic Graph (DAG) of V (0 to V-1) vertices and E edges represented as a 2D list of edges[][], where each entry edges[i] = [u, v] denotes a directed edge u -> v. Return the topological sort for the given graph.

Topological sorting for Directed Acyclic Graph (DAG) is a linear ordering of vertices such that for every directed edge u -> v, vertex u comes before v in the ordering.
Note: As there are multiple Topological orders possible, you may return any of them. If your returned Topological sort is correct then the output will be true else false.

Examples:

Input: V = 4, E = 3, edges[][] = [[3, 0], [1, 0], [2, 0]]

Output: true
Explanation: The output true denotes that the order is valid. Few valid Topological orders for the given graph are:
[3, 2, 1, 0]
[1, 2, 3, 0]
[2, 3, 1, 0]
Input: V = 6, E = 6, edges[][] = [[1, 3], [2, 3], [4, 1], [4, 0], [5, 0], [5,2]]

Output: true
Explanation: The output true denotes that the order is valid. Few valid Topological orders for the graph are:
[4, 5, 0, 1, 2, 3]
[5, 2, 4, 0, 1, 3]
Constraints:
2  ≤  V  ≤  103
1  ≤  E = edges.size()  ≤  (V * (V - 1)) / 2


*/

#include <bits/stdc++.h>

using namespace std;

class Solution
{
public:
    // void topoSortDFS(int node,unordered_map<int, bool> &visited,stack<int>&s,unordered_map<int, list<int>>&adj){
    //     visited[node] = true;

    //     for(auto neighbour : adj[node]){
    //         if(!visited[neighbour]){
    //             topoSortDFS(neighbour, visited, s, adj);
    //         }
    //     }
    //     s.push(node);
    // }
    vector<int> topoSort(int V, vector<vector<int>> &edges)
    {
        // code here
        unordered_map<int, list<int>> adj;

        for (int i = 0; i < edges.size(); i++)
        {
            int u = edges[i][0];
            int v = edges[i][1];

            adj[u].push_back(v);
        }

        // unordered_map<int, bool> visited;
        // stack<int> s;

        // for(int i = 0; i < V; i++){
        //     if(!visited[i]){
        //         topoSortDFS(i, visited, s, adj);
        //     }
        // }
        // vector<int> ans;
        // while(!s.empty()){
        //     int temp = s.top();
        //     s.pop();
        //     ans.push_back(temp);
        // }
        // return ans;

        vector<int> indegree(V);
        for (auto i : adj)
        {
            for (auto j : i.second)
            {
                indegree[j]++;
            }
        }

        queue<int> q;
        for (int i = 0; i < V; i++)
        {
            if (indegree[i] == 0)
                q.push(i);
        }

        vector<int> ans;
        while (!q.empty())
        {
            int front = q.front();
            q.pop();
            ans.push_back(front);

            for (auto neighbour : adj[front])
            {
                indegree[neighbour]--;

                if (indegree[neighbour] == 0)
                    q.push(neighbour);
            }
        }
        return ans;
    }
};