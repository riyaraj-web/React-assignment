/**
 * Maximum Subarray Sum - Kadane's Algorithm
 * Finds the contiguous subarray with the largest sum.
 */
public class MaximumSubarraySum {
    
    // Kadane's Algorithm - O(n) time, O(1) space
    public int maxSubarraySum(int[] arr) {
        int maxSum = arr[0];
        int currentSum = arr[0];
        
        for (int i = 1; i < arr.length; i++) {
            currentSum = Math.max(arr[i], currentSum + arr[i]);
            maxSum = Math.max(maxSum, currentSum);
        }
        
        return maxSum;
    }
    
    // Returns both sum and the actual subarray indices
    public Result maxSubarrayWithIndices(int[] arr) {
        int maxSum = arr[0];
        int currentSum = arr[0];
        int start = 0, end = 0, tempStart = 0;
        
        for (int i = 1; i < arr.length; i++) {
            if (arr[i] > currentSum + arr[i]) {
                currentSum = arr[i];
                tempStart = i;
            } else {
                currentSum += arr[i];
            }
            
            if (currentSum > maxSum) {
                maxSum = currentSum;
                start = tempStart;
                end = i;
            }
        }
        
        return new Result(maxSum, start, end);
    }
    
    // Helper class to return result with indices
    public static class Result {
        int sum;
        int startIndex;
        int endIndex;
        
        public Result(int sum, int startIndex, int endIndex) {
            this.sum = sum;
            this.startIndex = startIndex;
            this.endIndex = endIndex;
        }
        
        @Override
        public String toString() {
            return "Sum: " + sum + ", Start: " + startIndex + ", End: " + endIndex;
        }
    }
    
    public static void main(String[] args) {
        MaximumSubarraySum solver = new MaximumSubarraySum();
        
        // Test case 1
        int[] arr1 = {2, 3, -8, 7, -1, 2, 3};
        System.out.println("Array: [2, 3, -8, 7, -1, 2, 3]");
        System.out.println("Max sum: " + solver.maxSubarraySum(arr1));
        System.out.println("With indices: " + solver.maxSubarrayWithIndices(arr1));
        
        // Test case 2
        int[] arr2 = {-2, -4};
        System.out.println("\nArray: [-2, -4]");
        System.out.println("Max sum: " + solver.maxSubarraySum(arr2));
        
        // Test case 3
        int[] arr3 = {5, 4, 1, 7, 8};
        System.out.println("\nArray: [5, 4, 1, 7, 8]");
        System.out.println("Max sum: " + solver.maxSubarraySum(arr3));
    }
}