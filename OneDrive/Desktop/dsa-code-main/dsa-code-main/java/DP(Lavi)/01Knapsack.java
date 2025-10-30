import java.util.Scanner;

/**
 * Demonstrates the 0/1 Knapsack problem using dynamic programming.
 */
public final class KnapsackSolver {

  private KnapsackSolver() {
    // Private constructor to prevent instantiation.
  }

  /**
   * Solves the 0/1 Knapsack problem.
   *
   * @param weights an array of item weights
   * @param values an array of item values
   * @param capacity the maximum weight capacity of the knapsack
   * @return the maximum value achievable
   */
  public static int knapsack(int[] weights, int[] values, int capacity) {
    int n = weights.length;
    int[][] dp = new int[n + 1][capacity + 1];

    // Build the DP table
    for (int i = 1; i <= n; i++) {
      for (int w = 0; w <= capacity; w++) {
        if (weights[i - 1] <= w) {
          dp[i][w] = Math.max(values[i - 1] + dp[i - 1][w - weights[i - 1]], dp[i - 1][w]);
        } else {
          dp[i][w] = dp[i - 1][w];
        }
      }
    }

    return dp[n][capacity];
  }

  /**
   * Main method to read input and execute the knapsack solver.
   *
   * Input format:
   * First line: number of items n
   * Second line: weights of n items
   * Third line: values of n items
   * Fourth line: capacity of the knapsack
   */
  public static void main(String[] args) {
    Scanner scanner = new Scanner(System.in);

    int n = scanner.nextInt();
    int[] weights = new int[n];
    int[] values = new int[n];

    for (int i = 0; i < n; i++) {
      weights[i] = scanner.nextInt();
    }
    for (int i = 0; i < n; i++) {
      values[i] = scanner.nextInt();
    }

    int capacity = scanner.nextInt();

    int maxValue = knapsack(weights, values, capacity);
    System.out.println(maxValue);

    scanner.close();
  }
}
