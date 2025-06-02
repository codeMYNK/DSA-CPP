// GfG Problem : Number of Ways to Arrive at Destination (Medium)

/*
You are in a city that consists of n intersections numbered from 0 to n - 1 with bi-directional roads between some intersections. The inputs are generated such that you can reach any intersection from any other intersection and that there is at most one road between any two intersections.

You are given an integer n and a 2D integer array roads where roads[i] = [ui, vi, timei] means that there is a road between intersections ui and vi that takes timei minutes to travel. You want to know in how many ways you can travel from intersection 0 to intersection n - 1 in the shortest amount of time.

Return the number of ways you can arrive at your destination in the shortest amount of time. Since the answer may be large, return it modulo 109 + 7.

Example 1:

Input:
n=7, m=10
edges= [[0,6,7],[0,1,2],[1,2,3],[1,3,3],[6,3,3],[3,5,1],[6,5,1],[2,5,1],[0,4,5],[4,6,2]]

Output:
4
Explaination:

The four ways to get there in 7 minutes are:
- 0  6
- 0  4  6
- 0  1  2  5  6
- 0  1  3  5  6


Example 2:

Input:
n=6, m=8
edges= [[0,5,8],[0,2,2],[0,1,1],[1,3,3],[1,2,3],[2,5,6],[3,4,2],[4,5,2]]

Output:
3
Explaination:

The three ways to get there in 8 minutes are:
- 0  5
- 0  2  5
- 0  1  3  4  5


Constraints:
1 <= n <= 200
n - 1 <= roads.length <= n * (n - 1) / 2
roads[i].length == 3
0 <= ui, vi <= n - 1
1 <= timei <= 109
ui != vi
There is at most one road connecting any two intersections.
You can reach any intersection from any other intersection.

Expected Time Complexity: O(M * logN + N)
Expected Space Complexity: O(M+N)
*/

#include <bits/stdc++.h>

using namespace std;

class Solution
{
public:
    int countPaths(int n, vector<vector<int>> &roads)
    {

        int MOD = 1e9 + 7;
        vector<vector<long long>> adjList[n + 1];

        for (int i = 0; i < roads.size(); i++)
        {
            long long u = roads[i][0];
            long long v = roads[i][1];
            long long time = roads[i][2];

            adjList[u].push_back({v, time});
            adjList[v].push_back({u, time});
        }

        vector<long long> ways(n, 0);
        ways[0] = 1;
        vector<long long> dist(n, LLONG_MAX);
        dist[0] = 0;

        priority_queue<vector<long long>, vector<vector<long long>>, greater<vector<long long>>> pq;
        pq.push({0, 0}); // dist, node

        while (!pq.empty())
        {
            auto front = pq.top();
            pq.pop();

            long long d = front[0];
            long long currcity = front[1];

            for (auto &next : adjList[currcity])
            {
                long long nextcity = next[0];
                long long edgeWt = next[1];
                if (d + edgeWt < dist[nextcity])
                {
                    dist[nextcity] = d + edgeWt;
                    pq.push({d + edgeWt, nextcity});
                    ways[nextcity] = ways[currcity] % MOD;
                }
                else if (d + edgeWt == dist[nextcity])
                {
                    ways[nextcity] += (ways[currcity]) % MOD;
                }
            }
        }

        return ways[n - 1] % MOD;
    }
};