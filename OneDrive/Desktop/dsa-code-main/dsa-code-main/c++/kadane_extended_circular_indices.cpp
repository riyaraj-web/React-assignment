// Problems:
//   - Maximum Subarray (Kadane) - LeetCode 53
//   - Maximum Sum Circular Subarray - LeetCode 918
// Description:
//   Provides Kadane's algorithm (returns max sum and start/end indices), and circular variant using
//   either standard approach: max(normal), or total - min-subarray (with care for all-negative case).
//
// Complexity:
//   Time: O(n)
//   Space: O(1)

#include <bits/stdc++.h>
using namespace std;

// Kadane that also returns start and end indices (inclusive)
tuple<long long,int,int> kadaneWithIndices(const vector<int>& a) {
    long long bestSum = LLONG_MIN, curSum = 0;
    int bestL = 0, bestR = 0;
    int curL = 0;
    for (int i = 0; i < (int)a.size(); ++i) {
        if (curSum <= 0) { // start new subarray
            curSum = a[i];
            curL = i;
        } else {
            curSum += a[i];
        }
        if (curSum > bestSum) {
            bestSum = curSum;
            bestL = curL;
            bestR = i;
        }
    }
    return {bestSum, bestL, bestR};
}

// Max circular sum using kadane: max(regular_kadane, total - min_subarray)
// Handles all-negative case by checking if min_subarray==total.
long long maxCircularSubarray(const vector<int>& a) {
    int n = a.size();
    if (n == 0) return 0;
    // Normal max
    auto [maxNormal, l, r] = kadaneWithIndices(a);
    // Compute min-subarray using inverted Kadane
    long long total = 0;
    for (int x : a) total += x;
    // min subarray
    long long minSum = LLONG_MAX, curMin = 0;
    for (int x : a) {
        if (curMin >= 0) curMin = x;
        else curMin += x;
        minSum = min(minSum, curMin);
    }
    if (minSum == total) {
        // all numbers negative -> maxNormal is the answer
        return maxNormal;
    } else {
        return max(maxNormal, total - minSum);
    }
}

// Example usage
int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    vector<int> a1 = {-2,1,-3,4,-1,2,1,-5,4}; // classic
    auto [mx1, L1, R1] = kadaneWithIndices(a1);
    cout << "Kadane max sum: " << mx1 << "  range: [" << L1 << "," << R1 << "]\n";

    vector<int> a2 = {5, -3, 5}; // circular best takes wrap-around
    cout << "Max circular sum for {5,-3,5}: " << maxCircularSubarray(a2) << '\n';

    vector<int> a3 = {-3, -2, -5};
    cout << "All negative array max: " << maxCircularSubarray(a3) << '\n';

    return 0;
}
