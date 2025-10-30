class Solution {
    public int mySqrt(int x) {
        return binarySearch(x);
    }

    private int binarySearch(int n) {
        int start = 0;
        int end = n;
        int mid = start + (end - start) / 2;
        int ans = -1;

        while (start <= end) {
            long square = (long) mid * mid;

            if (square == n) {
                return mid;
            } else if (square < n) {
                ans = mid;
                start = mid + 1;
            } else {
                end = mid - 1;
            }
            mid = start + (end - start) / 2;
        }
        return ans;
    }
}