#include <iostream>
#include <vector>
#include <unordered_map>
using namespace std;

vector<int> twoSum(vector<int>& nums, int target) {
    unordered_map<int, int> mp; // value -> index
    for (int i = 0; i < nums.size(); i++) {
        int complement = target - nums[i];
        if (mp.find(complement) != mp.end()) {
            return {mp[complement], i}; // return indices
        }
        mp[nums[i]] = i;
    }
    return {}; // no solution
}

int main() {
    int n, target;
    cout << "Enter number of elements: ";
    cin >> n;

    vector<int> nums(n);
    cout << "Enter the elements: ";
    for (int i = 0; i < n; i++) {
        cin >> nums[i];
    }

    cout << "Enter target value: ";
    cin >> target;

    vector<int> result = twoSum(nums, target);

    if (!result.empty()) {
        cout << "Indices: " << result[0] << " and " << result[1] << endl;
        cout << "Numbers: " << nums[result[0]] << " and " << nums[result[1]] << endl;
    } else {
        cout << "No solution found!" << endl;
    }

    return 0;
}
