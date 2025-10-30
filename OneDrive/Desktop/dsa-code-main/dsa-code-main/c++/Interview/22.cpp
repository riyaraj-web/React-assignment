#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

/*
Problem: Search a 2D Matrix
Technique: Two-Step Binary Search (First on Rows, then on Columns)
Time Complexity: O(logN + logM)
Space Complexity: O(1)

Description:
Given an m x n integer matrix with the properties that each row is sorted and 
the first element of a row is greater than the last element of the previous row.
Determine if a target value is present in the matrix.
*/

class Solution {
public:
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        if (matrix.empty() || matrix[0].empty()) {
            return false;
        }

        int R = matrix.size();
        int C = matrix[0].size();

        // =======================================================
        // Step 1: Binary Search on Rows (to find the correct row)
        // =======================================================
        int rowStart = 0;
        int rowEnd = R - 1;
        int targetRow = -1;

        while (rowStart <= rowEnd) {
            int rowMid = rowStart + (rowEnd - rowStart) / 2;

            // Check the first and last element of the rowMid
            if (target >= matrix[rowMid][0] && target <= matrix[rowMid][C - 1]) {
                // Found the row where the target must be (if it exists)
                targetRow = rowMid;
                break;
            } else if (target < matrix[rowMid][0]) {
                // Target must be in an earlier row
                rowEnd = rowMid - 1;
            } else { // target > matrix[rowMid][C - 1]
                // Target must be in a later row
                rowStart = rowMid + 1;
            }
        }

        // If no potential row was found, the target is not in the matrix
        if (targetRow == -1) {
            return false;
        }

        // =======================================================
        // Step 2: Binary Search on Columns (search within the targetRow)
        // =======================================================
        int colStart = 0;
        int colEnd = C - 1;
        
        while (colStart <= colEnd) {
            int colMid = colStart + (colEnd - colStart) / 2;

            if (matrix[targetRow][colMid] == target) {
                return true;
            } else if (matrix[targetRow][colMid] < target) {
                // Target is larger, move right
                colStart = colMid + 1;
            } else {
                // Target is smaller, move left
                colEnd = colMid - 1;
            }
        }

        // Target not found in the determined row
        return false;
    }
};

// Test cases
int main() {
    Solution solution;
    
    vector<vector<int>> matrix1 = {
        {1, 3, 5, 7},
        {10, 11, 16, 20},
        {23, 30, 34, 60}
    };
    int target1_found = 11;
    int target1_not_found = 13;

    cout << "Test 1: Target " << target1_found << " found? " 
         << (solution.searchMatrix(matrix1, target1_found) ? "true" : "false") << " (Expected: true)" << endl;
    
    cout << "Test 1: Target " << target1_not_found << " found? " 
         << (solution.searchMatrix(matrix1, target1_not_found) ? "true" : "false") << " (Expected: false)" << endl;

    return 0;
}