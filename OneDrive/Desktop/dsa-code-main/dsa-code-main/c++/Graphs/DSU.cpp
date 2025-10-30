#include <bits/stdc++.h>
using namespace std;

class DSU
{
    vector<int> parent, rank, size;

public:
    // Constructor
    DSU(int n)
    {
        parent.resize(n + 1);
        rank.resize(n + 1, 0);
        size.resize(n + 1, 1);
        for (int i = 0; i <= n; i++)
        {
            parent[i] = i;
        }
    }

    // Find with path compression
    int findParent(int node)
    {
        if (node == parent[node])
            return node;
        return parent[node] = findParent(parent[node]);
    }

    // Union by rank
    void unionByRank(int u, int v)
    {
        int pu = findParent(u);
        int pv = findParent(v);
        if (pu == pv)
            return;

        if (rank[pu] < rank[pv])
        {
            parent[pu] = pv;
        }
        else if (rank[pv] < rank[pu])
        {
            parent[pv] = pu;
        }
        else
        {
            parent[pv] = pu;
            rank[pu]++;
        }
    }

    // Union by size
    void unionBySize(int u, int v)
    {
        int pu = findParent(u);
        int pv = findParent(v);
        if (pu == pv)
            return;

        if (size[pu] < size[pv])
        {
            parent[pu] = pv;
            size[pv] += size[pu];
        }
        else
        {
            parent[pv] = pu;
            size[pu] += size[pv];
        }
    }
};

int main()
{
    DSU dsu(7);

    dsu.unionBySize(1, 2);
    dsu.unionBySize(2, 3);
    dsu.unionBySize(4, 5);
    dsu.unionBySize(6, 7);
    dsu.unionBySize(5, 6);

    // Check whether 3 and 7 belong to same set
    if (dsu.findParent(3) == dsu.findParent(7))
        cout << "3 and 7 are in the same component\n";
    else
        cout << "3 and 7 are in different components\n";

    dsu.unionBySize(3, 7);

    if (dsu.findParent(3) == dsu.findParent(7))
        cout << "3 and 7 are now in the same component\n";
    else
        cout << "3 and 7 are still in different components\n";

    return 0;
}
