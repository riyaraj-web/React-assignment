// Problem: Find Bridges and Articulation Points in an undirected graph (Tarjan's algorithm variant)
// Description:
//   Uses DFS with discovery time and low-link times to detect bridges and articulation points.
//   Bridges: edges whose removal increases number of connected components.
//   Articulation points (cut vertices): nodes whose removal increases number of connected components.
//
// Complexity:
//   Time: O(V + E)
//   Space: O(V + E)

#include <bits/stdc++.h>
using namespace std;

struct Tarjan {
    int n;
    vector<vector<int>> adj;
    vector<int> disc, low, parent;
    vector<bool> ap; // articulation points
    vector<pair<int,int>> bridges;
    int timeCounter;

    Tarjan(int n): n(n), adj(n) {
        disc.assign(n, -1);
        low.assign(n, -1);
        parent.assign(n, -1);
        ap.assign(n, false);
        timeCounter = 0;
    }
    void addEdge(int u, int v) {
        adj[u].push_back(v);
        adj[v].push_back(u);
    }
    void dfs(int u) {
        disc[u] = low[u] = ++timeCounter;
        int children = 0;
        for (int v : adj[u]) {
            if (disc[v] == -1) {
                parent[v] = u;
                children++;
                dfs(v);
                low[u] = min(low[u], low[v]);

                // Articulation point rules
                if (parent[u] == -1 && children > 1) ap[u] = true;
                if (parent[u] != -1 && low[v] >= disc[u]) ap[u] = true;

                // Bridge
                if (low[v] > disc[u]) bridges.emplace_back(u, v);
            } else if (v != parent[u]) {
                low[u] = min(low[u], disc[v]);
            }
        }
    }
    void run() {
        for (int i = 0; i < n; ++i) {
            if (disc[i] == -1) dfs(i);
        }
    }
};

// Example usage
int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    // Example graph from classical examples:
    // 5 nodes: edges: 0-1, 1-2, 2-0, 1-3, 3-4
    Tarjan t(5);
    t.addEdge(0,1);
    t.addEdge(1,2);
    t.addEdge(2,0);
    t.addEdge(1,3);
    t.addEdge(3,4);

    t.run();

    cout << "Articulation points:\n";
    for (int i = 0; i < 5; ++i) if (t.ap[i]) cout << i << ' ';
    cout << "\nBridges:\n";
    for (auto &e : t.bridges) cout << e.first << " - " << e.second << '\n';

    return 0;
}
