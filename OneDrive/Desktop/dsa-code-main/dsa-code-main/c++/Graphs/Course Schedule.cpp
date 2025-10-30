class Solution {
  public:
      bool canFinish(int numCourses, vector<vector<int>>& prerequisites) {
          vector<vector<int>> adj(numCourses);
          vector<int> inDegree(numCourses, 0);
  
          for (int i = 0; i < prerequisites.size(); i++) {
              adj[prerequisites[i][1]].push_back(prerequisites[i][0]);
              //finding indegree
              inDegree[prerequisites[i][0]]++;
          }
  
          //kans algo
  
          queue<int> q;
          for (int i = 0; i < numCourses; i++) {
              if (!inDegree[i]){
                  q.push(i);
              }
          }
          int count = 0;
  
          while (!q.empty()) {
              int node = q.front();
              q.pop();
              count++;
  
              for (int i = 0; i < adj[node].size(); i++) {
                  inDegree[adj[node][i]]--;
                  if (!inDegree[adj[node][i]])
                      q.push(adj[node][i]);
              }
          }
  
          //size == numCourses -> complete all cources
          return count == numCourses;
      }
  };