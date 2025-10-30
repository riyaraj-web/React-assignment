#include <iostream>
#include <string>
#include <unordered_set>
using namespace std;

int lengthOfLongestSubstring(string s) {
    unordered_set<char> seen;
    int left = 0, maxLen = 0;

    for (int right = 0; right < s.size(); ++right) {
        while (seen.count(s[right])) {
            seen.erase(s[left]);
            left++;
        }
        seen.insert(s[right]);
        maxLen = max(maxLen, right - left + 1);
    }
    return maxLen;
}

int main() {
    string s;
    cout << "Enter a string: ";
    cin >> s;
    cout << "Length of longest substring without repeating characters: "
         << lengthOfLongestSubstring(s) << endl;
}
