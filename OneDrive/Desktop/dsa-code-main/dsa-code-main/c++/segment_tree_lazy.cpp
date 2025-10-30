/*
 * segment_tree_lazy.cpp
 *
 * A C++ implementation of a Segment Tree with Lazy Propagation
 * Supports range updates (e.g. add a value to a range) and range queries (e.g. sum over a range).
 *
 * Usage:
 *  - Build from an initial array.
 *  - Call update(l, r, val) to add `val` to all elements in [l, r].
 *  - Call query(l, r) to get sum (or other associative function) over [l, r].
 *
 * Complexity:
 *  - Build: O(n)
 *  - Update: O(log n)
 *  - Query: O(log n)
 *
 * Example:
 *  vector<long long> arr = {1, 2, 3, 4, 5};
 *  SegmentTree st(arr);
 *  st.update(1, 3, 5);  // add 5 to positions 1,2,3
 *  long long s = st.query(2, 4);
 *  // s = arr[2]+5 + arr[3]+5 + arr[4] = 3+5 + 4+5 + 5 = 27
 */

#include <bits/stdc++.h>
using namespace std;

using ll = long long;

class SegmentTree {
private:
    int n;
    vector<ll> tree;
    vector<ll> lazy;

    void build(int node, int l, int r, const vector<ll>& arr) {
        if (l == r) {
            tree[node] = arr[l];
        } else {
            int mid = (l + r) / 2;
            build(node*2, l, mid, arr);
            build(node*2+1, mid+1, r, arr);
            tree[node] = tree[node*2] + tree[node*2+1];
        }
    }

    void apply(int node, int l, int r, ll val) {
        tree[node] += (r - l + 1) * val;
        lazy[node] += val;
    }

    void pushDown(int node, int l, int r) {
        if (lazy[node] != 0) {
            int mid = (l + r) / 2;
            apply(node*2, l, mid, lazy[node]);
            apply(node*2+1, mid+1, r, lazy[node]);
            lazy[node] = 0;
        }
    }

    ll queryRange(int node, int l, int r, int ql, int qr) {
        if (qr < l || r < ql) {
            return 0;  // neutral for sum
        }
        if (ql <= l && r <= qr) {
            return tree[node];
        }
        pushDown(node, l, r);
        int mid = (l + r) / 2;
        ll left = queryRange(node*2, l, mid, ql, qr);
        ll right = queryRange(node*2+1, mid+1, r, ql, qr);
        return left + right;
    }

    void updateRange(int node, int l, int r, int ul, int ur, ll val) {
        if (ur < l || r < ul) {
            return;
        }
        if (ul <= l && r <= ur) {
            apply(node, l, r, val);
            return;
        }
        pushDown(node, l, r);
        int mid = (l + r) / 2;
        updateRange(node*2, l, mid, ul, ur, val);
        updateRange(node*2+1, mid+1, r, ul, ur, val);
        tree[node] = tree[node*2] + tree[node*2+1];
    }

public:
    SegmentTree(const vector<ll>& arr) {
        n = arr.size();
        tree.assign(4*n, 0);
        lazy.assign(4*n, 0);
        if (n > 0) {
            build(1, 0, n-1, arr);
        }
    }

    // Adds val to all elements in [l, r]
    void update(int l, int r, ll val) {
        updateRange(1, 0, n-1, l, r, val);
    }

    // Returns sum in [l, r]
    ll query(int l, int r) {
        return queryRange(1, 0, n-1, l, r);
    }
};

// Basic demonstration / test
int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n, q;
    cin >> n >> q;
    vector<ll> arr(n);
    for (int i = 0; i < n; i++) {
        cin >> arr[i];
    }

    SegmentTree st(arr);

    while (q--) {
        int type;
        cin >> type;
        if (type == 1) {
            // update
            int l, r;
            ll val;
            cin >> l >> r >> val;
            // assuming 0-based indices input; if input is 1-based, adjust
            st.update(l, r, val);
        } else if (type == 2) {
            int l, r;
            cin >> l >> r;
            ll ans = st.query(l, r);
            cout << ans << "\n";
        }
    }

    return 0;
}
