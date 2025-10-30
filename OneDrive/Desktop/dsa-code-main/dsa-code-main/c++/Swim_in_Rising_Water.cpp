// You are given an n x n integer matrix grid where each value grid[i][j] represents the elevation at that point (i, j).
//It starts raining, and water gradually rises over time. At time t, the water level is t, meaning any cell with elevation less than equal to t is submerged or reachable.
//You can swim from a square to another 4-directionally adjacent square if and only if the elevation of both squares individually are at most t. You can swim infinite distances in zero time. Of course, you must stay within the boundaries of the grid during your swim.
//Return the minimum time until you can reach the bottom right square (n - 1, n - 1) if you start at the top left square (0, 0).

 


    int swimInWater(vector<vector<int>>& grid) {
        int m = grid.size(), n = grid[0].size();
        priority_queue<tuple<int,int,int>, vector<tuple<int,int,int>>, greater<>> pq;
        vector<pair<int,int>> directions = {{0,1}, {1,0}, {0,-1}, {-1,0}};
        set<pair<int,int>> seen;
        
        pq.push({grid[0][0], 0, 0});
        
        while (!pq.empty()) {
            auto [max_d, r, c] = pq.top();
            pq.pop();
            
            if (seen.count({r, c})) continue;
            seen.insert({r, c});
            
            if (r == m-1 && c == n-1) return max_d;
            
            for (auto [dr, dc] : directions) {
                int nr = r + dr, nc = c + dc;
                if (nr >= 0 && nr < m && nc >= 0 && nc < n && !seen.count({nr, nc})) {
                    int new_d = max(max_d, grid[nr][nc]);
                    pq.push({new_d, nr, nc});
                }
            }
        }
        return -1;
    }
