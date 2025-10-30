#include <iostream>
#include <vector>
#include <unordered_map>

using namespace std;

vector<int> twoSum(vector<int>& nums, int target) {
    unordered_map<int, int> hashmap;
    vector<int> result;
    
    for (int i = 0; i < nums.size(); ++i) {
        int complement = target - nums[i];
        
        // Check if the complement is in the map
        if (hashmap.find(complement) != hashmap.end()) {
            result.push_back(hashmap[complement]);
            result.push_back(i);
            return result;
        }
        
        // Add current number and its index to the map
        hashmap[nums[i]] = i;
    }
    
    return result;  // Will never reach here if the input guarantees exactly one solution.
}

int main() {
    vector<int> nums = {2, 7, 11, 15};
    int target = 9;
    vector<int> result = twoSum(nums, target);
    
    cout << "Indices: " << result[0] << ", " << result[1] << endl;
    return 0;
}
