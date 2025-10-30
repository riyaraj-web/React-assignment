// Problem: Longest Palindromic Substring - LeetCode 5
// Description:
//   Implements Manacher's algorithm to find the longest palindromic substring in O(n) time.
//   Returns the substring itself along with its length.
//
// Complexity:
//   Time: O(n)
//   Space: O(n) for transformed string / radius arrays.

#include <bits/stdc++.h>
using namespace std;

string longestPalindromeManacher(const string &s) {
    if (s.empty()) return "";
    // Transform string: ^#a#b#c#$ to handle even-length palindromes uniformly
    string t = "^";
    for (char c : s) {
        t += "#";
        t += c;
    }
    t += "#$";

    int n = t.size();
    vector<int> p(n, 0);
    int center = 0, right = 0;
    for (int i = 1; i < n - 1; ++i) {
        int mirror = 2*center - i;
        if (i < right) p[i] = min(right - i, p[mirror]);
        // expand around i
        while (t[i + 1 + p[i]] == t[i - 1 - p[i]]) ++p[i];
        if (i + p[i] > right) {
            center = i;
            right = i + p[i];
        }
    }
    // find max palindrome radius
    int maxLen = 0, centerIndex = 0;
    for (int i = 1; i < n - 1; ++i) {
        if (p[i] > maxLen) {
            maxLen = p[i];
            centerIndex = i;
        }
    }
    int start = (centerIndex - maxLen - 1) / 2; // map back to original string indices
    return s.substr(start, maxLen);
}

// Example usage
int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    string s1 = "babad";
    cout << "Longest palindrome in \"" << s1 << "\": " << longestPalindromeManacher(s1) << '\n';

    string s2 = "cbbd";
    cout << "Longest palindrome in \"" << s2 << "\": " << longestPalindromeManacher(s2) << '\n';

    return 0;
}
