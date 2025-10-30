/*
    Problem: Maximum Subarray Sum (Kadane's Algorithm)
    Language: C++
    Author: <your-name>
    Date: <today’s-date>
    Description:
        Given an integer array nums, find the contiguous subarray with the largest sum.

    Example:
        Input: [-2,1,-3,4,-1,2,1,-5,4]
        Output: 6  (because [4,-1,2,1] has the largest sum = 6)

    Time Complexity: O(n)
    Space Complexity: O(1)
*/

#include <iostream>
#include <vector>
#include <climits>
using namespace std;

int maxSubArray(vector<int>& nums) {
    int maxSoFar = INT_MIN, currSum = 0;
    for (int num : nums) {
        currSum = max(num, currSum + num);
        maxSoFar = max(maxSoFar, currSum);
    }
    return maxSoFar;
}

int main() {
    int n;
    cout << "Enter number of elements: ";
    cin >> n;
    vector<int> nums(n);
    cout << "Enter elements: ";
    for (int i = 0; i < n; i++) cin >> nums[i];
    cout << "Maximum Subarray Sum = " << maxSubArray(nums) << endl;
    return 0;
}
