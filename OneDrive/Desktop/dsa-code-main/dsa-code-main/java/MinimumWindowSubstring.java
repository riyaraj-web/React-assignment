import java.util.*;

/**
 * Minimum Window Substring - Sliding Window Approach
 * Find smallest substring containing all characters of pattern.
 */
public class MinimumWindowSubstring {
    
    public String minWindow(String s, String p) {
        if (s.length() < p.length()) return "";
        
        Map<Character, Integer> pCount = new HashMap<>();
        for (char c : p.toCharArray()) {
            pCount.put(c, pCount.getOrDefault(c, 0) + 1);
        }
        
        int left = 0, minLen = Integer.MAX_VALUE, minStart = 0;
        int required = pCount.size(), formed = 0;
        Map<Character, Integer> windowCount = new HashMap<>();
        
        for (int right = 0; right < s.length(); right++) {
            char c = s.charAt(right);
            windowCount.put(c, windowCount.getOrDefault(c, 0) + 1);
            
            if (pCount.containsKey(c) && windowCount.get(c).intValue() == pCount.get(c).intValue()) {
                formed++;
            }
            
            while (left <= right && formed == required) {
                if (right - left + 1 < minLen) {
                    minLen = right - left + 1;
                    minStart = left;
                }
                
                char leftChar = s.charAt(left);
                windowCount.put(leftChar, windowCount.get(leftChar) - 1);
                if (pCount.containsKey(leftChar) && windowCount.get(leftChar) < pCount.get(leftChar)) {
                    formed--;
                }
                left++;
            }
        }
        
        return minLen == Integer.MAX_VALUE ? "" : s.substring(minStart, minStart + minLen);
    }
    
    public static void main(String[] args) {
        MinimumWindowSubstring solution = new MinimumWindowSubstring();
        
        // Test case 1
        String s1 = "timetopractice", p1 = "toc";
        System.out.println("s = \"" + s1 + "\", p = \"" + p1 + "\"");
        System.out.println("Result: \"" + solution.minWindow(s1, p1) + "\""); // "toprac"
        
        // Test case 2
        String s2 = "zoomlazapzo", p2 = "oza";
        System.out.println("\ns = \"" + s2 + "\", p = \"" + p2 + "\"");
        System.out.println("Result: \"" + solution.minWindow(s2, p2) + "\""); // "apzo"
    }
}