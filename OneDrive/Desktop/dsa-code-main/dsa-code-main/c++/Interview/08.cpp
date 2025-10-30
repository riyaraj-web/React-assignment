#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

/*
Problem: Trapping Rain Water
Difficulty: Hard
Technique: Two Pointers or Prefix Max Arrays
Time Complexity: O(N)
Space Complexity: O(1) for two pointers, O(N) for prefix arrays

Description:
Given n non-negative integers representing an elevation map where the width of 
each bar is 1, compute how much water it can trap after raining.

Example 1:
Input: height = [0,1,0,2,1,0,1,3,2,1,2,1]
Output: 6
Explanation: The above elevation map is represented by array [0,1,0,2,1,0,1,3,2,1,2,1]. 
In this case, 6 units of rain water are being trapped.

Example 2:
Input: height = [4,2,0,3,2,5]
Output: 9
*/

// Solution 1: Two Pointers (Optimal - O(1) space)
class SolutionTwoPointers {
public:
    int trap(vector<int>& height) {
        if (height.empty()) {
            return 0;
        }
        
        int left = 0;
        int right = height.size() - 1;
        int leftMax = 0;   // Maximum height on the left side
        int rightMax = 0;  // Maximum height on the right side
        int water = 0;
        
        // Key insight: Water trapped at position i depends on 
        // min(maxLeft, maxRight) - height[i]
        while (left < right) {
            if (height[left] < height[right]) {
                // Process left side
                if (height[left] >= leftMax) {
                    // Update left maximum
                    leftMax = height[left];
                } else {
                    // Water can be trapped
                    water += leftMax - height[left];
                }
                left++;
            } else {
                // Process right side
                if (height[right] >= rightMax) {
                    // Update right maximum
                    rightMax = height[right];
                } else {
                    // Water can be trapped
                    water += rightMax - height[right];
                }
                right--;
            }
        }
        
        return water;
    }
};

// Solution 2: Prefix Max Arrays (More intuitive)
class SolutionPrefixArrays {
public:
    int trap(vector<int>& height) {
        int n = height.size();
        if (n == 0) {
            return 0;
        }
        
        // Create arrays to store max height to the left and right
        vector<int> leftMax(n);
        vector<int> rightMax(n);
        
        // Fill leftMax array
        leftMax[0] = height[0];
        for (int i = 1; i < n; i++) {
            leftMax[i] = max(leftMax[i - 1], height[i]);
        }
        
        // Fill rightMax array
        rightMax[n - 1] = height[n - 1];
        for (int i = n - 2; i >= 0; i--) {
            rightMax[i] = max(rightMax[i + 1], height[i]);
        }
        
        // Calculate trapped water
        int water = 0;
        for (int i = 0; i < n; i++) {
            // Water at position i = min(leftMax, rightMax) - height[i]
            water += min(leftMax[i], rightMax[i]) - height[i];
        }
        
        return water;
    }
};

// Test cases
int main() {
    SolutionTwoPointers solutionTP;
    SolutionPrefixArrays solutionPA;
    
    // Test case 1
    vector<int> height1;
    height1.push_back(0);
    height1.push_back(1);
    height1.push_back(0);
    height1.push_back(2);
    height1.push_back(1);
    height1.push_back(0);
    height1.push_back(1);
    height1.push_back(3);
    height1.push_back(2);
    height1.push_back(1);
    height1.push_back(2);
    height1.push_back(1);
    int result1TP = solutionTP.trap(height1);
    int result1PA = solutionPA.trap(height1);
    cout << "Test 1 (Two Pointers): " << result1TP << " (Expected: 6)" << endl;
    cout << "Test 1 (Prefix Arrays): " << result1PA << " (Expected: 6)" << endl << endl;
    
    // Test case 2
    vector<int> height2;
    height2.push_back(4);
    height2.push_back(2);
    height2.push_back(0);
    height2.push_back(3);
    height2.push_back(2);
    height2.push_back(5);
    int result2TP = solutionTP.trap(height2);
    int result2PA = solutionPA.trap(height2);
    cout << "Test 2 (Two Pointers): " << result2TP << " (Expected: 9)" << endl;
    cout << "Test 2 (Prefix Arrays): " << result2PA << " (Expected: 9)" << endl << endl;
    
    // Test case 3: No water can be trapped
    vector<int> height3;
    height3.push_back(1);
    height3.push_back(2);
    height3.push_back(3);
    height3.push_back(4);
    height3.push_back(5);
    int result3TP = solutionTP.trap(height3);
    cout << "Test 3: " << result3TP << " (Expected: 0)" << endl << endl;
    
    // Test case 4: Single valley
    vector<int> height4;
    height4.push_back(3);
    height4.push_back(0);
    height4.push_back(2);
    height4.push_back(0);
    height4.push_back(4);
    int result4TP = solutionTP.trap(height4);
    cout << "Test 4: " << result4TP << " (Expected: 7)" << endl;
    
    return 0;
}