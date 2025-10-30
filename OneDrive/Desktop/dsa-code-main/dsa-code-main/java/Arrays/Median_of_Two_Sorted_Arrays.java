class Solution {
    public double findMedianSortedArrays(int[] smaller, int[] larger) {
        if(smaller.length > larger.length) return findMedianSortedArrays(larger, smaller);
        int sn = smaller.length, ln = larger.length;
        int low = 0, high = sn;

        while(low <= high) {
            int mid1 = low + (high - low)/2; // x -> the no. of elements I take from A1
            int mid2 = (sn + ln + 1)/2 - mid1; // because I need to take (real mid (median point) - mid1); this gives me no. of elements I can take from A2

            int l1 = mid1 == 0 ? Integer.MIN_VALUE : smaller[mid1-1]; // if mid1 is 0 that means no elements are taken from A1, so minimum value
            int l2 = mid2 == 0 ? Integer.MIN_VALUE : larger[mid2-1]; // if mid2 is 0 that means no elements are taken from A2

            int r1 = mid1 == sn ? Integer.MAX_VALUE : smaller[mid1];
            int r2 = mid2 == ln ? Integer.MAX_VALUE : larger[mid2];

            if(l1 <= r2 && l2 <= r1) {
                if((sn + ln)%2 == 1) 
                    return Math.max(l1, l2);
                else 
                    return (Math.max(l1, l2) + Math.min(r1, r2))/2.0;
            } else if(l1 > r2) {
                high = mid1-1;
            } else { // l2 > r1
                low = mid1+1;
            }
        }

        return 0.0;
    }
}