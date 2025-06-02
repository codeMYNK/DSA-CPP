// Leetcode Problem No : 787 - Cheapest Flight Within K Stops (Medium)

/*
 [[0,1,100],[1,2,100],[0,2,500]], src = 0, dst = 2, k = 1
Output: 200
Explanation:
The graph is shown above.
The optimal path with at most 1 stop from city 0 to 2 is marked in red and has cost 100 + 100 = 200.
Example 3:


Input: n = 3, flights = [[0,1,100],[1,2,100],[0,2,500]], src = 0, dst = 2, k = 0
Output: 500
Explanation:
The graph is shown above.
The optimal path with no stops from city 0 to 2 is marked in red and has cost 500.


Constraints:

1 <= n <= 100
0 <= flights.length <= (n * (n - 1) / 2)
flights[i].length == 3
0 <= fromi, toi < n
fromi != toi
1 <= pricei <= 104
There will not be any multiple flights between two cities.
0 <= src, dst, k < n
src != dst
*/

#include <bits/stdc++.h>

using namespace std;

class Solution
{
public:
    int findCheapestPrice(int n, vector<vector<int>> &flights, int src, int dst, int k)
    {
        vector<pair<int, int>> adj[n];

        for (auto it : flights)
        {
            adj[it[0]].push_back({it[1], it[2]});
        }
        queue<pair<int, pair<int, int>>> q;
        vector<int> dist(n, 1e9);
        q.push({0, {src, 0}});
        dist[src] = 0;

        while (!q.empty())
        {
            auto it = q.front();
            q.pop();
            int currStop = it.first;
            int node = it.second.first;
            int cost = it.second.second;

            if (currStop > k)
                continue;

            for (auto it : adj[node])
            {
                int adjNode = it.first;
                int wt = it.second;
                if (wt + cost < dist[adjNode] && currStop <= k)
                {
                    dist[adjNode] = cost + wt;
                    q.push({currStop + 1, {adjNode, cost + wt}});
                }
            }
        }

        if (dist[dst] == 1e9)
            return -1;
        else
            return dist[dst];
    }
};