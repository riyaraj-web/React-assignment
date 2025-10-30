#include <iostream>
#include <vector>
#include <unordered_set>
#include <algorithm>
using namespace std;

/*
Problem: Longest Consecutive Sequence
Difficulty: Medium
Technique: Hash Set
Time Complexity: O(N)
Space Complexity: O(N)

Description:
Given an unsorted array of integers nums, return the length of the longest 
consecutive elements sequence.
You must write an algorithm that runs in O(n) time.

Example:
Input: nums = [100,4,200,1,3,2]
Output: 4
Explanation: The longest consecutive elements sequence is [1, 2, 3, 4]. 
Therefore its length is 4.

Example 2:
Input: nums = [0,3,7,2,5,8,4,6,0,1]
Output: 9
Explanation: The longest consecutive sequence is [0,1,2,3,4,5,6,7,8].
*/

class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
        if (nums.empty()) {
            return 0;
        }
        
        // Step 1: Put all numbers in a hash set for O(1) lookup
        unordered_set<int> numSet;
        for (size_t i = 0; i < nums.size(); i++) {
            numSet.insert(nums[i]);
        }
        
        int longestStreak = 0;
        
        // Step 2: Iterate through the set
        for (unordered_set<int>::iterator it = numSet.begin(); it != numSet.end(); ++it) {
            int num = *it;
            
            // Key optimization: Only start counting from the beginning of a sequence
            // Check if num-1 exists. If it does, num is not the start of a sequence
            if (numSet.find(num - 1) == numSet.end()) {
                // This is the start of a sequence
                int currentNum = num;
                int currentStreak = 1;
                
                // Count consecutive numbers
                while (numSet.find(currentNum + 1) != numSet.end()) {
                    currentNum++;
                    currentStreak++;
                }
                
                // Update longest streak
                longestStreak = max(longestStreak, currentStreak);
            }
        }
        
        return longestStreak;
    }
};

// Test cases
int main() {
    Solution solution;
    
    // Test case 1
    vector<int> nums1;
    nums1.push_back(100);
    nums1.push_back(4);
    nums1.push_back(200);
    nums1.push_back(1);
    nums1.push_back(3);
    nums1.push_back(2);
    int result1 = solution.longestConsecutive(nums1);
    cout << "Test 1: " << result1 << " (Expected: 4)" << endl;
    
    // Test case 2
    vector<int> nums2;
    nums2.push_back(0);
    nums2.push_back(3);
    nums2.push_back(7);
    nums2.push_back(2);
    nums2.push_back(5);
    nums2.push_back(8);
    nums2.push_back(4);
    nums2.push_back(6);
    nums2.push_back(0);
    nums2.push_back(1);
    int result2 = solution.longestConsecutive(nums2);
    cout << "Test 2: " << result2 << " (Expected: 9)" << endl;
    
    // Test case 3: Single element
    vector<int> nums3;
    nums3.push_back(1);
    int result3 = solution.longestConsecutive(nums3);
    cout << "Test 3: " << result3 << " (Expected: 1)" << endl;
    
    // Test case 4: Empty array
    vector<int> nums4;
    int result4 = solution.longestConsecutive(nums4);
    cout << "Test 4: " << result4 << " (Expected: 0)" << endl;
    
    // Test case 5: All consecutive
    vector<int> nums5;
    nums5.push_back(1);
    nums5.push_back(2);
    nums5.push_back(3);
    nums5.push_back(4);
    nums5.push_back(5);
    int result5 = solution.longestConsecutive(nums5);
    cout << "Test 5: " << result5 << " (Expected: 5)" << endl;
    
    return 0;
}