#include <iostream>
#include <vector>
#include <numeric>

using namespace std;

/*
Problem: Product of Array Except Self
Technique: Two-Pass Prefix/Suffix Products
Time Complexity: O(N)
Space Complexity: O(1) (excluding the output array, as per problem constraints)

Description:
Given an integer array nums, return an array answer such that answer[i] is equal 
to the product of all the elements of nums except nums[i].
The product of any prefix or suffix of nums is guaranteed to fit in a 32-bit integer.
You must write an algorithm that runs in O(N) time and without using the division operation.
*/

class Solution {
public:
    vector<int> productExceptSelf(vector<int>& nums) {
        int n = nums.size();
        // The output array will store the result. We initialize it to 1s.
        vector<int> output(n, 1);

        // =======================================================
        // PASS 1: Calculate the product of all elements *to the left* of i
        // The output[i] will store PrefixProduct[i-1]
        // =======================================================
        int prefixProduct = 1;
        for (int i = 0; i < n; i++) {
            // output[i] now holds the product of elements before nums[i]
            output[i] = prefixProduct;
            // Update prefixProduct for the next iteration
            prefixProduct *= nums[i];
        }

        // After Pass 1 (Example: nums = [1, 2, 3, 4]):
        // output = [1, 1, 2, 6]
        // prefixProduct = 24

        // =======================================================
        // PASS 2: Multiply the current output[i] (Left Product) by 
        // the product of all elements *to the right* of i (Suffix Product)
        // We calculate the Suffix Product on the fly from right-to-left.
        // =======================================================
        int suffixProduct = 1;
        for (int i = n - 1; i >= 0; i--) {
            // output[i] = (Product of elements to the left) * (Product of elements to the right)
            output[i] *= suffixProduct;
            // Update suffixProduct for the next iteration (i-1)
            suffixProduct *= nums[i];
        }
        
        // After Pass 2 (Example: nums = [1, 2, 3, 4]):
        // i=3: output[3]=6*1=6, suffixProduct=1*4=4
        // i=2: output[2]=2*4=8, suffixProduct=4*3=12
        // i=1: output[1]=1*12=12, suffixProduct=12*2=24
        // i=0: output[0]=1*24=24, suffixProduct=24*1=24
        // Final output = [24, 12, 8, 6]

        return output;
    }
};

// Test cases
int main() {
    Solution solution;
    
    vector<int> nums1 = {1, 2, 3, 4};
    vector<int> result1 = solution.productExceptSelf(nums1); // Expected: [24, 12, 8, 6]
    cout << "Test 1: [";
    for(int i = 0; i < result1.size(); ++i) {
        cout << result1[i] << (i == result1.size() - 1 ? "" : ", ");
    }
    cout << "]" << endl;

    vector<int> nums2 = {-1, 1, 0, -3, 3};
    vector<int> result2 = solution.productExceptSelf(nums2); // Expected: [0, 0, 9, 0, 0]
    cout << "Test 2: [";
    for(int i = 0; i < result2.size(); ++i) {
        cout << result2[i] << (i == result2.size() - 1 ? "" : ", ");
    }
    cout << "]" << endl;
    
    return 0;
}