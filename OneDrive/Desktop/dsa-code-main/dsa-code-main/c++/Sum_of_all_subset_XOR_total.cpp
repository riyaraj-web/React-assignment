// LeetCode - 1863

/*
You are given an array nums.
You need to find the sum of XOR values of all possible subsets of this array.
*/

//Here is the code : (Solved usin BitMasking)

class Solution{
    public:

    int subsetXORSum(vector<int>& nums){
        int n = nums.size();
        int sum = 0;

        for(int mask = 0; mask < (1 << n); mask++){
            int currXOR = 0;
            for(int i=0; i<n; i++){
                if(mask & (1 << i)){
                    currXOR ^= nums[i];
                }
            }
            sum += currXOR;
        }
        return sum;
    }
};