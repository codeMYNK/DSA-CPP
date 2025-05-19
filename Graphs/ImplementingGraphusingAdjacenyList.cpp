#include <iostream>
#include <unordered_map>
#include <list>

using namespace std;
template <typename t>

class Graph
{
public:
    unordered_map<t, list<t>> adj;

    void addEdge(t u, t v, bool direction)
    {
        adj[u].push_back(v);
        if (direction == 0)
        {
            adj[v].push_back(u);
        }
    }
    void printGraph()
    {
        for (auto i : adj)
        {
            cout << i.first << " ->";
            for (auto j : i.second)
            {
                cout << j << " ,";
            }
            cout << endl;
        }
    }
};

int main()
{
    int userEdges, userNodes;

    cout << "Enter the number of nodes: ";
    cin >> userNodes;

    cout << "Enter the number of edges: ";
    cin >> userEdges;

    Graph<int> userGraph;
    bool isDirectional;
    cout << "Enter 0 if you want an undirectional graph and 1 if you want a directional graph : ";
    cin >> isDirectional;

    for (int i = 0; i < userEdges; i++)
    {
        int u, v;
        cout << "Enter the value of node : " << endl;
        cin >> u;

        cout << "Enter the value of node : " << endl;
        cin >> v;

        userGraph.addEdge(u, v, isDirectional);
    }

    cout << "The graph you created is below. " << endl;

    userGraph.printGraph();

    return 0;
}