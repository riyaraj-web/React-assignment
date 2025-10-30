#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

/*
Problem: Three Sum (3Sum)
Difficulty: Medium
Technique: Two Pointers (with Sorting)
Time Complexity: O(N²)
Space Complexity: O(1) - excluding output array

Description:
Given an integer array nums, return all the triplets [nums[i], nums[j], nums[k]] 
such that i != j, i != k, and j != k, and nums[i] + nums[j] + nums[k] == 0.
Notice that the solution set must not contain duplicate triplets.

Example:
Input: nums = [-1,0,1,2,-1,-4]
Output: [[-1,-1,2],[-1,0,1]]
Explanation: 
nums[0] + nums[1] + nums[2] = (-1) + 0 + 1 = 0.
nums[1] + nums[2] + nums[4] = 0 + 1 + (-1) = 0.
nums[0] + nums[3] + nums[4] = (-1) + 2 + (-1) = 0.
The distinct triplets are [-1,0,1] and [-1,-1,2].
*/

class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {
        vector<vector<int>> result;
        
        // Step 1: Sort the array to use two-pointer technique
        sort(nums.begin(), nums.end());
        
        // Step 2: Iterate through the array
        for (size_t i = 0; i < nums.size(); i++) {
            // Skip duplicate values for the first element
            if (i > 0 && nums[i] == nums[i - 1]) {
                continue;
            }
            
            // Step 3: Use two pointers for the remaining array
            int left = i + 1;
            int right = nums.size() - 1;
            
            while (left < right) {
                int sum = nums[i] + nums[left] + nums[right];
                
                if (sum == 0) {
                    // Found a valid triplet
                    vector<int> triplet;
                    triplet.push_back(nums[i]);
                    triplet.push_back(nums[left]);
                    triplet.push_back(nums[right]);
                    result.push_back(triplet);
                    
                    // Skip duplicates for the second element
                    while (left < right && nums[left] == nums[left + 1]) {
                        left++;
                    }
                    // Skip duplicates for the third element
                    while (left < right && nums[right] == nums[right - 1]) {
                        right--;
                    }
                    
                    // Move both pointers
                    left++;
                    right--;
                } else if (sum < 0) {
                    // Sum is too small, move left pointer right
                    left++;
                } else {
                    // Sum is too large, move right pointer left
                    right--;
                }
            }
        }
        
        return result;
    }
};

// Helper function to print results
void printResult(vector<vector<int>>& result) {
    cout << "[";
    for (size_t i = 0; i < result.size(); i++) {
        cout << "[";
        for (size_t j = 0; j < result[i].size(); j++) {
            cout << result[i][j];
            if (j < result[i].size() - 1) cout << ",";
        }
        cout << "]";
        if (i < result.size() - 1) cout << ",";
    }
    cout << "]" << endl;
}

// Test cases
int main() {
    Solution solution;
    
    // Test case 1
    vector<int> nums1;
    nums1.push_back(-1);
    nums1.push_back(0);
    nums1.push_back(1);
    nums1.push_back(2);
    nums1.push_back(-1);
    nums1.push_back(-4);
    vector<vector<int>> result1 = solution.threeSum(nums1);
    cout << "Test 1: ";
    printResult(result1);
    cout << "Expected: [[-1,-1,2],[-1,0,1]]" << endl << endl;
    
    // Test case 2
    vector<int> nums2;
    nums2.push_back(0);
    nums2.push_back(1);
    nums2.push_back(1);
    vector<vector<int>> result2 = solution.threeSum(nums2);
    cout << "Test 2: ";
    printResult(result2);
    cout << "Expected: []" << endl << endl;
    
    // Test case 3
    vector<int> nums3;
    nums3.push_back(0);
    nums3.push_back(0);
    nums3.push_back(0);
    vector<vector<int>> result3 = solution.threeSum(nums3);
    cout << "Test 3: ";
    printResult(result3);
    cout << "Expected: [[0,0,0]]" << endl << endl;
    
    return 0;
}