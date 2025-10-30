// Bridges in Graph - Using Tarjan's Algorithm of time in and low time: G-55

// Problem Statement : There are n servers numbered from 0 to n - 1 connected by undirected server - to - server connections forming a network where connections[i] = [ ai, bi ] represents a connection between servers ai and bi.Any server can reach other servers directly or indirectly through the network.

//                                                                                                                                                                                                                                                                                A critical connection is a connection that,
//                                                                                                                                                 if removed, will make some servers unable to reach some other servers.

//                                                                                                                                                               Return all critical connections in the network in any order.

//
Note : Here servers mean the nodes of the graph.The problem statement is taken from leetcode.

#include <bits/stdc++.h>
       using namespace std;

class Solution
{
private:
    int timer = 1;
    void dfs(int node, int parent, vector<int> &vis,
             vector<int> adj[], int tin[], int low[], vector<vector<int>> &bridges)
    {
        vis[node] = 1;
        tin[node] = low[node] = timer;
        timer++;
        for (auto it : adj[node])
        {
            if (it == parent)
                continue;
            if (vis[it] == 0)
            {
                dfs(it, node, vis, adj, tin, low, bridges);
                low[node] = min(low[it], low[node]);
                // node --- it
                if (low[it] > tin[node])
                {
                    bridges.push_back({it, node});
                }
            }
            else
            {
                low[node] = min(low[node], low[it]);
            }
        }
    }

public:
    vector<vector<int>> criticalConnections(int n,
                                            vector<vector<int>> &connections)
    {
        vector<int> adj[n];
        for (auto it : connections)
        {
            int u = it[0], v = it[1];
            adj[u].push_back(v);
            adj[v].push_back(u);
        }
        vector<int> vis(n, 0);
        int tin[n];
        int low[n];
        vector<vector<int>> bridges;
        dfs(0, -1, vis, adj, tin, low, bridges);
        return bridges;
    }
};

int main()
{

    int n = 4;
    vector<vector<int>> connections = {
        {0, 1}, {1, 2}, {2, 0}, {1, 3}};

    Solution obj;
    vector<vector<int>> bridges = obj.criticalConnections(n, connections);
    for (auto it : bridges)
    {
        cout << "[" << it[0] << ", " << it[1] << "] ";
    }
    cout << endl;
    return 0;
}
