//https://leetcode.com/problems/rotate-string/

/* Rotate String

Given two strings s and goal, return true if and only if s can become goal after some number of shifts on s.

A shift on s consists of moving the leftmost character of s to the rightmost position.

For example, if s = "abcde", then it will be "bcdea" after one shift.
 

Example 1:

Input: s = "abcde", goal = "cdeab"
Output: true
Example 2:

Input: s = "abcde", goal = "abced"
Output: false
 

Constraints:

1 <= s.length, goal.length <= 100
s and goal consist of lowercase English letters.
*/

class Solution {
public:
    bool rotateString(string s, string goal) {
        int n = s.length();
        if (n != goal.length()) return false;
        if (s == goal) return true;

        // Check every possible rotation
        for (int i = 1; i < n; i++) {
            bool match = true;
            for (int j = 0; j < n; j++) {
                if (s[(i + j) % n] != goal[j]) {
                    match = false;
                    break;
                }
            }
            if (match) return true;
        }

        return false;
    }
};

/*Explanation:
The code checks if goal can be obtained by rotating s.

i = number of positions to rotate left.

s[(i + j) % n] picks characters from s after rotation (wraps around using % n).

For each rotation, it compares all characters with goal.

If a rotation matches → return true; if none match → return false.

Time: O(n²), Space: O(1).
*/