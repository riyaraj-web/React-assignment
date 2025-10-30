/**
 * A utility class for checking if a string of parentheses is valid.
 *
 * 
 */
public class ValidParenthesis {

  /**
   * Determines if the given string is valid using a recursive approach.
   *
   * @param s input string containing only '(', ')', '{', '}', '[' and ']'
   * @return true if the string is valid, false otherwise
   */
  public boolean isValidRecursive(String s) {
    // Base case: empty string is valid.
    if (s.isEmpty()) {
      return true;
    }

    // If the length is odd, it cannot be valid.
    if (s.length() % 2 != 0) {
      return false;
    }

    // Find the first valid pair.
    int index = s.indexOf("()");
    if (index == -1) {
      index = s.indexOf("[]");
    }
    if (index == -1) {
      index = s.indexOf("{}");
    }

    // If no valid pair is found, the string is invalid.
    if (index == -1) {
      return false;
    }

    // Remove the pair and recurse on the reduced string.
    String reduced = s.substring(0, index) + s.substring(index + 2);
    return isValidRecursive(reduced);
  }

  /**
   * Runs sample test cases for the recursive validation method.
   */
  public static void main(String[] args) {
    ValidParenthesis validator = new ValidParenthesis();

    String test1 = "()";
    String test2 = "()[]{}";
    String test3 = "(]";
    String test4 = "([)]";
    String test5 = "{[]}";

    assert validator.isValidRecursive(test1) : "Test case 1 failed";
    assert validator.isValidRecursive(test2) : "Test case 2 failed";
    assert !validator.isValidRecursive(test3) : "Test case 3 failed";
    assert !validator.isValidRecursive(test4) : "Test case 4 failed";
    assert validator.isValidRecursive(test5) : "Test case 5 failed";

    System.out.println("All test cases passed!");
  }
}

