#include <iostream>
#include <vector>
#include <algorithm>
#include <climits>
using namespace std;

/*
Problem: Minimum Size Subarray Sum
Difficulty: Medium
Technique: Sliding Window
Time Complexity: O(N)
Space Complexity: O(1)

Description:
Given an array of positive integers nums and a positive integer target, 
return the minimal length of a subarray whose sum is greater than or equal to target. 
If there is no such subarray, return 0 instead.

Example:
Input: target = 7, nums = [2,3,1,2,4,3]
Output: 2
Explanation: The subarray [4,3] has the minimal length under the problem constraint.

Example 2:
Input: target = 4, nums = [1,4,4]
Output: 1

Example 3:
Input: target = 11, nums = [1,1,1,1,1,1,1,1]
Output: 0
*/

class Solution {
public:
    int minSubArrayLen(int target, vector<int>& nums) {
        int n = nums.size();
        int minLength = INT_MAX;  // Initialize to maximum value
        int left = 0;             // Left pointer of the window
        int currentSum = 0;       // Sum of current window
        
        // Expand window by moving right pointer
        for (int right = 0; right < n; right++) {
            // Add current element to window sum
            currentSum += nums[right];
            
            // Shrink window from left while sum >= target
            // This finds the minimum window for current right position
            while (currentSum >= target) {
                // Update minimum length
                minLength = min(minLength, right - left + 1);
                
                // Remove leftmost element and shrink window
                currentSum -= nums[left];
                left++;
            }
        }
        
        // If minLength was never updated, no valid subarray exists
        return (minLength == INT_MAX) ? 0 : minLength;
    }
};

// Test cases
int main() {
    Solution solution;
    
    // Test case 1
    vector<int> nums1;
    nums1.push_back(2);
    nums1.push_back(3);
    nums1.push_back(1);
    nums1.push_back(2);
    nums1.push_back(4);
    nums1.push_back(3);
    int target1 = 7;
    int result1 = solution.minSubArrayLen(target1, nums1);
    cout << "Test 1: " << result1 << " (Expected: 2)" << endl;
    
    // Test case 2
    vector<int> nums2;
    nums2.push_back(1);
    nums2.push_back(4);
    nums2.push_back(4);
    int target2 = 4;
    int result2 = solution.minSubArrayLen(target2, nums2);
    cout << "Test 2: " << result2 << " (Expected: 1)" << endl;
    
    // Test case 3
    vector<int> nums3;
    nums3.push_back(1);
    nums3.push_back(1);
    nums3.push_back(1);
    nums3.push_back(1);
    nums3.push_back(1);
    nums3.push_back(1);
    nums3.push_back(1);
    nums3.push_back(1);
    int target3 = 11;
    int result3 = solution.minSubArrayLen(target3, nums3);
    cout << "Test 3: " << result3 << " (Expected: 0)" << endl;
    
    // Test case 4
    vector<int> nums4;
    nums4.push_back(1);
    nums4.push_back(2);
    nums4.push_back(3);
    nums4.push_back(4);
    nums4.push_back(5);
    int target4 = 11;
    int result4 = solution.minSubArrayLen(target4, nums4);
    cout << "Test 4: " << result4 << " (Expected: 3)" << endl;
    
    return 0;
}