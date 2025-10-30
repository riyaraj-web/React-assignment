#include <iostream>
#include <vector>
#include <algorithm> 

using namespace std;

// Function to find the median of two sorted arrays
double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {
    // Step 1: Merge both arrays
    for (int i = 0; i < nums2.size(); i++) {
        nums1.emplace_back(nums2[i]);  // add elements of nums2 to nums1
    }

    // Step 2: Sort the merged array
    sort(nums1.begin(), nums1.end());

    // Step 3: Find the median
    int n = nums1.size();
    int mid = n / 2;

    // If number of elements is even, average of two middle elements
    if (n % 2 == 0) {
        return (nums1[mid] + nums1[mid - 1]) / 2.0;
    }

    // If number of elements is odd, middle element is median
    return nums1[mid];
}

// Main function to test the code
int main() {
    vector<int> nums1 = {1, 3};
    vector<int> nums2 = {2};

    double median = findMedianSortedArrays(nums1, nums2);

    cout << "Median is: " << median << endl;

    return 0;
}
