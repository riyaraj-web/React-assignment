/*
 Problem: Longest Substring Without Repeating Characters

 Given a string s, find:
   1) The length of the longest substring without repeating characters.
   2) Optionally, return one such longest substring.

 Example
   Input:  "abcabcbb"
   Output: 3
   Explanation: The answer is "abc", with the length of 3.

 Approaches

 1) Sliding Window + HashMap of Last-Seen Index (Recommended)
    - Maintain a window [left..right] with no duplicate characters.
    - Use a Map<Character, Integer> to track the last index where each character appeared.
    - When you see a repeated character c at index right:
        left = max(left, lastSeen[c] + 1)
      This "jumps" the left boundary past the previous occurrence, preserving O(n) time.
    - Time: O(n) because each index is visited at most twice (once by right, once by left jump).
    - Space: O(k), where k is the character set size appearing in s (≤ n).
    - Pros: Simple, robust for general Unicode in the BMP (char-based).
    - Cons: For supplementary Unicode code points (outside BMP), char-based methods treat surrogate pairs separately.

 2) Sliding Window + Fixed Array (ASCII Optimization)
    - Use an int[256] array initialized to -1 for last-seen indices (extended ASCII).
    - Same logic as above, but constant-time array access is faster and memory-light.
    - If a non-ASCII character (> 255) is detected, fall back to the HashMap method.
    - Time: O(n)
    - Space: O(1) bounded by 256
    - Pros: Very fast and cache-friendly for ASCII inputs.
    - Cons: Not safe for non-ASCII; we detect and fall back.

 3) Brute Force (For completeness; not implemented)
    - Check all substrings and test uniqueness with a Set.
    - Time: O(n^3) naive, or O(n^2) with some optimizations—still impractical for interviews when O(n) exists.

 Edge Cases
   - s is null or empty -> length = 0; substring = "".
   - All characters same -> length = 1.
   - String with spaces/punctuation -> treated as valid characters.
   - Unicode note: This implementation is char-based (UTF-16 code units). For full code point correctness,
     you can rework it to iterate over code points and use an Int2IntMap keyed by code point.

 Complexity
   - Time: O(n) for sliding window methods.
   - Space: O(k), k = distinct characters in the window (HashMap) or O(1) for ASCII array.

 How to Run
   # From repo root (adjust path if needed)
   javac Java/Strings/LongestUniqueSubstring.java
   java -cp Java/Strings LongestUniqueSubstring            # runs built-in demos
   java -cp Java/Strings LongestUniqueSubstring "pwwkew"   # runs on your input

 References
   - LeetCode: Longest Substring Without Repeating Characters
     https://leetcode.com/problems/longest-substring-without-repeating-characters/
   - GeeksforGeeks: Length of the longest substring without repeating characters
     https://www.geeksforgeeks.org/length-of-the-longest-substring-without-repeating-characters/

 Attribution
   - Language: Java
   - Tags: Strings, Sliding Window, Hashing, Two Pointers, Interview Prep
   - Hacktoberfest: Suitable as a meaningful contribution (place the note about Hacktoberfest in the PR description; not required in code)
*/

import java.util.Arrays;
import java.util.HashMap;
import java.util.Map;

public class LongestUniqueSubstring {

    /**
     * Returns the length of the longest substring without repeating characters,
     * using an optimized sliding window with last-seen indices in a HashMap.
     *
     * Time Complexity: O(n)
     * Space Complexity: O(k), k = number of distinct characters in s
     */
    public static int lengthOfLongestSubstring(String s) {
        if (s == null || s.isEmpty()) return 0;

        Map<Character, Integer> last = new HashMap<>(); // char -> last index
        int best = 0, left = 0; // window is [left..right]
        for (int right = 0; right < s.length(); right++) {
            char c = s.charAt(right);
            Integer prev = last.get(c);
            if (prev != null && prev >= left) {
                left = prev + 1; // jump left past the previous occurrence
            }
            last.put(c, right);
            best = Math.max(best, right - left + 1);
        }
        return best;
    }

    /**
     * ASCII-optimized variant: uses an int[256] for last-seen indices.
     * If a non-ASCII character is detected, falls back to the HashMap method.
     *
     * Time Complexity: O(n)
     * Space Complexity: O(1) bounded by 256
     */
    public static int lengthOfLongestSubstringAscii(String s) {
        if (s == null || s.isEmpty()) return 0;

        int[] last = new int[256];
        Arrays.fill(last, -1);

        int best = 0, left = 0;
        for (int right = 0; right < s.length(); right++) {
            char raw = s.charAt(right);
            if (raw > 255) {
                // Non-ASCII detected; fall back for correctness
                return lengthOfLongestSubstring(s);
            }
            int prev = last[raw];
            if (prev >= left) {
                left = prev + 1;
            }
            last[raw] = right;
            best = Math.max(best, right - left + 1);
        }
        return best;
    }

    /**
     * Returns one longest substring without repeating characters (not just its length),
     * using the HashMap sliding window approach.
     *
     * Time Complexity: O(n)
     * Space Complexity: O(k)
     */
    public static String longestUniqueSubstring(String s) {
        if (s == null || s.isEmpty()) return "";

        Map<Character, Integer> last = new HashMap<>();
        int bestLen = 0, bestStart = 0;
        int left = 0;

        for (int right = 0; right < s.length(); right++) {
            char c = s.charAt(right);
            Integer prev = last.get(c);
            if (prev != null && prev >= left) {
                left = prev + 1;
            }
            last.put(c, right);

            int windowLen = right - left + 1;
            if (windowLen > bestLen) {
                bestLen = windowLen;
                bestStart = left;
            }
        }
        return s.substring(bestStart, bestStart + bestLen);
    }

    // Simple CLI and demo
    public static void main(String[] args) {
        if (args != null && args.length > 0) {
            String input = String.join(" ", args);
            System.out.println("Input: " + quote(input));
            System.out.println("Length (HashMap): " + lengthOfLongestSubstring(input));
            System.out.println("Length (ASCII optimized): " + lengthOfLongestSubstringAscii(input));
            System.out.println("Substring (HashMap): " + quote(longestUniqueSubstring(input)));
            return;
        }

        // Demo cases (covering common edge cases)
        String[] samples = {
            "abcabcbb",  // 3 ("abc")
            "bbbbb",     // 1 ("b")
            "pwwkew",    // 3 ("wke" or "kew")
            "",          // 0 ("")
            "dvdf",      // 3 ("vdf")
            "au",        // 2 ("au")
            "aab",       // 2 ("ab")
            "abba",      // 2 ("ab" or "ba")
            "tmmzuxt",   // 5 ("mzuxt")
            "anviaj",    // 5 ("nviaj")
        };

        System.out.println("Demo (HashMap approach):");
        for (String s : samples) {
            System.out.printf("Input: %-12s -> len=%d, sub=%s%n",
                    quote(s), lengthOfLongestSubstring(s), quote(longestUniqueSubstring(s)));
        }

        System.out.println("\nDemo (ASCII-optimized approach):");
        for (String s : samples) {
            System.out.printf("Input: %-12s -> len=%d%n",
                    quote(s), lengthOfLongestSubstringAscii(s));
        }
    }

    private static String quote(String s) {
        return s == null ? "null" : "\"" + s + "\"";
    }
}
