import java.util.*;

/**
 * Top K Frequent Elements - Priority Queue Approach
 * Find k most frequent elements with larger number preference for ties.
 */
public class TopKFrequent {
    
    public int[] topKFrequent(int[] arr, int k) {
        Map<Integer, Integer> freqMap = new HashMap<>();
        for (int num : arr) {
            freqMap.put(num, freqMap.getOrDefault(num, 0) + 1);
        }
        
        PriorityQueue<Integer> pq = new PriorityQueue<>((a, b) -> {
            int freqCompare = freqMap.get(b) - freqMap.get(a);
            return freqCompare != 0 ? freqCompare : b - a;
        });
        
        pq.addAll(freqMap.keySet());
        
        int[] result = new int[k];
        for (int i = 0; i < k; i++) {
            result[i] = pq.poll();
        }
        
        return result;
    }
    
    public static void main(String[] args) {
        TopKFrequent solution = new TopKFrequent();
        
        // Test case 1
        int[] arr1 = {3, 1, 4, 4, 5, 2, 6, 1};
        int[] result1 = solution.topKFrequent(arr1, 2);
        System.out.println("Array: [3,1,4,4,5,2,6,1], k=2");
        System.out.println("Result: " + Arrays.toString(result1)); // [4, 1]
        
        // Test case 2
        int[] arr2 = {7, 10, 11, 5, 2, 5, 5, 7, 11, 8, 9};
        int[] result2 = solution.topKFrequent(arr2, 4);
        System.out.println("\nArray: [7,10,11,5,2,5,5,7,11,8,9], k=4");
        System.out.println("Result: " + Arrays.toString(result2)); // [5, 11, 7, 10]
    }
}