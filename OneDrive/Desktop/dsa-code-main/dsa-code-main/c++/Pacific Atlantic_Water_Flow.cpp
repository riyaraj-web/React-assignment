#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    vector<vector<int>> pacificAtlantic(vector<vector<int>>& heights) {
        if (heights.empty()) return {};
        int m = heights.size(), n = heights[0].size();
        vector<vector<bool>> pacific(m, vector<bool>(n, false));
        vector<vector<bool>> atlantic(m, vector<bool>(n, false));

        for (int i = 0; i < m; i++) {
            dfs(heights, pacific, i, 0);
            dfs(heights, atlantic, i, n - 1);
        }
        for (int j = 0; j < n; j++) {
            dfs(heights, pacific, 0, j);
            dfs(heights, atlantic, m - 1, j);
        }

        vector<vector<int>> result;
        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                if (pacific[i][j] && atlantic[i][j])
                    result.push_back({i, j});
            }
        }
        return result;
    }

private:
    void dfs(vector<vector<int>>& heights, vector<vector<bool>>& visited, int i, int j) {
        int m = heights.size(), n = heights[0].size();
        visited[i][j] = true;
        vector<int> dirs = {-1, 0, 1, 0, -1}; // 4 directions

        for (int d = 0; d < 4; d++) {
            int x = i + dirs[d];
            int y = j + dirs[d + 1];
            if (x >= 0 && x < m && y >= 0 && y < n && !visited[x][y] && heights[x][y] >= heights[i][j]) {
                dfs(heights, visited, x, y);
            }
        }
    }
};

int main() {
    Solution sol;
    vector<vector<int>> heights = {
        {1,2,2,3,5},
        {3,2,3,4,4},
        {2,4,5,3,1},
        {6,7,1,4,5},
        {5,1,1,2,4}
    };

    vector<vector<int>> result = sol.pacificAtlantic(heights);
    cout << "Cells that can reach both oceans:\n";
    for (auto &cell : result) {
        cout << "[" << cell[0] << "," << cell[1] << "] ";
    }
    cout << endl;

    return 0;
}
