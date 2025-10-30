//3718. Smallest Missing Multiple of K
// Weekly Contest 472 Question 1 in Java
import java.util.*;

class Solution {
    public int missingMultiple(int[] nums, int k) {
        Set<Integer> s = new HashSet<>();
        for (int num : nums) {
            s.add(num);
        }
        int current = k;
        while (s.contains(current)) {
            current += k;
        }
        return current;
    }
}
