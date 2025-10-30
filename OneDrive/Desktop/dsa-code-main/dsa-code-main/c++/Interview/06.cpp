#include <iostream>
#include <string>
#include <unordered_set>
#include <algorithm>
using namespace std;

/*
Problem: Longest Substring Without Repeating Characters
Difficulty: Medium
Technique: Sliding Window + Hash Set/Map
Time Complexity: O(N)
Space Complexity: O(min(N, M)) where M is the charset size

Description:
Given a string s, find the length of the longest substring without repeating characters.

Example 1:
Input: s = "abcabcbb"
Output: 3
Explanation: The answer is "abc", with the length of 3.

Example 2:
Input: s = "bbbbb"
Output: 1
Explanation: The answer is "b", with the length of 1.

Example 3:
Input: s = "pwwkew"
Output: 3
Explanation: The answer is "wke", with the length of 3.
Notice that the answer must be a substring, "pwke" is a subsequence and not a substring.
*/

class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        // Hash set to store characters in current window
        unordered_set<char> charSet;
        
        int maxLength = 0;
        int left = 0;  // Left pointer of sliding window
        
        // Expand window with right pointer
        for (int right = 0; right < s.length(); right++) {
            // If character is already in the set, shrink window from left
            // until the duplicate is removed
            while (charSet.find(s[right]) != charSet.end()) {
                charSet.erase(s[left]);
                left++;
            }
            
            // Add current character to the set
            charSet.insert(s[right]);
            
            // Update maximum length
            maxLength = max(maxLength, right - left + 1);
        }
        
        return maxLength;
    }
};

// Alternative solution using unordered_map (tracks last seen index)
class SolutionMap {
public:
    int lengthOfLongestSubstring(string s) {
        // Map to store the last seen index of each character
        unordered_map<char, int> charIndex;
        
        int maxLength = 0;
        int left = 0;
        
        for (int right = 0; right < s.length(); right++) {
            char currentChar = s[right];
            
            // If character was seen before and is in current window
            if (charIndex.find(currentChar) != charIndex.end() && 
                charIndex[currentChar] >= left) {
                // Move left pointer to position after the last occurrence
                left = charIndex[currentChar] + 1;
            }
            
            // Update the last seen index of current character
            charIndex[currentChar] = right;
            
            // Update maximum length
            maxLength = max(maxLength, right - left + 1);
        }
        
        return maxLength;
    }
};

// Test cases
int main() {
    Solution solution;
    SolutionMap solutionMap;
    
    // Test case 1
    string s1 = "abcabcbb";
    int result1 = solution.lengthOfLongestSubstring(s1);
    int result1Map = solutionMap.lengthOfLongestSubstring(s1);
    cout << "Test 1 (Set): " << result1 << " (Expected: 3)" << endl;
    cout << "Test 1 (Map): " << result1Map << " (Expected: 3)" << endl << endl;
    
    // Test case 2
    string s2 = "bbbbb";
    int result2 = solution.lengthOfLongestSubstring(s2);
    int result2Map = solutionMap.lengthOfLongestSubstring(s2);
    cout << "Test 2 (Set): " << result2 << " (Expected: 1)" << endl;
    cout << "Test 2 (Map): " << result2Map << " (Expected: 1)" << endl << endl;
    
    // Test case 3
    string s3 = "pwwkew";
    int result3 = solution.lengthOfLongestSubstring(s3);
    int result3Map = solutionMap.lengthOfLongestSubstring(s3);
    cout << "Test 3 (Set): " << result3 << " (Expected: 3)" << endl;
    cout << "Test 3 (Map): " << result3Map << " (Expected: 3)" << endl << endl;
    
    // Test case 4: Empty string
    string s4 = "";
    int result4 = solution.lengthOfLongestSubstring(s4);
    cout << "Test 4: " << result4 << " (Expected: 0)" << endl << endl;
    
    // Test case 5: All unique characters
    string s5 = "abcdef";
    int result5 = solution.lengthOfLongestSubstring(s5);
    cout << "Test 5: " << result5 << " (Expected: 6)" << endl << endl;
    
    // Test case 6: Special characters
    string s6 = "au!@#$%";
    int result6 = solution.lengthOfLongestSubstring(s6);
    cout << "Test 6: " << result6 << " (Expected: 7)" << endl;
    
    return 0;
}