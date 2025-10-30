#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

/*
Problem: Find the Duplicate Number
Technique: Floyd's Cycle Detection (Tortoise and Hare)
Time Complexity: O(N)
Space Complexity: O(1)

Description:
Given an array nums containing n + 1 integers where each integer is between 1 and n 
(inclusive), prove that at least one duplicate number must exist. Assume that there 
is only one duplicate number, find the duplicate one.
*/

class Solution {
public:
    int findDuplicate(vector<int>& nums) {
        // Pointers for cycle detection
        int slow = nums[0]; // The Tortoise moves one step at a time
        int fast = nums[nums[0]]; // The Hare moves two steps at a time

        // =======================================================
        // Step 1: Find the Intersection Point (Collision)
        // =======================================================
        // Move the pointers until they meet inside the cycle.
        while (slow != fast) {
            slow = nums[slow];        // Move slow by 1
            fast = nums[nums[fast]];  // Move fast by 2
        }

        // =======================================================
        // Step 2: Find the Cycle Start (The Duplicate Number)
        // =======================================================
        // Reset the fast pointer to the array start (index 0).
        // Keep the slow pointer at the collision point.
        // The distance from the array start to the cycle start (duplicate) is 
        // the same as the distance from the collision point to the cycle start.
        fast = 0;

        // Move both pointers one step at a time until they meet.
        // Their meeting point is the entry point of the cycle, which is the duplicate number.
        while (slow != fast) {
            slow = nums[slow];
            fast = nums[fast];
        }

        // The meeting point is the duplicate number.
        return slow;
    }
};

// Test cases
int main() {
    Solution solution;

    // Test 1: Duplicate is 2
    vector<int> nums1 = {1, 3, 4, 2, 2};
    int result1 = solution.findDuplicate(nums1); // Expected: 2
    cout << "Test 1: Duplicate = " << result1 << " (Expected: 2)" << endl;

    // Test 2: Duplicate is 3
    vector<int> nums2 = {3, 1, 3, 4, 2};
    int result2 = solution.findDuplicate(nums2); // Expected: 3
    cout << "Test 2: Duplicate = " << result2 << " (Expected: 3)" << endl;

    // Test 3: Duplicate is 1
    vector<int> nums3 = {1, 1};
    int result3 = solution.findDuplicate(nums3); // Expected: 1
    cout << "Test 3: Duplicate = " << result3 << " (Expected: 1)" << endl;

    return 0;
}