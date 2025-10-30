// LeetCode 200: Number of Islands
// Issue #1063
// Solved using Depth First Search (DFS)
// Time Complexity: O(m * n)

#include <iostream>
#include <vector>

using namespace std;

class Solution {
private:
    /**
     * @brief Helper function to perform DFS on the grid.
     * This function will "sink" an island by turning all '1's to '0's.
     * @param grid The 2D grid of land and water.
     * @param r The current row index.
     * @param c The current column index.
     */
    void dfs(vector<vector<char>>& grid, int r, int c) {
        int numRows = grid.size();
        int numCols = grid[0].size();

        // Base cases (check for out-of-bounds or if it's water)
        if (r < 0 || c < 0 || r >= numRows || c >= numCols || grid[r][c] == '0') {
            return;
        }

        // Mark the current cell as visited (sink it)
        grid[r][c] = '0';

        // Recursively call DFS on all 4 neighbors
        dfs(grid, r + 1, c); // down
        dfs(grid, r - 1, c); // up
        dfs(grid, r, c + 1); // right
        dfs(grid, r, c - 1); // left
    }

public:
    /**
     * @brief Counts the number of islands in a 2D grid.
     * @param grid The 2D grid of '1's (land) and '0's (water).
     * @return The total number of islands.
     */
    int numIslands(vector<vector<char>>& grid) {
        if (grid.empty() || grid[0].empty()) {
            return 0;
        }

        int numRows = grid.size();
        int numCols = grid[0].size();
        int islandCount = 0;

        // Iterate through every cell in the grid
        for (int i = 0; i < numRows; ++i) {
            for (int j = 0; j < numCols; ++j) {
                // If we find land ('1'), it's a new island
                if (grid[i][j] == '1') {
                    islandCount++;
                    // Use DFS to sink the entire island so we don't count it again
                    dfs(grid, i, j);
                }
            }
        }

        return islandCount;
    }
};

// Main function to test the code
int main() {
    Solution sol;

    // Test Case 1
    vector<vector<char>> grid1 = {
        {'1', '1', '1', '1', '0'},
        {'1', '1', '0', '1', '0'},
        {'1', '1', '0', '0', '0'},
        {'0', '0', '0', '0', '0'}
    };
    cout << "Test Case 1: Number of Islands = " << sol.numIslands(grid1) << endl; // Expected: 1

    // Test Case 2 (Create a copy as numIslands modifies the grid)
    vector<vector<char>> grid2 = {
        {'1', '1', '0', '0', '0'},
        {'1', '1', '0', '0', '0'},
        {'0', '0', '1', '0', '0'},
        {'0', '0', '0', '1', '1'}
    };
    cout << "Test Case 2: Number of Islands = " << sol.numIslands(grid2) << endl; // Expected: 3

    return 0;
}