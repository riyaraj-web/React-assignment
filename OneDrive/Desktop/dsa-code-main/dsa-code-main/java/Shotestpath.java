import java.util.*;

class Solution {
    public int shortestPathLength(int[][] graph) {
        int n = graph.length;
        if (n == 1) return 0;

        // Each state: (node, bitmask)
        Queue<int[]> q = new LinkedList<>();
        boolean[][] visited = new boolean[n][1 << n];

        // Start BFS from each node
        for (int i = 0; i < n; i++) {
            q.offer(new int[]{i, 1 << i});
            visited[i][1 << i] = true;
        }

        int steps = 0;

        while (!q.isEmpty()) {
            int size = q.size();

            for (int i = 0; i < size; i++) {
                int[] curr = q.poll();
                int node = curr[0];
                int mask = curr[1];

                // If all nodes visited
                if (mask == (1 << n) - 1) {
                    return steps;
                }

                // Explore neighbors
                for (int next : graph[node]) {
                    int nextMask = mask | (1 << next);
                    if (!visited[next][nextMask]) {
                        visited[next][nextMask] = true;
                        q.offer(new int[]{next, nextMask});
                    }
                }
            }
            steps++;
        }

        return -1; // Should never reach
    }
}
