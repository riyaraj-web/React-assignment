function maxSubArray(nums: number[]): number {
    let maxSum = nums[0], currSum = nums[0];
    for (let i = 1; i < nums.length; i++) {
        currSum = Math.max(nums[i], currSum + nums[i]);
        maxSum = Math.max(maxSum, currSum);
    }
    return maxSum;
}

// Usage
console.log(maxSubArray([-2,1,-3,4,-1,2,1,-5,4])); // 6
