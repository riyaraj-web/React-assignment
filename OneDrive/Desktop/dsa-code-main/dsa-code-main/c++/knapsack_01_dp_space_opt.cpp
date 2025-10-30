// Description:
//   Given n items with weights w[i] and values v[i], and capacity W, choose subset to maximize value
//   without exceeding W. We show a standard DP (2D) and a space-optimized 1D DP approach.
//
// Complexity:
//   2D DP: Time O(n * W), Space O(n * W)
//   1D optimized: Time O(n * W), Space O(W)

#include <bits/stdc++.h>
using namespace std;

// 2D DP (tabulation) - useful to illustrate states
long long knapsack2D(const vector<int>& w, const vector<int>& v, int W) {
    int n = w.size();
    vector<vector<long long>> dp(n+1, vector<long long>(W+1, 0));
    for (int i = 1; i <= n; ++i) {
        for (int cap = 0; cap <= W; ++cap) {
            dp[i][cap] = dp[i-1][cap];
            if (cap >= w[i-1]) dp[i][cap] = max(dp[i][cap], dp[i-1][cap - w[i-1]] + v[i-1]);
        }
    }
    return dp[n][W];
}

// 1D space optimized DP (iterate weights descending to avoid reuse)
long long knapsack1D(const vector<int>& w, const vector<int>& v, int W) {
    int n = w.size();
    vector<long long> dp(W+1, 0);
    for (int i = 0; i < n; ++i) {
        for (int cap = W; cap >= w[i]; --cap) {
            dp[cap] = max(dp[cap], dp[cap - w[i]] + v[i]);
        }
    }
    return dp[W];
}

// Example usage
int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    // Example: 3 items
    vector<int> weights = {3, 4, 6};
    vector<int> values  = {2, 3, 1};
    int W = 8;

    cout << "Knapsack 2D DP result: " << knapsack2D(weights, values, W) << '\n';
    cout << "Knapsack 1D optimized result: " << knapsack1D(weights, values, W) << '\n';

    return 0;
}
