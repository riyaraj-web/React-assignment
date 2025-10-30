// dsu.hpp
// Simple header-only Disjoint Set Union (Union-Find) with path compression & union by size.
// Author: <your-name>
// License: MIT (add LICENSE file in repo)

#ifndef DSU_HPP
#define DSU_HPP

#include <vector>
#include <stdexcept>

class DSU {
public:
    explicit DSU(int n): parent(n), size_(n,1) {
        if (n < 0) throw std::invalid_argument("n must be non-negative");
        for (int i = 0; i < n; ++i) parent[i] = i;
    }

    // Find representative (with path compression)
    int find(int x) {
        validate(x);
        if (parent[x] != x) parent[x] = find(parent[x]);
        return parent[x];
    }

    // Unite sets containing a and b. Returns true if merged, false if already same set.
    bool unite(int a, int b) {
        validate(a); validate(b);
        int ra = find(a), rb = find(b);
        if (ra == rb) return false;
        // union by size: attach smaller to larger
        if (size_[ra] < size_[rb]) std::swap(ra, rb);
        parent[rb] = ra;
        size_[ra] += size_[rb];
        return true;
    }

    // Returns size of the set containing x
    int set_size(int x) {
        validate(x);
        return size_[find(x)];
    }

    // Are a and b in same set?
    bool same(int a, int b) {
        validate(a); validate(b);
        return find(a) == find(b);
    }

private:
    std::vector<int> parent;
    std::vector<int> size_;

    void validate(int x) const {
        if (x < 0 || x >= static_cast<int>(parent.size()))
            throw std::out_of_range("index out of range");
    }
};

#endif // DSU_HPP
