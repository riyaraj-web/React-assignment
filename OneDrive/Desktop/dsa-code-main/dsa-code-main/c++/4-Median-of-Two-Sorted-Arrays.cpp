// Leetcode Qn. 04 > MEDIAN OF TWO SORTED ARRAYS (HARD)
// it is a brute force solution 
class Solution {
public:
    double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {
        vector<int> merged;
        merged.insert(merged.end(), nums1.begin(), nums1.end());
        merged.insert(merged.end(), nums2.begin(), nums2.end());
        sort(merged.begin(), merged.end());
        int n = merged.size();
        if (n % 2 == 1) {
            return merged[n / 2];
        } else {
            return (merged[n / 2 - 1] + merged[n / 2]) / 2.0;
        }
    }
};
// time complixity -> O((m+n)log(m+n))