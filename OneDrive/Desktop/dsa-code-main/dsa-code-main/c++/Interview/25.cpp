#include <iostream>
#include <vector>
#include <numeric>

using namespace std;

class SolutionSummation {
public:
    int missingNumber(vector<int>& nums) {
        int n = nums.size();
        
        // Use long long for the sum calculation to prevent potential integer overflow
        // if 'n' is large (though generally unnecessary for typical constraints).
        long long expectedSum = (long long)n * (n + 1) / 2;
        
        long long actualSum = 0;
        for (int num : nums) {
            actualSum += num;
        }
        
        // The missing number is the difference.
        return (int)(expectedSum - actualSum);
    }
};  