public class nQueen_OneSolution {
    static int count = 0;

    public static void main(String args[]) {
        int n = 4;
        char board[][] = new char[n][n];
        int row = 0;

        // initialize
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++) {
                board[i][j] = '.';
            }
        }

        // Find one solution
        if (nQueenOne(board, row)) {
            System.out.println("Solution is possible");
            printBoard(board);
        } else {
            System.out.println("Solution is not possible");
        }

        // Count all solutions
        count = 0; // reset
        nQueenAll(board, 0);
        System.out.println("Total number of boards for n queens: " + count);
    }

    public static void printBoard(char board[][]) {
        System.out.println("----------chess board--------------");
        for (int i = 0; i < board.length; i++) {
            for (int j = 0; j < board.length; j++) {
                System.out.print(board[i][j] + " ");
            }
            System.out.println();
        }
    }

    // Find ONE solution
    public static boolean nQueenOne(char board[][], int row) {
        if (row == board.length) {
            return true;
        }

        for (int j = 0; j < board.length; j++) {
            if (isSafe(board, row, j)) {
                board[row][j] = 'Q';
                if (nQueenOne(board, row + 1)) {
                    return true;
                }
                board[row][j] = '.'; // backtrack
            }
        }
        return false;
    }

    // Count ALL solutions
    public static void nQueenAll(char board[][], int row) {
        if (row == board.length) {
            count++;
            return;
        }

        for (int j = 0; j < board.length; j++) {
            if (isSafe(board, row, j)) {
                board[row][j] = 'Q';
                nQueenAll(board, row + 1);
                board[row][j] = '.';
            }
        }
    }

    public static boolean isSafe(char board[][], int row, int col) {
        // column check
        for (int i = row - 1; i >= 0; i--) {
            if (board[i][col] == 'Q') {
                return false;
            }
        }
        // left diagonal
        for (int i = row - 1, j = col - 1; i >= 0 && j >= 0; i--, j--) {
            if (board[i][j] == 'Q') {
                return false;
            }
        }
        // right diagonal
        for (int i = row - 1, j = col + 1; i >= 0 && j < board.length; i--, j++) {
            if (board[i][j] == 'Q') {
                return false;
            }
        }
        return true;
    }
}
