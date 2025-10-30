#include <iostream>
#include <vector>
#include <unordered_map>
using namespace std;

/*
Problem: Two Sum
Difficulty: Easy
Technique: Hash Map
Time Complexity: O(N)
Space Complexity: O(N)

Description:
Given an array of integers nums and an integer target, return indices of the 
two numbers such that they add up to target.

Example:
Input: nums = [2,7,11,15], target = 9
Output: [0,1]
Explanation: Because nums[0] + nums[1] == 9, we return [0, 1].
*/

class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        unordered_map<int, int> numMap; // value -> index
        
        for (size_t i = 0; i < nums.size(); i++) {
            int complement = target - nums[i];
            
            // Check if complement exists in map
            if (numMap.find(complement) != numMap.end()) {
                vector<int> result;
                result.push_back(numMap[complement]);
                result.push_back(i);
                return result;
            }
            
            // Store current number and its index
            numMap[nums[i]] = i;
        }
        
        return vector<int>(); // No solution found
    }
};

// Test cases
int main() {
    Solution solution;
    
    // Test case 1
    vector<int> nums1;
    nums1.push_back(2);
    nums1.push_back(7);
    nums1.push_back(11);
    nums1.push_back(15);
    int target1 = 9;
    vector<int> result1 = solution.twoSum(nums1, target1);
    cout << "Test 1: [" << result1[0] << ", " << result1[1] << "]" << endl;
    
    // Test case 2
    vector<int> nums2;
    nums2.push_back(3);
    nums2.push_back(2);
    nums2.push_back(4);
    int target2 = 6;
    vector<int> result2 = solution.twoSum(nums2, target2);
    cout << "Test 2: [" << result2[0] << ", " << result2[1] << "]" << endl;
    
    // Test case 3
    vector<int> nums3;
    nums3.push_back(3);
    nums3.push_back(3);
    int target3 = 6;
    vector<int> result3 = solution.twoSum(nums3, target3);
    cout << "Test 3: [" << result3[0] << ", " << result3[1] << "]" << endl;
    
    return 0;
}