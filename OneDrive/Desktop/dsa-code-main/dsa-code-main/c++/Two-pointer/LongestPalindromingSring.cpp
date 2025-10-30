#include <string>
#include <iostream> // For testing

using namespace std;

class Solution {
private:
    // Helper function to expand around a center and find the longest palindrome
    void expandAroundCenter(const string& s, int left, int right, int& start, int& maxLen) {
        // Expand while the pointers are within bounds and characters match
        while (left >= 0 && right < s.length() && s[left] == s[right]) {
            int currentLen = right - left + 1;
            if (currentLen > maxLen) {
                maxLen = currentLen;
                start = left;
            }
            // Move pointers outwards
            left--;
            right++;
        }
    }

public:
    string longestPalindrome(const string& s) {
        if (s.length() < 2) {
            return s; // Palindromes of length 0 or 1 are just the string itself
        }

        int start = 0;  // Starting index of the longest palindrome found so far
        int maxLen = 1; // Length of the longest palindrome found so far

        // Iterate through each character to consider it as a potential center
        for (int i = 0; i < s.length(); ++i) {
            // Case 1: Odd length palindrome (e.g., "aba")
            // The center is a single character at index 'i'
            expandAroundCenter(s, i, i, start, maxLen);
            
            // Case 2: Even length palindrome (e.g., "abba")
            // The center is between characters at 'i' and 'i+1'
            expandAroundCenter(s, i, i + 1, start, maxLen);
        }

        return s.substr(start, maxLen);
    }
};

// Example usage
int main() {
    Solution sol;
    string s1 = "babad";
    string s2 = "cbbd";
    cout << "Longest palindrome in '" << s1 << "': " << sol.longestPalindrome(s1) << endl; // Expected: "bab" or "aba"
    cout << "Longest palindrome in '" << s2 << "': " << sol.longestPalindrome(s2) << endl; // Expected: "bb"
    return 0;
}