// Problem: Minimum Spanning Tree using Kruskal's algorithm + DSU (Union-Find)
// Description:
//   Given an undirected weighted graph, compute MST weight and edges using Kruskal's algorithm.
//   DSU supports union by rank and path compression.
//
// Complexity:
//   Sorting edges: O(E log E)
//   DSU operations: ~O(alpha(N)) each
//   Overall: O(E log E)

#include <bits/stdc++.h>
using namespace std;

struct DSU {
    int n;
    vector<int> parent, rankv;
    DSU(int n): n(n), parent(n), rankv(n, 0) {
        iota(parent.begin(), parent.end(), 0);
    }
    int find(int x) {
        if (parent[x] != x) parent[x] = find(parent[x]);
        return parent[x];
    }
    bool unite(int a, int b) {
        a = find(a); b = find(b);
        if (a == b) return false;
        if (rankv[a] < rankv[b]) swap(a, b);
        parent[b] = a;
        if (rankv[a] == rankv[b]) rankv[a]++;
        return true;
    }
};

struct Edge {
    int u, v;
    long long w;
    bool operator<(const Edge& other) const { return w < other.w; }
};

pair<long long, vector<Edge>> kruskal(int n, vector<Edge>& edges) {
    sort(edges.begin(), edges.end());
    DSU dsu(n);
    long long total = 0;
    vector<Edge> mst;
    for (auto &e : edges) {
        if (dsu.unite(e.u, e.v)) {
            total += e.w;
            mst.push_back(e);
        }
    }
    // If MST required to check connectivity: ensure mst.size() == n-1
    return {total, mst};
}

// Example usage
int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    // Example graph:
    // 4 vertices (0..3)
    // edges: (0,1,1), (0,2,4), (1,2,2), (1,3,6), (2,3,3)
    int n = 4;
    vector<Edge> edges = {
        {0,1,1},
        {0,2,4},
        {1,2,2},
        {1,3,6},
        {2,3,3}
    };

    auto [weight, mst] = kruskal(n, edges);
    cout << "MST total weight: " << weight << '\n';
    cout << "Edges in MST:\n";
    for (auto &e : mst) cout << e.u << " - " << e.v << "  (w="<< e.w << ")\n";

    return 0;
}
