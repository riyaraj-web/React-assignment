
public class TriangularSumArray {

    public static void main(String[] args) {
        // Example input
        int[] nums = {1, 2, 3, 4, 5};

        // Call the function
        int result = triangularSum(nums);

        // Print the result
        System.out.println("Triangular Sum: " + result);
    }

    public static int triangularSum(int[] nums) {
        int n = nums.length;

        // Reduce the array step by step
        for (int size = n; size > 1; size--) {
            for (int i = 0; i < size - 1; i++) {
                nums[i] = (nums[i] + nums[i + 1]) % 10;
            }
        }

        // The first element becomes the final triangular sum
        return nums[0];
    }
}
