class Solution {
  public:
      void bfs (vector<vector<int>>& grid, int& count) {
          int r = grid.size();
          int c = grid[0].size();
  
          queue<pair<int, int>> q;
          for (int i = 0; i < r; i++)
              for (int j = 0; j < c; j++) 
                  if (grid[i][j] == 2)
                      q.push(make_pair(i, j));
  
          while (!q.empty()) {
              int current_rotting = q.size();
              while (current_rotting--) {
                  int i = q.front().first;
                  int j = q.front().second;
                  q.pop();
  
                  //ebar 1 gulo k 2 korte hobe next time er jonno
  
                  if (i - 1 >= 0 && grid[i - 1][j] == 1) {
                      grid[i - 1][j] = 2;
                      q.push({i - 1, j});
                  }
  
                  if (i + 1 < r && grid[i + 1][j] == 1) {
                      grid[i + 1][j] = 2;
                      q.push({i + 1, j});
                  }
  
                  if (j - 1 >= 0 && grid[i][j - 1] == 1) {
                      grid[i][j - 1] = 2;
                      q.push({i, j - 1});
                  }
  
                  if (j + 1 < c && grid[i][j + 1] == 1) {
                      grid[i][j + 1] = 2;
                      q.push({i, j + 1});
                  }
              }
              count++;
          }
  
      }
      int orangesRotting(vector<vector<int>>& grid) {
          int count = 0;
  
          bfs(grid, count);
  
          for (int i = 0; i < grid.size(); i++)
              for (int j = 0; j < grid[0].size(); j++) 
                  if (grid[i][j] == 1)
                      return -1;
  
          return count == 0 ? 0 : count-1;
      }
  };