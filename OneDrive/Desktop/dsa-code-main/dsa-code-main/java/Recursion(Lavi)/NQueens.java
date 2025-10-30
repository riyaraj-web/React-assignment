public class NQueens {
  /**
   * The n-queens puzzle is the problem of placing n queens on an n x n chessboard such that no two
   * queens attack each other. Given an integer n, return the number of distinct solutions to the
   * n-queens puzzle.
   * 
   * Example: 
   * Input n = 4 
   * Output: 2 
   * Explanation: There are two distinct solutions to the 4-queens puzzle as shown below.
   *
   * [
   *   [".Q..",  // Solution 1
   *    "...Q",
   *    "Q...",
   *    "..Q."],
   *   ["..Q.",  // Solution 2
   *    "Q...",
   *    "...Q",
   *    ".Q.."
   *    ]
   * ]
   * 
   * Constraints:
   * 1. 1 <= n <= 9
   * 2. You may assume that n is a positive integer.
   *
   * @param n - The size of the chessboard and the number of queens to place.
   * @returns int - The number of distinct solutions to the n-queens puzzle.
   **/
  public int totalNQueens(int n) {
    return placeQueens(new boolean[n][n], n, 0);
  }

  private int placeQueens(boolean[][] board, int n, int r) {
    if (r == n) {
      return 1; // found one valid arrangement
    }

    int count = 0;
    for (int c = 0; c < n; c++) {
      if (isSafe(board, r, c, n)) {
        board[r][c] = true;
        count += placeQueens(board, n, r + 1);
        board[r][c] = false; // backtrack
      }
    }
    return count;
  }

  private boolean isSafe(boolean[][] board, int r, int c, int n) {
    // check column
    for (int i = 0; i < r; i++) {
      if (board[i][c]) {
        return false;
      }
    }

    // check left diagonal
    for (int i = r - 1, j = c - 1; i >= 0 && j >= 0; i--, j--) {
      if (board[i][j]) {
        return false;
      }
    }

    // check right diagonal
    for (int i = r - 1, j = c + 1; i >= 0 && j < n; i--, j++) {
      if (board[i][j]) {
        return false;
      }
    }

    return true;
  }

  /**
   * Main method for testing the NQueens class.
   */
  public static void main(String[] args) {
    NQueens nQueens = new NQueens();
    assert nQueens.totalNQueens(4) == 2 : "Test case 1 failed";
    assert nQueens.totalNQueens(1) == 1 : "Test case 2 failed";
    assert nQueens.totalNQueens(5) == 10 : "Test case 3 failed";
    System.out.println("all test case passed");
  }
}

