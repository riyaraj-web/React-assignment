#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

/*
Problem: Jump Game
Technique: Greedy (Tracking Maximum Reachable Index)
Time Complexity: O(N)
Space Complexity: O(1)

Description:
You are given an integer array nums. You are initially located at the first index, 
and each element in the array represents your maximum jump length at that position.
Return true if you can reach the last index, or false otherwise.
*/

class Solution {
public:
    bool canJump(vector<int>& nums) {
        int n = nums.size();
        if (n == 0) {
            return false; // Based on typical constraints, though usually n >= 1
        }
        
        // 'maxReach' tracks the furthest index that can be reached from the current position
        // or any previously checked position.
        int maxReach = 0;
        
        // Iterate through the array. We only need to check indices up to where we can reach.
        for (int i = 0; i < n; ++i) {
            
            // 1. Check if the current index 'i' is reachable.
            // If the furthest we can reach (maxReach) is less than the current index 'i', 
            // it means there's a gap we cannot cross, and thus the end is unreachable.
            if (i > maxReach) {
                return false;
            }
            
            // 2. Update the maximum reachable index (The Greedy step).
            // The maximum reach is updated to be the further of:
            // a) The current maxReach.
            // b) The jump from the current index: i + nums[i].
            maxReach = max(maxReach, i + nums[i]);
            
            // 3. Check if the end has been reached or surpassed.
            // If maxReach is greater than or equal to the last index (n - 1), 
            // we know the end is reachable, so we can stop and return true.
            if (maxReach >= n - 1) {
                return true;
            }
        }
        
        // This return is technically redundant due to the check inside the loop, 
        // but included for completeness if the loop ends (e.g., n=1).
        return maxReach >= n - 1; 
    }
};

// Test cases
int main() {
    Solution solution;
    
    // Test 1: Can reach the end
    vector<int> nums1 = {2, 3, 1, 1, 4};
    bool result1 = solution.canJump(nums1); // Expected: true
    cout << "Test 1: " << (result1 ? "true" : "false") << " (Expected: true)" << endl;

    // Test 2: Cannot reach the end (stuck at 0)
    vector<int> nums2 = {3, 2, 1, 0, 4};
    bool result2 = solution.canJump(nums2); // Expected: false
    cout << "Test 2: " << (result2 ? "true" : "false") << " (Expected: false)" << endl;
    
    // Test 3: Array of length 1
    vector<int> nums3 = {0};
    bool result3 = solution.canJump(nums3); // Expected: true
    cout << "Test 3: " << (result3 ? "true" : "false") << " (Expected: true)" << endl;

    // Test 4: Long failure case
    vector<int> nums4 = {1, 1, 1, 1, 0, 1};
    bool result4 = solution.canJump(nums4); // Expected: false
    cout << "Test 4: " << (result4 ? "true" : "false") << " (Expected: false)" << endl;

    return 0;
}