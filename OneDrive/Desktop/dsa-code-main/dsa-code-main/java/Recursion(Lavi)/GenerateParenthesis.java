import java.util.*;

public class GenerateParenthesis {
  /**
   * Given n pairs of parentheses, write a function to generate all combinations of well-formed
   * parentheses.
   * 
   * Constraints:
   * 1. 1 <= n <= 8
   * 2. The solution set must not contain duplicate combinations.
   * 
   * Example:
   * Input: n = 3
   * Output: ["((()))","(()())","(())()","()(())","()()()"]
   * 
   * @param n - Number of pairs of parentheses.
   * @returns List<String> - A list of all combinations of well-formed parentheses.
   */
  private void helper(int n, List<String> res, StringBuilder sb, int open, int close) {
    if (sb.length() == 2 * n) {
      res.add(new String(sb));
    }
    if (open < n) {
      sb.append("(");
      helper(n, res, sb, open + 1, close);
      sb.deleteCharAt(sb.length() - 1);
    }
    if (close < open) {
      sb.append(")");
      helper(n, res, sb, open, close + 1);
      sb.deleteCharAt(sb.length() - 1);
    }
  }

  public List<String> generateParenthesis(int n) {
    if (n == 0) {
      return new ArrayList<>();
    }
    List<String> res = new ArrayList<>();
    helper(n, res, new StringBuilder(), 0, 0);
    return res;
  }

  /**
   * Main method for testing the GenerateParenthesis class.
   */
  public static void main(String[] args) {
    GenerateParenthesis gp = new GenerateParenthesis();
    int n = 3;
    List<String> result = gp.generateParenthesis(n);
    List<String> expected = Arrays.asList("((()))", "(()())", "(())()", "()(())", "()()()");
    
    assert result.size() == expected.size() && result.containsAll(expected)
        : "Test case failed";
    System.out.println("Passed");
  }
}

