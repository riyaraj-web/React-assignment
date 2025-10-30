#include <vector>
#include <iostream>
using namespace std;

int uniquePathsWithObstacles(vector<vector<int>>& obstacleGrid) {
    int m = obstacleGrid.size();
    int n = obstacleGrid[0].size();
    
    // If the starting or ending cell has an obstacle, return 0
    if (obstacleGrid[0][0] == 1 || obstacleGrid[m-1][n-1] == 1) {
        return 0;
    }

    // Initialize a dp array
    vector<vector<int>> dp(m, vector<int>(n, 0));

    // Start at the top-left corner
    dp[0][0] = 1;

    // Fill the dp table
    for (int i = 0; i < m; ++i) {
        for (int j = 0; j < n; ++j) {
            if (obstacleGrid[i][j] == 1) {
                dp[i][j] = 0;  // No paths through obstacles
            } else {
                if (i > 0) dp[i][j] += dp[i-1][j];  // Path from above
                if (j > 0) dp[i][j] += dp[i][j-1];  // Path from left
            }
        }
    }

    return dp[m-1][n-1];  // Return the number of paths to the bottom-right corner
}

int main() {
    vector<vector<int>> obstacleGrid = {
        {0,0,0},
        {0,1,0},
        {0,0,0}
    };
    cout << "Number of unique paths: " << uniquePathsWithObstacles(obstacleGrid) << endl;
    return 0;
}
