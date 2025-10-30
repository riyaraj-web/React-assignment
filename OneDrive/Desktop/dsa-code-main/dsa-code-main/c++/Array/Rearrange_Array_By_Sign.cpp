#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    vector<int> rearrangeArray(vector<int>& nums) {
        int n = nums.size();
        vector<int> ans(n); // final rearranged array

        int posIndex = 0; // even positions (for positives)
        int negIndex = 1; // odd positions (for negatives)

        // Go through all elements
        for (int i = 0; i < n; i++) {
            if (nums[i] > 0) {
                ans[posIndex] = nums[i];
                posIndex += 2;
            } else {
                ans[negIndex] = nums[i];
                negIndex += 2;
            }
        }
        return ans;
    }
};

int main() {
    Solution s;
    vector<int> nums = {3, 1, -2, -5, 2, -4};

    vector<int> ans = s.rearrangeArray(nums);

    cout << "Rearranged array: ";
    for (int i = 0; i < ans.size(); i++) {
        cout << ans[i] << " ";
    }
    cout << endl;

    return 0;
}
