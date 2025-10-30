#include <iostream>
#include <vector>
#include <algorithm> // For swap

using namespace std;

/*
Problem: Sort Colors (Dutch National Flag Problem)
Technique: Three Pointers
Time Complexity: O(N)
Space Complexity: O(1)

Description:
Given an array nums with n objects colored red, white, or blue, sort them in-place 
so that objects of the same color are adjacent, with the colors in the order red, 
white, and blue. We use the integers 0, 1, and 2 to represent the color red, white, 
and blue, respectively.
*/

class Solution {
public:
    void sortColors(vector<int>& nums) {
        // Initialize three pointers
        int low = 0;    // Boundary for 0s (Everything to the left of 'low' is 0)
        int mid = 0;    // Current element being examined
        int high = nums.size() - 1; // Boundary for 2s (Everything to the right of 'high' is 2)

        // Iterate while the middle pointer hasn't crossed the high pointer
        while (mid <= high) {
            switch (nums[mid]) {
                case 0:
                    // Current element is 0 (Red)
                    // Swap it with the element at 'low' to move it to the beginning.
                    swap(nums[low], nums[mid]);
                    // Advance both low and mid pointers.
                    low++;
                    mid++;
                    break;

                case 1:
                    // Current element is 1 (White)
                    // It's in the correct relative position (between 0s and 2s).
                    // Just advance the mid pointer to check the next element.
                    mid++;
                    break;

                case 2:
                    // Current element is 2 (Blue)
                    // Swap it with the element at 'high' to move it to the end.
                    swap(nums[mid], nums[high]);
                    // ONLY advance the high pointer, DO NOT advance the mid pointer.
                    // The element swapped into nums[mid] from nums[high] is UNKNOWN 
                    // and must be re-checked in the next iteration.
                    high--;
                    break;
            }
        }
    }
};

// Test cases
int main() {
    Solution solution;
    
    // Test 1
    vector<int> nums1 = {2, 0, 2, 1, 1, 0};
    solution.sortColors(nums1); // Expected: [0, 0, 1, 1, 2, 2]
    cout << "Test 1: [";
    for(int i = 0; i < nums1.size(); ++i) {
        cout << nums1[i] << (i == nums1.size() - 1 ? "" : ", ");
    }
    cout << "] (Expected: [0, 0, 1, 1, 2, 2])" << endl;

    // Test 2
    vector<int> nums2 = {2, 0, 1};
    solution.sortColors(nums2); // Expected: [0, 1, 2]
    cout << "Test 2: [";
    for(int i = 0; i < nums2.size(); ++i) {
        cout << nums2[i] << (i == nums2.size() - 1 ? "" : ", ");
    }
    cout << "] (Expected: [0, 1, 2])" << endl;
    
    // Test 3
    vector<int> nums3 = {1, 1, 1, 0, 2, 2, 0, 0, 1, 2};
    solution.sortColors(nums3); // Expected: [0, 0, 0, 1, 1, 1, 1, 2, 2, 2]
    cout << "Test 3: [";
    for(int i = 0; i < nums3.size(); ++i) {
        cout << nums3[i] << (i == nums3.size() - 1 ? "" : ", ");
    }
    cout << "] (Expected: [0, 0, 0, 1, 1, 1, 1, 2, 2, 2])" << endl;

    return 0;
}