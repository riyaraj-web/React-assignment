#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int largestElement(vector<int>& nums) {
        // Initialize max as the first element
        int max = nums[0];

        // Traverse the entire array
        for (int i = 1; i < nums.size(); i++) {

            /* If current element is greater
            than max, update max*/
            if (nums[i] > max) {
                max = nums[i];
            }

        }
        // Return the largest element found
        return max;
    }
};

int main() {
    vector nums = {3, 2, 1, 5, 2};

 // Create an instance of the Solution class
    Solution sol;

    int largest = sol.largestElement(nums);

    // Print the largest element in the array.
    cout << largest << endl;
    return 0;
}