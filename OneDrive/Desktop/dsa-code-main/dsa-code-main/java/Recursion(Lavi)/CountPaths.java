import java.util.*;

public class CountPaths {
  /**
   * Count the number of unique paths from (x, y) to (0, 0) in an m x n grid.
   * 
   * @param m - Number of rows in the grid.
   * @param n - Number of columns in the grid.
   * @param x - Starting row position.
   * @param y - Starting column position.
   * @returns int - Number of unique paths from (x, y) to (0, 0).
   */
  private int helper(int n, int m, int i, int j, int[][] dp) {
    if (i < 0 || j < 0 || i >= n || j >= m) {
      return 0;
    }
    if (i == 0 && j == 0) {
      return 1;
    }
    if (dp[i][j] != -1) {
      return dp[i][j];
    }
    return dp[i][j] = helper(n, m, i - 1, j, dp) + helper(n, m, i, j - 1, dp);
  }

  public int countPaths(int m, int n, int x, int y) {
    if (x == 0 && y == 0) {
      return 0;
    }
    int[][] dp = new int[n][m];
    for (int[] it : dp) {
      Arrays.fill(it, -1);
    }
    return helper(n, m, x, y, dp);
  }

  /**
   * Main method for testing the CountPaths class.
   */
  public static void main(String[] args) {
    CountPaths cp = new CountPaths();

    assert cp.countPaths(3, 3, 2, 2) == 6 : "Test case 1 failed";
    assert cp.countPaths(3, 3, 1, 1) == 2 : "Test case 2 failed";
    assert cp.countPaths(3, 3, 0, 0) == 0 : "Test case 3 failed";
    System.out.println("All test case passed");
  }
}
