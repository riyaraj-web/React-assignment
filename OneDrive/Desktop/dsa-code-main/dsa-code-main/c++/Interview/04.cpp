#include <iostream>
#include <vector>
#include <unordered_map>
using namespace std;

/*
Problem: Subarray Sum Equals K
Difficulty: Medium
Technique: Prefix Sum + Hash Map
Time Complexity: O(N)
Space Complexity: O(N)

Description:
Given an array of integers nums and an integer k, return the total number of 
subarrays whose sum equals to k.
A subarray is a contiguous non-empty sequence of elements within an array.

Example:
Input: nums = [1,1,1], k = 2
Output: 2
Explanation: There are two subarrays [1,1] that sum to 2.

Example 2:
Input: nums = [1,2,3], k = 3
Output: 2
Explanation: [1,2] and [3] both sum to 3.
*/

class Solution {
public:
    int subarraySum(vector<int>& nums, int k) {
        // Hash map to store prefix sum frequencies
        // Key: prefix sum, Value: count of how many times this prefix sum occurred
        unordered_map<int, int> prefixSumCount;
        
        // Initialize with prefix sum 0 occurring once
        // This handles subarrays that start from index 0
        prefixSumCount[0] = 1;
        
        int currentSum = 0;  // Running prefix sum
        int count = 0;       // Count of subarrays with sum k
        
        // Iterate through the array
        for (size_t i = 0; i < nums.size(); i++) {
            // Update current prefix sum
            currentSum += nums[i];
            
            // Key insight: If (currentSum - k) exists in our map,
            // it means there's a subarray ending at index i with sum k
            // 
            // Why? If prefixSum[j] = currentSum - k, then
            // sum from (j+1) to i = currentSum - prefixSum[j] = k
            
            int target = currentSum - k;
            
            if (prefixSumCount.find(target) != prefixSumCount.end()) {
                count += prefixSumCount[target];
            }
            
            // Add current prefix sum to the map
            prefixSumCount[currentSum]++;
        }
        
        return count;
    }
};

// Test cases
int main() {
    Solution solution;
    
    // Test case 1
    vector<int> nums1;
    nums1.push_back(1);
    nums1.push_back(1);
    nums1.push_back(1);
    int k1 = 2;
    int result1 = solution.subarraySum(nums1, k1);
    cout << "Test 1: " << result1 << " (Expected: 2)" << endl;
    
    // Test case 2
    vector<int> nums2;
    nums2.push_back(1);
    nums2.push_back(2);
    nums2.push_back(3);
    int k2 = 3;
    int result2 = solution.subarraySum(nums2, k2);
    cout << "Test 2: " << result2 << " (Expected: 2)" << endl;
    
    // Test case 3
    vector<int> nums3;
    nums3.push_back(1);
    nums3.push_back(-1);
    nums3.push_back(0);
    int k3 = 0;
    int result3 = solution.subarraySum(nums3, k3);
    cout << "Test 3: " << result3 << " (Expected: 3)" << endl;
    
    // Test case 4: With negative numbers
    vector<int> nums4;
    nums4.push_back(3);
    nums4.push_back(4);
    nums4.push_back(7);
    nums4.push_back(2);
    nums4.push_back(-3);
    nums4.push_back(1);
    nums4.push_back(4);
    nums4.push_back(2);
    int k4 = 7;
    int result4 = solution.subarraySum(nums4, k4);
    cout << "Test 4: " << result4 << " (Expected: 4)" << endl;
    
    return 0;
}