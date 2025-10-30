public class CountEvenOdd {
    public static void countEvenOdd(int[] nums) {
        int even = 0, odd = 0;

        for (int num : nums) {
            if (num % 2 == 0) even++;
            else odd++;
        }

        System.out.println("Even: " + even);
        System.out.println("
