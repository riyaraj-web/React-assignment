/**
 * Search in a Row and Column Sorted Matrix
 * Time Complexity: O(n + m)
 * Space Complexity: O(1)
 *
 * This program searches for a target element in a matrix
 * where each row and column is sorted in ascending order.
 *
 * Example:
 * Input: target = 39
 * Output: [-1, -1]  (since 39 is not present)
 *
 * Author: Ruturaj Pawar
 * Contributed for Hacktoberfest 2025
 */

import java.util.Arrays;

public class RowColumnSearchInMatrix {
    public static void main(String[] args) {
        int[][] arr = {
                {10,20,30,40},
                {15,25,35,45},
                {28,29,37,49},
                {33,34,38,50}
        };
        System.out.println(Arrays.toString(search(arr, 39)));
    }

    static int[] search(int[][] matrix, int target) {
        int row = 0;
        int col = matrix[0].length - 1;

        while (row < matrix.length && col>= 0) {
            if (matrix[row][col] == target) {
                return new int[]{row, col};
            }
            else if (matrix[row][col] < target) {
                row++;
            }
            else {
                col--;
            }
        }
        return new int[]{-1, -1};
    }
}
