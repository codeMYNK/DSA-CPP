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

int main()
{
    DisjointSet ds(7);
    ds.unionByRank(1, 2);
    ds.unionByRank(2, 3);
    ds.unionByRank(4, 5);
    ds.unionByRank(6, 7);
    ds.unionByRank(5, 6);
    ds.unionByRank(3, 7);
    return 0;
}