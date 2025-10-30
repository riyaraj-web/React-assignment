// Problem: Topological Sort (Course Schedule II) - LeetCode 210 (and general topological ordering)
// Description:
//   Given a directed acyclic graph (DAG), return a topological ordering of the vertices.
//   Two common approaches: Kahn's algorithm (BFS using indegree) and DFS-based ordering.
// Usage:
//   Demonstrates both approaches. Change graph in main() for other tests.
//
// Complexity:
//   Time: O(V + E)
//   Space: O(V + E)

#include <bits/stdc++.h>
using namespace std;

// Kahn's algorithm (BFS) - returns empty vector if cycle (no topo order)
vector<int> topoKahn(int n, const vector<vector<int>>& adj) {
    vector<int> indeg(n, 0);
    for (int u = 0; u < n; ++u)
        for (int v : adj[u]) indeg[v]++;
    queue<int> q;
    for (int i = 0; i < n; ++i) if (indeg[i] == 0) q.push(i);
    vector<int> order;
    while (!q.empty()) {
        int u = q.front(); q.pop();
        order.push_back(u);
        for (int v : adj[u]) {
            if (--indeg[v] == 0) q.push(v);
        }
    }
    if ((int)order.size() != n) return {}; // cycle detected
    return order;
}

// DFS-based topological sort (works only for DAGs; we detect cycles)
bool dfsTopo(int u, const vector<vector<int>>& adj, vector<int>& vis, vector<int>& order) {
    // vis: 0=unvisited, 1=visiting, 2=visited
    vis[u] = 1;
    for (int v : adj[u]) {
        if (vis[v] == 1) return false; // back-edge -> cycle
        if (vis[v] == 0) {
            if (!dfsTopo(v, adj, vis, order)) return false;
        }
    }
    vis[u] = 2;
    order.push_back(u); // push post-order
    return true;
}

vector<int> topoDFS(int n, const vector<vector<int>>& adj) {
    vector<int> vis(n, 0), order;
    for (int i = 0; i < n; ++i) {
        if (vis[i] == 0) {
            if (!dfsTopo(i, adj, vis, order)) return {}; // cycle
        }
    }
    reverse(order.begin(), order.end());
    return order;
}

// Example usage
int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    // Example graph (DAG):
    // 5 nodes: 0 -> 2, 0 -> 3, 1 -> 3, 1 -> 4, 3 -> 4
    int n = 5;
    vector<vector<int>> adj(n);
    adj[0] = {2, 3};
    adj[1] = {3, 4};
    adj[2] = {};
    adj[3] = {4};
    adj[4] = {};

    auto orderKahn = topoKahn(n, adj);
    cout << "Topological order (Kahn): ";
    if (orderKahn.empty()) cout << "Cycle detected\n";
    else {
        for (int x : orderKahn) cout << x << ' ';
        cout << '\n';
    }

    auto orderDFS = topoDFS(n, adj);
    cout << "Topological order (DFS): ";
    if (orderDFS.empty()) cout << "Cycle detected\n";
    else {
        for (int x : orderDFS) cout << x << ' ';
        cout << '\n';
    }

    return 0;
}
