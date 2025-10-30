public class SubSequences {
  /**
   * If S and T are strings, we say that S is a subsequence of T if all
   * letters of S appear in T in the same order (not necessarily consecutively).
   * For example, "ace" is a subsequence of "abcde" while "aec" is not.
   * Given two strings S and T, checks whether S is a subsequence of T.
   * 
   * Constraints:
   * 1. Your solution should be recursive and not use any loops.
   * 2. 0 <= len(S), len(T) <= 1000
   * 3. Strings are case-sensitive and contain only English letters.
   *
   * @param S - The subsequence string.
   * @param T - The target string.
   * @returns boolean - True if S is a subsequence of T, otherwise false.
   **/
  /**
   * Recursive helper method to check if string {@code t} is a subsequence of string {@code s}.
   *
   * @param t the target subsequence string
   * @param s the source string
   * @param i current index in {@code t}
   * @param j current index in {@code s}
   * @return true if {@code t} is a subsequence of {@code s}, otherwise false
   */
  private boolean helper(String t, String s, int i, int j) {
    if (i == t.length()) {
      return true;
    }
    if (j == s.length()) {
      return false;
    }
    if (t.charAt(i) == s.charAt(j)) {
      if (helper(t, s, i + 1, j + 1)) {
        return true;
      }
    }
    return helper(t, s, i, j + 1);
  }

  /**
   * Checks whether string {@code t} is a subsequence of string {@code s}.
   *
   * @param t the target subsequence string
   * @param s the source string
   * @return true if {@code t} is a subsequence of {@code s}, otherwise false
   */
  public boolean isSubsequence(String t, String s) {
    return helper(t, s, 0, 0);
  }

  /**
   * Main method for testing the SubSequences class.
   */
  public static void main(String[] args) {
    SubSequences subsequences = new SubSequences();
    assert subsequences.isSubsequence("ace", "abcde") == true : "Test case 1 failed";
    assert subsequences.isSubsequence("aec", "abcde") == false : "Test case 2 failed";
    assert subsequences.isSubsequence("", "abcde") == true : "Test case 3 failed";
    assert subsequences.isSubsequence("abc", "") == false : "Test case 4 failed";
    assert subsequences.isSubsequence("abc", "ahbgdc") == true : "Test case 5 failed";
    assert subsequences.isSubsequence("axc", "ahbgdc") == false : "Test case 6 failed";
  }
}
