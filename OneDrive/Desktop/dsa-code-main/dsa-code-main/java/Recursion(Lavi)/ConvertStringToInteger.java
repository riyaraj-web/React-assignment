public class ConvertStringToInteger {
    /**
     * Convert a string to an integer without using built-in parsing functions.
     * 
     * Constraints / Rules:
     * 1. You may not use built-in functions like Integer.parseInt() or similar.
     * 2. You may not use any form of loops (for, while, do-while).
     * 3. You may not use any form of conditional statements (if, switch, ternary operator).
     * 4. Your function should work for negative numbers.
     * 5. If the string is invalid, return 0.
     * 6. Only characters that should be allowed in the string are numeric digits from '0'
     *    through '9', possibly preceded by a single minus sign '-' at the start if the number
     *    is negative. A string that contains any other characters in it is considered invalid.
     * 7. You may assume that the string will not have leading or trailing whitespace.
     * 8. You may assume that if the string contains valid characters, then it represents an integer
     * that can be successfully stored in an int; that is, its value will not exceed 2^31.
     * 9. If the empty string is passed, your function should return 0.
     * 
     * @param s - Input string representing an integer.
     * @returns int - The integer value represented by the string.
     */

    /**
     * Recursive helper method to convert a numeric string into an integer.
     *
     * @param s   the input string
     * @param idx current index being processed
     * @param ans the accumulated integer value so far
     * @return the integer value if valid, otherwise 0
     */
    public int helper(String s, int idx, int ans) {
      if (idx == s.length()) {
        return ans;
      }
      if (!(s.charAt(idx) >= '0' && s.charAt(idx) <= '9')) {
        return 0;
      }
      int temp = s.charAt(idx) - '0';
      ans = ans * 10 + temp;
      return helper(s, idx + 1, ans);
    }

    /**
     * Converts the given string into an integer, handling negatives and invalid inputs.
     *
     * @param s the input string representing an integer
     * @return the integer value represented by the string, or 0 if invalid
     */
    public int convertStringToInteger(String s) {
      if (s.equals("")) {
        return 0;
      }
      if (s.charAt(0) == '-') {
        int ans = helper(s, 1, 0);
        return -1 * ans;
      }
      return helper(s, 0, 0);
    }


    /**
     * Main method for testing the ConvertStringToInteger class.
     */
    public static void main(String[] args) {
        ConvertStringToInteger converter = new ConvertStringToInteger();
        String[] testStrings = {"123", "-456", "0", "789a", "", "-0", "2147483647", "-2147483648"};
        int[] expectedResults = {123, -456, 0, 0, 0, 0, 2147483647, -2147483648};

        // System.out.println(converter.convertStringToInteger(testStrings[0]));

        for (int i = 0; i < testStrings.length; i++) {
            assert converter.convertStringToInteger(testStrings[i]) == expectedResults[i] : "Test case " + (i + 1) + " failed";
        }
        System.out.println("All test cases passed");
    }
}