#include <iostream>
#include <vector>
#include <algorithm> // For std::reverse

using namespace std;

/*
Problem: Rotate Array
Technique: Reversal Technique
Time Complexity: O(N)
Space Complexity: O(1)

Description:
Given an integer array nums, rotate the array to the right by k steps, where k 
is non-negative. The rotation must be performed in-place.
*/

class Solution {
private:
    // Helper function to reverse a portion of the vector
    void reverse(vector<int>& nums, int start, int end) {
        // We can use std::reverse, but implementing it manually shows the in-place nature
        while (start < end) {
            swap(nums[start], nums[end]);
            start++;
            end--;
        }
    }

public:
    void rotate(vector<int>& nums, int k) {
        int n = nums.size();
        if (n == 0 || k == 0) return;

        // 1. Handle cases where k > n:
        // The rotation is equivalent to k % n.
        k = k % n;

        // If k is 0 after the modulo operation, no rotation is needed.
        if (k == 0) return;

        // The Reversal Technique involves three steps:
        
        // Step 1: Reverse the last k elements (the part that should go to the front).
        // Indices: [n - k, n - 1]
        // Example: [1, 2, 3, 4, 5, 6, 7], k=3
        // After Step 1: [1, 2, 3, | 7, 6, 5, 4]
        reverse(nums, n - k, n - 1);

        // Step 2: Reverse the first n - k elements (the part that stays at the back).
        // Indices: [0, n - k - 1]
        // Example: [1, 2, 3, | 7, 6, 5, 4]
        // After Step 2: [3, 2, 1, | 7, 6, 5, 4]
        reverse(nums, 0, n - k - 1);
        
        // Step 3: Reverse the entire array.
        // Indices: [0, n - 1]
        // Example: [3, 2, 1, 7, 6, 5, 4]
        // Final Result: [4, 5, 6, 7, 1, 2, 3] (Rotated by 3)
        reverse(nums, 0, n - 1);
    }
};

// Test cases
int main() {
    Solution solution;
    
    // Test 1: k < n
    vector<int> nums1 = {1, 2, 3, 4, 5, 6, 7};
    int k1 = 3;
    solution.rotate(nums1, k1); // Expected: [5, 6, 7, 1, 2, 3, 4]
    cout << "Test 1 (k=3): [";
    for(int i = 0; i < nums1.size(); ++i) {
        cout << nums1[i] << (i == nums1.size() - 1 ? "" : ", ");
    }
    cout << "] (Expected: [5, 6, 7, 1, 2, 3, 4])" << endl;

    // Test 2: k > n
    vector<int> nums2 = {-1, -100, 3, 99};
    int k2 = 5; // Equivalent to k = 5 % 4 = 1
    solution.rotate(nums2, k2); // Expected: [99, -1, -100, 3]
    cout << "Test 2 (k=5): [";
    for(int i = 0; i < nums2.size(); ++i) {
        cout << nums2[i] << (i == nums2.size() - 1 ? "" : ", ");
    }
    cout << "] (Expected: [99, -1, -100, 3])" << endl;
    
    // Test 3: k = 0
    vector<int> nums3 = {1, 2};
    int k3 = 0;
    solution.rotate(nums3, k3); // Expected: [1, 2]
    cout << "Test 3 (k=0): [";
    for(int i = 0; i < nums3.size(); ++i) {
        cout << nums3[i] << (i == nums3.size() - 1 ? "" : ", ");
    }
    cout << "] (Expected: [1, 2])" << endl;

    return 0;
}