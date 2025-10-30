#include <iostream>
#include <string>
#include <unordered_map>
#include <climits>
using namespace std;

/*
Problem: Minimum Window Substring
Difficulty: Hard
Technique: Sliding Window + Hash Map
Time Complexity: O(N + M) where N = length of s, M = length of t
Space Complexity: O(M)

Description:
Given two strings s and t of lengths m and n respectively, return the minimum 
window substring of s such that every character in t (including duplicates) is 
included in the window. If there is no such substring, return the empty string "".

The testcases will be generated such that the answer is unique.

Example 1:
Input: s = "ADOBECODEBANC", t = "ABC"
Output: "BANC"
Explanation: The minimum window substring "BANC" includes 'A', 'B', and 'C' from string t.

Example 2:
Input: s = "a", t = "a"
Output: "a"
Explanation: The entire string s is the minimum window.

Example 3:
Input: s = "a", t = "aa"
Output: ""
Explanation: Both 'a's from t must be included in the window.
Since the largest window of s only has one 'a', return empty string.
*/

class Solution {
public:
    string minWindow(string s, string t) {
        if (s.empty() || t.empty() || s.length() < t.length()) {
            return "";
        }
        
        // Hash map to store frequency of characters in t
        unordered_map<char, int> targetCount;
        for (char c : t) {
            targetCount[c]++;
        }
        
        // Hash map to store frequency of characters in current window
        unordered_map<char, int> windowCount;
        
        int required = targetCount.size();  // Number of unique characters in t
        int formed = 0;  // Number of unique characters in current window with desired frequency
        
        int left = 0;
        int minLen = INT_MAX;
        int minLeft = 0;  // Starting index of minimum window
        
        // Expand window with right pointer
        for (int right = 0; right < s.length(); right++) {
            char c = s[right];
            windowCount[c]++;
            
            // Check if current character satisfies the frequency requirement
            if (targetCount.find(c) != targetCount.end() && 
                windowCount[c] == targetCount[c]) {
                formed++;
            }
            
            // Try to contract the window until it's no longer valid
            while (left <= right && formed == required) {
                // Update minimum window
                if (right - left + 1 < minLen) {
                    minLen = right - left + 1;
                    minLeft = left;
                }
                
                // Remove character from left of window
                char leftChar = s[left];
                windowCount[leftChar]--;
                
                // Check if window becomes invalid
                if (targetCount.find(leftChar) != targetCount.end() && 
                    windowCount[leftChar] < targetCount[leftChar]) {
                    formed--;
                }
                
                left++;
            }
        }
        
        // Return minimum window or empty string if no valid window found
        return (minLen == INT_MAX) ? "" : s.substr(minLeft, minLen);
    }
};

// Test cases
int main() {
    Solution solution;
    
    // Test case 1
    string s1 = "ADOBECODEBANC";
    string t1 = "ABC";
    string result1 = solution.minWindow(s1, t1);
    cout << "Test 1: \"" << result1 << "\" (Expected: \"BANC\")" << endl;
    
    // Test case 2
    string s2 = "a";
    string t2 = "a";
    string result2 = solution.minWindow(s2, t2);
    cout << "Test 2: \"" << result2 << "\" (Expected: \"a\")" << endl;
    
    // Test case 3
    string s3 = "a";
    string t3 = "aa";
    string result3 = solution.minWindow(s3, t3);
    cout << "Test 3: \"" << result3 << "\" (Expected: \"\")" << endl;
    
    // Test case 4: Multiple occurrences
    string s4 = "aaaaaaaaaaaabbbbbcdd";
    string t4 = "abcdd";
    string result4 = solution.minWindow(s4, t4);
    cout << "Test 4: \"" << result4 << "\" (Expected: \"abbbbbcdd\")" << endl;
    
    // Test case 5: Exact match
    string s5 = "abc";
    string t5 = "abc";
    string result5 = solution.minWindow(s5, t5);
    cout << "Test 5: \"" << result5 << "\" (Expected: \"abc\")" << endl;
    
    // Test case 6: No valid window
    string s6 = "abc";
    string t6 = "def";
    string result6 = solution.minWindow(s6, t6);
    cout << "Test 6: \"" << result6 << "\" (Expected: \"\")" << endl;
    
    return 0;
}