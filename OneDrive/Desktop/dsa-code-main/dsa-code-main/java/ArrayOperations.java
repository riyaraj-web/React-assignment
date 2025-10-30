import java.util.*;

public class ArrayOperations {
    
    // Find maximum element in array
    public int findMax(int[] arr) {
        int max = arr[0];
        for (int i = 1; i < arr.length; i++) {
            if (arr[i] > max) max = arr[i];
        }
        return max;
    }
    
    // Reverse array in-place
    public void reverseArray(int[] arr) {
        int left = 0, right = arr.length - 1;
        while (left < right) {
            int temp = arr[left];
            arr[left] = arr[right];
            arr[right] = temp;
            left++;
            right--;
        }
    }
    
    // Find missing number in array 1 to n
    public int findMissing(int[] arr, int n) {
        int sum = n * (n + 1) / 2;
        for (int num : arr) {
            sum -= num;
        }
        return sum;
    }
    
    // Remove duplicates from sorted array
    public int removeDuplicates(int[] arr) {
        if (arr.length == 0) return 0;
        int j = 0;
        for (int i = 1; i < arr.length; i++) {
            if (arr[i] != arr[j]) {
                arr[++j] = arr[i];
            }
        }
        return j + 1;
    }
    
    // Rotate array right by k positions
    public void rotateRight(int[] arr, int k) {
        k %= arr.length;
        reverse(arr, 0, arr.length - 1);
        reverse(arr, 0, k - 1);
        reverse(arr, k, arr.length - 1);
    }
    
    private void reverse(int[] arr, int start, int end) {
        while (start < end) {
            int temp = arr[start];
            arr[start] = arr[end];
            arr[end] = temp;
            start++;
            end--;
        }
    }
    
    public static void main(String[] args) {
        ArrayOperations ap = new ArrayOperations();
        
        int[] arr = {3, 1, 4, 1, 5, 9, 2, 6};
        System.out.println("Max: " + ap.findMax(arr));
        
        ap.reverseArray(arr);
        System.out.println("Reversed: " + Arrays.toString(arr));
        
        System.out.println("Missing: " + ap.findMissing(new int[]{1,2,4,5}, 5));
    }
}