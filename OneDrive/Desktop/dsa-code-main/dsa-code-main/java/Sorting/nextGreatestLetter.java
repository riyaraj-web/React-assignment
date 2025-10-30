
public class nextGreatestLetter {
    public static void main(String[] args) {

        int[] arr = {2, 3, 5, 9, 14, 16, 18};
        int target = 15;
        int ans = Ceiling(arr, target);
        System.out.println(ans);
    }

        static int Ceiling(int[] arr, int target) {

                if (target > arr[arr.length - 1]) {
            return -1;
        }

        int start = 0;
        int end = arr.length - 1;

        while (start <= end) {
            int mid = start + (end - start) / 2;

            if (target < arr[mid]) {
                end = mid - 1;
            } else if (target > arr[mid]) {
                start = mid + 1;
            } else {
                return arr[mid]; // found exact match
            }
        }
        return arr[start]; // smallest element >= target
    }
}