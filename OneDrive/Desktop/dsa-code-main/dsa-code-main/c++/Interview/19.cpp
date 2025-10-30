#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

/*
Problem: Spiral Matrix
Technique: Boundary Tracking/Simulation
Time Complexity: O(N*M) where N=rows, M=cols (visiting each element once)
Space Complexity: O(1) (excluding the output list)

Description:
Given an m x n matrix, return all elements of the matrix in spiral order.
*/

class Solution {
public:
    vector<int> spiralOrder(vector<vector<int>>& matrix) {
        if (matrix.empty() || matrix[0].empty()) {
            return {};
        }

        int rows = matrix.size();
        int cols = matrix[0].size();
        vector<int> result;

        // Initialize boundaries for the matrix traversal
        int top = 0;
        int bottom = rows - 1;
        int left = 0;
        int right = cols - 1;

        // Loop until the boundaries cross (or meet, depending on the implementation)
        while (top <= bottom && left <= right) {

            // 1. Traverse Right (Top Row)
            for (int c = left; c <= right; ++c) {
                result.push_back(matrix[top][c]);
            }
            top++; // Shrink the top boundary

            if (top > bottom) break; // Check for boundary cross

            // 2. Traverse Down (Right Column)
            for (int r = top; r <= bottom; ++r) {
                result.push_back(matrix[r][right]);
            }
            right--; // Shrink the right boundary

            if (left > right) break; // Check for boundary cross

            // 3. Traverse Left (Bottom Row) - Only if there is still a row to traverse
            for (int c = right; c >= left; --c) {
                result.push_back(matrix[bottom][c]);
            }
            bottom--; // Shrink the bottom boundary

            if (top > bottom) break; // Check for boundary cross

            // 4. Traverse Up (Left Column) - Only if there is still a column to traverse
            for (int r = bottom; r >= top; --r) {
                result.push_back(matrix[r][left]);
            }
            left++; // Shrink the left boundary
        }

        return result;
    }
};

// Test cases
void printVector(const vector<int>& vec) {
    cout << "[";
    for (size_t i = 0; i < vec.size(); ++i) {
        cout << vec[i] << (i == vec.size() - 1 ? "" : ", ");
    }
    cout << "]";
}

int main() {
    Solution solution;
    
    // Test 1: 3x3 matrix
    vector<vector<int>> matrix1 = {
        {1, 2, 3},
        {4, 5, 6},
        {7, 8, 9}
    };
    vector<int> result1 = solution.spiralOrder(matrix1); // Expected: [1, 2, 3, 6, 9, 8, 7, 4, 5]
    cout << "Test 1: ";
    printVector(result1);
    cout << " (Expected: [1, 2, 3, 6, 9, 8, 7, 4, 5])" << endl;

    // Test 2: 3x4 matrix
    vector<vector<int>> matrix2 = {
        {1, 2, 3, 4},
        {5, 6, 7, 8},
        {9, 10, 11, 12}
    };
    vector<int> result2 = solution.spiralOrder(matrix2); // Expected: [1, 2, 3, 4, 8, 12, 11, 10, 9, 5, 6, 7]
    cout << "Test 2: ";
    printVector(result2);
    cout << " (Expected: [1, 2, 3, 4, 8, 12, 11, 10, 9, 5, 6, 7])" << endl;

    // Test 3: Single column matrix
    vector<vector<int>> matrix3 = {
        {1},
        {2},
        {3}
    };
    vector<int> result3 = solution.spiralOrder(matrix3); // Expected: [1, 2, 3]
    cout << "Test 3: ";
    printVector(result3);
    cout << " (Expected: [1, 2, 3])" << endl;

    return 0;
}