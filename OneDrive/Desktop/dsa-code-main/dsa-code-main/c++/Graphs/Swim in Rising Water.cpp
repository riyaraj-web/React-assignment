// // Swim in Rising Water
// Problem Statement : You are given an n × n matrix grid where grid[i][j] is the unique elevation of cell(i, j).Rain starts falling at time t = 0. At any later time t ≥ 0, every cell is covered by water to depth t.You may move 4 - directionally(up, down, left, right) between adjacent cells instantaneously iff the elevations of both cells are ≤ t.Starting from the top - left cell(0, 0), return the minimum time t at which you can reach the bottom - right cell(n − 1, n − 1).

#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    // Minimum time to reach bottom right cell
    int swimInWater(vector<vector<int>> &grid)
    {
        // Get grid size
        int n = grid.size();

        // Create a min-heap for cells based on elevation
        priority_queue<vector<int>, vector<vector<int>>, greater<vector<int>>> minHeap;

        // Create visited matrix
        vector<vector<int>> visited(n, vector<int>(n, 0));

        // Push starting cell to heap
        minHeap.push({grid[0][0], 0, 0});
        visited[0][0] = 1;

        // Direction vectors for movement
        vector<pair<int, int>> dirs = {{0, 1}, {1, 0}, {0, -1}, {-1, 0}};

        // Process heap until destination is reached
        while (!minHeap.empty())
        {
            // Extract cell with least elevation
            auto curr = minHeap.top();
            minHeap.pop();
            int elevation = curr[0], r = curr[1], c = curr[2];

            // If destination reached, return elevation
            if (r == n - 1 && c == n - 1)
                return elevation;

            // Explore neighboring cells
            for (auto &dir : dirs)
            {
                int nr = r + dir.first;
                int nc = c + dir.second;

                // Check bounds and if not visited
                if (nr >= 0 && nc >= 0 && nr < n && nc < n && !visited[nr][nc])
                {
                    visited[nr][nc] = 1;
                    minHeap.push({max(elevation, grid[nr][nc]), nr, nc});
                }
            }
        }
        return -1;
    }
};

int main()
{
    vector<vector<int>> grid = {
        {0, 2}, {1, 3}};
    Solution sol;
    cout << "Minimum time to reach destination: " << sol.swimInWater(grid) << endl;
    return 0;
}