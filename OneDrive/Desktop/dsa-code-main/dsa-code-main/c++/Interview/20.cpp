#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

/*
Problem: Rotate Image (Matrix 90 degrees Clockwise)
Technique: In-place Transpose then Reverse
Time Complexity: O(N^2) where N is the dimension of the matrix
Space Complexity: O(1)

Description:
You are given an n x n 2D matrix representing an image, rotate the image by 90 degrees (clockwise).
You have to rotate the image in-place, which means you modify the input 2D matrix directly.
*/

class Solution {
private:
    // Helper function to transpose the matrix in-place
    void transpose(vector<vector<int>>& matrix) {
        int n = matrix.size();
        // Iterate over the upper triangle of the matrix (excluding the main diagonal)
        for (int i = 0; i < n; ++i) {
            for (int j = i + 1; j < n; ++j) {
                // Swap element at (i, j) with element at (j, i)
                swap(matrix[i][j], matrix[j][i]);
            }
        }
    }

    // Helper function to reverse each row of the matrix
    void reverseRows(vector<vector<int>>& matrix) {
        // Use std::reverse for simplicity and clarity.
        for (auto& row : matrix) {
            reverse(row.begin(), row.end());
        }
    }

public:
    void rotate(vector<vector<int>>& matrix) {
        if (matrix.empty()) {
            return;
        }

        // The rotation can be decomposed into two distinct steps:
        
        // Step 1: Transpose the matrix (swap matrix[i][j] with matrix[j][i]).
        // This effectively rotates the matrix 90 degrees counter-clockwise.
        transpose(matrix);

        // Step 2: Reverse each row.
        // Reversing the rows corrects the orientation to a 90-degree clockwise rotation.
        reverseRows(matrix);
    }
};

// Helper function to print the matrix
void printMatrix(const vector<vector<int>>& matrix) {
    for (const auto& row : matrix) {
        cout << "[";
        for (size_t i = 0; i < row.size(); ++i) {
            cout << row[i] << (i == row.size() - 1 ? "" : ", ");
        }
        cout << "]" << endl;
    }
}

// Test cases
int main() {
    Solution solution;
    
    // Test 1: 3x3 matrix
    vector<vector<int>> matrix1 = {
        {1, 2, 3},
        {4, 5, 6},
        {7, 8, 9}
    };
    cout << "Test 1 (Before):" << endl;
    printMatrix(matrix1);
    solution.rotate(matrix1); 
    cout << "Test 1 (After - Expected: [[7, 4, 1], [8, 5, 2], [9, 6, 3]]):" << endl;
    printMatrix(matrix1);
    cout << endl;

    // Test 2: 4x4 matrix
    vector<vector<int>> matrix2 = {
        {5, 1, 9, 11},
        {2, 4, 8, 10},
        {13, 3, 6, 7},
        {15, 14, 12, 16}
    };
    cout << "Test 2 (Before):" << endl;
    printMatrix(matrix2);
    solution.rotate(matrix2); 
    cout << "Test 2 (After - Expected: [[15, 13, 2, 5], [14, 3, 4, 1], [12, 6, 8, 9], [16, 7, 10, 11]]):" << endl;
    printMatrix(matrix2);
    cout << endl;

    return 0;
}