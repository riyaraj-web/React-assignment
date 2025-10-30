#include <iostream>
#include <unordered_map>
#include <string>
#include <algorithm>

using namespace std;

int lengthOfLongestSubstring(string s) {
    unordered_map<char, int> charIndexMap;
    int start = 0, maxLength = 0;

    for (int end = 0; end < s.length(); ++end) {
        // If character is already in the map, move the start pointer
        if (charIndexMap.find(s[end]) != charIndexMap.end()) {
            start = max(start, charIndexMap[s[end]] + 1);
        }

        // Update the position of the current character
        charIndexMap[s[end]] = end;

        // Calculate the current length of the substring
        maxLength = max(maxLength, end - start + 1);
    }

    return maxLength;
}

int main() {
    string s = "abcabcbb";
    cout << "Longest Substring Length: " << lengthOfLongestSubstring(s) << endl;
    return 0;
}
