#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

/*
Problem: Move Zeroes
Technique: Two Pointers (Read/Write or 'Snowball' approach)
Time Complexity: O(N)
Space Complexity: O(1)

Description:
Given an integer array nums, move all 0's to the end of it while maintaining the 
relative order of the non-zero elements. You must do this in-place without 
making a copy of the array.
*/

class Solution {
public:
    void moveZeroes(vector<int>& nums) {
        int n = nums.size();
        
        // 'writePointer' tracks the position where the next non-zero element should be placed.
        // It's the boundary between the non-zero elements and the zeros.
        int writePointer = 0; 
        
        // =======================================================
        // PASS 1: Move all non-zero elements to the front
        // =======================================================
        // 'readPointer' iterates through the entire array.
        for (int readPointer = 0; readPointer < n; readPointer++) {
            
            // If the element at 'readPointer' is non-zero,
            // we move it to the position pointed to by 'writePointer'.
            if (nums[readPointer] != 0) {
                // We only need to swap if the pointers are different, 
                // but the logic below is robust and covers both cases efficiently.
                
                // Swap the non-zero element into the 'writePointer' slot.
                // For a highly optimized solution, one would just assign 
                // and then fill the remaining with zeros in the next step.
                
                if (readPointer != writePointer) {
                    swap(nums[readPointer], nums[writePointer]);
                }
                
                // Advance the 'writePointer' to the next position for a non-zero element.
                writePointer++;
            }
            // If nums[readPointer] is 0, we simply advance 'readPointer', 
            // leaving the 0 behind for the 'writePointer' to eventually overwrite.
        }

        // --- Alternative (More common and often faster) Implementation ---
        /*
        // PASS 1: Write all non-zero elements sequentially
        for (int readPointer = 0; readPointer < n; readPointer++) {
            if (nums[readPointer] != 0) {
                nums[writePointer] = nums[readPointer];
                writePointer++;
            }
        }
        
        // PASS 2: Fill the remainder of the array with zeros
        for (int i = writePointer; i < n; i++) {
            nums[i] = 0;
        }
        */

        // The swap method above is a single pass, in-place solution.
    }
};

// Test cases
int main() {
    Solution solution;
    
    // Test 1
    vector<int> nums1 = {0, 1, 0, 3, 12};
    solution.moveZeroes(nums1); // Expected: [1, 3, 12, 0, 0]
    cout << "Test 1: [";
    for(int i = 0; i < nums1.size(); ++i) {
        cout << nums1[i] << (i == nums1.size() - 1 ? "" : ", ");
    }
    cout << "] (Expected: [1, 3, 12, 0, 0])" << endl;

    // Test 2
    vector<int> nums2 = {0, 0, 1};
    solution.moveZeroes(nums2); // Expected: [1, 0, 0]
    cout << "Test 2: [";
    for(int i = 0; i < nums2.size(); ++i) {
        cout << nums2[i] << (i == nums2.size() - 1 ? "" : ", ");
    }
    cout << "] (Expected: [1, 0, 0])" << endl;
    
    // Test 3
    vector<int> nums3 = {4, 2, 4, 0, 0, 3, 0, 5, 1, 0};
    solution.moveZeroes(nums3); // Expected: [4, 2, 4, 3, 5, 1, 0, 0, 0, 0]
    cout << "Test 3: [";
    for(int i = 0; i < nums3.size(); ++i) {
        cout << nums3[i] << (i == nums3.size() - 1 ? "" : ", ");
    }
    cout << "] (Expected: [4, 2, 4, 3, 5, 1, 0, 0, 0, 0])" << endl;

    return 0;
}