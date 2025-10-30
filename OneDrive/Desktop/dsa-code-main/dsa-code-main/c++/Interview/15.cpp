#include <iostream>
#include <vector>
#include <algorithm>
#include <climits>

using namespace std;

/*
Problem: Maximum Subarray
Technique: Kadane's Algorithm (Dynamic Programming / Greedy)
Time Complexity: O(N)
Space Complexity: O(1)

Description:
Given an integer array nums, find the subarray with the largest sum, and return its sum.
A subarray is a contiguous non-empty sequence of elements within an array.
*/

class Solution {
public:
    int maxSubArray(vector<int>& nums) {
        if (nums.empty()) {
            // According to the problem constraints, the array contains at least one number.
            // If it were allowed to be empty, we might return 0 or throw an exception.
            // Returning INT_MIN handles the case where all numbers are negative.
            return INT_MIN; 
        }

        // 'currentMax' tracks the maximum sum of the subarray *ending* at the current index.
        // It's the core of the dynamic programming/greedy choice.
        int currentMax = nums[0];
        
        // 'globalMax' tracks the maximum subarray sum found so far across the entire array.
        int globalMax = nums[0];
        
        // Start iterating from the second element (index 1).
        for (int i = 1; i < nums.size(); ++i) {
            int num = nums[i];

            // 1. Kadane's Principle (The Dynamic Choice):
            // For the subarray ending at index i, the maximum sum is either:
            // a) The current element 'num' itself (meaning a new subarray starts here).
            // b) The current element 'num' plus the max sum of the subarray ending at i-1 ('currentMax' before update).
            currentMax = max(num, currentMax + num);

            // 2. Global Update:
            // Check if the newly calculated maximum sum for the subarray ending at i 
            // is greater than the best sum found so far globally.
            globalMax = max(globalMax, currentMax);
        }

        return globalMax;
    }
};

// Test cases
int main() {
    Solution solution;
    
    // Test 1: Classic case
    vector<int> nums1 = {-2, 1, -3, 4, -1, 2, 1, -5, 4};
    int result1 = solution.maxSubArray(nums1); // Expected: 6 (Subarray: [4, -1, 2, 1])
    cout << "Test 1: Max Sum = " << result1 << " (Expected: 6)" << endl;

    // Test 2: Single element
    vector<int> nums2 = {1};
    int result2 = solution.maxSubArray(nums2); // Expected: 1
    cout << "Test 2: Max Sum = " << result2 << " (Expected: 1)" << endl;

    // Test 3: All negative numbers (should return the largest single number)
    vector<int> nums3 = {-2, -3, -1, -5, -4};
    int result3 = solution.maxSubArray(nums3); // Expected: -1
    cout << "Test 3: Max Sum = " << result3 << " (Expected: -1)" << endl;
    
    // Test 4: Positive numbers
    vector<int> nums4 = {5, 4, -1, 7, 8};
    int result4 = solution.maxSubArray(nums4); // Expected: 23 (Subarray: [5, 4, -1, 7, 8])
    cout << "Test 4: Max Sum = " << result4 << " (Expected: 23)" << endl;

    return 0;
}