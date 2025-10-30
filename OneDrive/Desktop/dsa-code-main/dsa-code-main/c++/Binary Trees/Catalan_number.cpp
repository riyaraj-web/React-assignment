#include <iostream>
#include <vector>
using namespace std;

int numTrees(int n) {
    vector<long long> dp(n + 1, 0);
    dp[0] = dp[1] = 1; 
    for (int i = 2; i <= n; i++) {
        for (int root = 1; root <= i; root++) {
            dp[i] += dp[root - 1] * dp[i - root];
        }
    }
    return dp[n];
}

int main() {
    int n = 3;
    cout << numTrees(n) << endl; // Output: 5
    return 0;
}
