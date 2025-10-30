#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

/*
Problem: Remove Duplicates from Sorted Array
Technique: Two Pointers (In-place modification)
Time Complexity: O(N)
Space Complexity: O(1)

Description:
Given an integer array nums sorted in non-decreasing order, remove the duplicates 
in-place such that each unique element appears only once. The relative order of the 
elements should be kept the same. Return the number of unique elements (k).
*/

class Solution {
public:
    int removeDuplicates(vector<int>& nums) {
        int n = nums.size();
        if (n == 0) {
            return 0;
        }

        // 'writePointer' (or 'insertIndex') tracks the position where the next 
        // *unique* element should be placed. It represents the end of the unique subarray.
        int writePointer = 1; 
        
        // 'readPointer' (or 'i') iterates through the array from the second element.
        // We compare nums[i] with the last unique element recorded, which is nums[writePointer - 1].
        for (int readPointer = 1; readPointer < n; readPointer++) {
            
            // Check if the current element is *different* from the last unique element found.
            // The last unique element is always at nums[writePointer - 1].
            if (nums[readPointer] != nums[writePointer - 1]) {
                // Found a new unique element.
                
                // Move this unique element to the 'writePointer' position.
                // Note: If readPointer == writePointer, this is a redundant self-assignment/copy, 
                // but the code remains correct and is typically fast enough.
                nums[writePointer] = nums[readPointer];
                
                // Advance the 'writePointer' to reserve the next slot for a unique element.
                writePointer++;
            }
            // If nums[readPointer] == nums[writePointer - 1], it is a duplicate.
            // We just advance the 'readPointer' and effectively "skip" the duplicate.
        }
        
        // 'writePointer' now holds the total number of unique elements (k) 
        // and is one greater than the index of the last unique element.
        return writePointer;
    }
};

// Test cases
int main() {
    Solution solution;
    
    // Test 1
    vector<int> nums1 = {1, 1, 2};
    int k1 = solution.removeDuplicates(nums1); // Expected k: 2. nums should be [1, 2, _]
    cout << "Test 1: k = " << k1 << ", Unique elements: [";
    for(int i = 0; i < k1; ++i) {
        cout << nums1[i] << (i == k1 - 1 ? "" : ", ");
    }
    cout << "]" << endl; // Output: [1, 2]

    // Test 2
    vector<int> nums2 = {0, 0, 1, 1, 1, 2, 2, 3, 3, 4};
    int k2 = solution.removeDuplicates(nums2); // Expected k: 5. nums should be [0, 1, 2, 3, 4, _]
    cout << "Test 2: k = " << k2 << ", Unique elements: [";
    for(int i = 0; i < k2; ++i) {
        cout << nums2[i] << (i == k2 - 1 ? "" : ", ");
    }
    cout << "]" << endl; // Output: [0, 1, 2, 3, 4]
    
    // Test 3
    vector<int> nums3 = {3, 3, 3};
    int k3 = solution.removeDuplicates(nums3); // Expected k: 1. nums should be [3, _]
    cout << "Test 3: k = " << k3 << ", Unique elements: [";
    for(int i = 0; i < k3; ++i) {
        cout << nums3[i] << (i == k3 - 1 ? "" : ", ");
    }
    cout << "]" << endl; // Output: [3]

    return 0;
}