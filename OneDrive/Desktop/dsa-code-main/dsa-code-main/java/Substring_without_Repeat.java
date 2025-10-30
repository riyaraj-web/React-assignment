import java.util.*;

class Substring_without_Repeat {

    public int lengthOfLongestSubstring(String s) {
        Set<Character> set = new HashSet<>();
        int left = 0;
        int maxLength = 0;

        for (int right = 0; right < s.length(); right++) {
            while (set.contains(s.charAt(right))) {
                set.remove(s.charAt(left));
                left++;
            }

            set.add(s.charAt(right));
            maxLength = Math.max(maxLength, right - left + 1);
        }

        return maxLength;
    }

    public static void main(String[] args) {
        Substring_without_Repeat obj = new Substring_without_Repeat();

        String s = "abcabcbb"; // You can change this input
        int result = obj.lengthOfLongestSubstring(s);

        System.out.println("Length of the longest substring without repeating characters: " + result);
    }
}
