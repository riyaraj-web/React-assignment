// 30. Substring with Concatenation of All Words
// Hard
// Topics
// premium lock icon
// Companies
// You are given a string s and an array of strings words. All the strings of words are of the same length.

// A concatenated string is a string that exactly contains all the strings of any permutation of words concatenated.

// For example, if words = ["ab","cd","ef"], then "abcdef", "abefcd", "cdabef", "cdefab", "efabcd", and "efcdab" are all concatenated strings. "acdbef" is not a concatenated string because it is not the concatenation of any permutation of words.
// Return an array of the starting indices of all the concatenated substrings in s. You can return the answer in any order.

 

// Example 1:

// Input: s = "barfoothefoobarman", words = ["foo","bar"]

// Output: [0,9]

// Explanation:

// The substring starting at 0 is "barfoo". It is the concatenation of ["bar","foo"] which is a permutation of words.
// The substring starting at 9 is "foobar". It is the concatenation of ["foo","bar"] which is a permutation of words.

// Example 2:

// Input: s = "wordgoodgoodgoodbestword", words = ["word","good","best","word"]

// Output: []

// Explanation:

// There is no concatenated substring.

// Example 3:

// Input: s = "barfoofoobarthefoobarman", words = ["bar","foo","the"]

// Output: [6,9,12]

// Explanation:

// The substring starting at 6 is "foobarthe". It is the concatenation of ["foo","bar","the"].
// The substring starting at 9 is "barthefoo". It is the concatenation of ["bar","the","foo"].
// The substring starting at 12 is "thefoobar". It is the concatenation of ["the","foo","bar"].

 

// Constraints:

// 1 <= s.length <= 104
// 1 <= words.length <= 5000
// 1 <= words[i].length <= 30
// s and words[i] consist of lowercase English letters.

class Solution {
    // This is the reference map.
    std::unordered_map<std::string, unsigned int> map;
public:
    vector<int> findSubstring(string s, vector<string>& words) {
        std::vector<int> result;

        // Length of each word in words.
        unsigned int length = words[0].size();

        // Initializing the reference map.
        map.clear();
        for (const std::string& word : words)
            map[word]++;

        // Iterate for each offset
        // As many times as the number of characters in each word.
        for (unsigned int offset = 0; offset < length; ++offset) {
            // Sliding window size.
            unsigned int size = 0;
            // Sliding window memory.
            std::unordered_map<std::string, unsigned int> seen;

            // Iterate over the string, with the step equals to length.
            for (unsigned int i = offset; i + length <= s.size(); i += length) {
                // This is the word we're going to check.
                std::string sub = s.substr(i, length);

                // If the word is absent in the reference map,
                // we clear the sliding window and move on.
                auto itr = map.find(sub);
                if (itr == map.end()) {
                    seen.clear();
                    size = 0;
                    continue;
                }

                // Increase the number of occurrences
                // of the word in seen map.
                ++seen[sub];
                ++size;

                // To make sure the sliding window is valid,
                // we need to check only the recent occurrence
                // against the reference,
                // because previous occurrences
                // were checked on previous iterations.
                while (seen[sub] > itr->second) {
                    // If the occurrences amount exceeds
                    // the reference amount,
                    // we shrink the window from the left until
                    // the window becomes valid again.

                    // A word at the beginning of the current sliding window.
                    std::string first = s.substr(i - (size - 1) * length, length);

                    // Remove the occurrence from the window,
                    // shrinking it from the left.
                    --seen[first];
                    --size;
                }
                
                // If we used all words from the words array,
                // we have found the correct spot
                // and we need to calculate the beginning
                // index of the current sliding window.
                if (size == words.size())
                    result.push_back(i - (size - 1) * length);
            }
        }

        return result;
    }
};