import java.util.*;

class Solution {
    public List<Integer> leaders(int[] arr) {
        int n = arr.length;
        List<Integer> leaders = new ArrayList<>();
        
        // Start with the rightmost element (always a leader)
        int maxFromRight = arr[n - 1];
        leaders.add(maxFromRight);
        
        // Traverse from right to left
        for (int i = n - 2; i >= 0; i--) {
            if (arr[i] > maxFromRight) {
                leaders.add(arr[i]);
                maxFromRight = arr[i];
            }
        }
        
        // Reverse since we collected leaders in reverse order
        Collections.reverse(leaders);
        return leaders;
    }
}

public class AllLeadersInTheArray {
    public static void main(String[] args) {
        Solution solution = new Solution();
        Scanner sc = new Scanner(System.in);
        
        System.out.print("Enter number of elements: ");
        int n = sc.nextInt();
        int[] arr = new int[n];
        
        System.out.println("Enter the array elements:");
        for (int i = 0; i < n; i++) {
            arr[i] = sc.nextInt();
        }
        
        List<Integer> leaders = solution.leaders(arr);
        System.out.println("Leaders in the array: " + leaders);
    }
}
