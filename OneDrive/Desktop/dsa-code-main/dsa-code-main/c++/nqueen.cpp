#include <iostream>
#include <vector>
#include <string>
using namespace std;

class Solution {
public:
    vector<vector<string>> solveNQueens(int n) {
        vector<vector<string>> res;
        vector<string> board(n, string(n, '.'));
        vector<int> leftRow(n, 0), upperDiag(2*n - 1, 0), lowerDiag(2*n - 1, 0);
        solve(0, board, res, leftRow, upperDiag, lowerDiag, n);
        return res;
    }

private:
    void solve(int col, vector<string> &board, vector<vector<string>> &res,
               vector<int> &leftRow, vector<int> &upperDiag, vector<int> &lowerDiag, int n) {
        if (col == n) {
            res.push_back(board);
            return;
        }

        for (int row = 0; row < n; row++) {
            if (leftRow[row] == 0 && lowerDiag[row + col] == 0 && upperDiag[row - col + n - 1] == 0) {
                board[row][col] = 'Q';
                leftRow[row] = 1;
                lowerDiag[row + col] = 1;
                upperDiag[row - col + n - 1] = 1;

                solve(col + 1, board, res, leftRow, upperDiag, lowerDiag, n);

                // Backtrack
                board[row][col] = '.';
                leftRow[row] = 0;
                lowerDiag[row + col] = 0;
                upperDiag[row - col + n - 1] = 0;
            }
        }
    }
};

int main() {
    Solution sol;
    int n;
    cout << "Enter the value of N: ";
    cin >> n;

    if (n < 1) {
        cout << "N must be at least 1\n";
        return 1;
    }

    vector<vector<string>> solutions = sol.solveNQueens(n);

    cout << "\nNumber of solutions: " << solutions.size() << "\n\n";
    
    if (solutions.empty()) {
        cout << "No solutions exist for N = " << n << "\n";
    } else {
        for (int i = 0; i < solutions.size(); i++) {
            cout << "Solution " << (i + 1) << ":\n";
            for (auto &row : solutions[i]) {
                cout << row << "\n";
            }
            cout << "\n";
        }
    }
    
    return 0;
}
