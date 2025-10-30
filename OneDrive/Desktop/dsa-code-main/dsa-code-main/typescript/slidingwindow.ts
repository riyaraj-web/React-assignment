function maxSlidingWindow(nums: number[], k: number): number[] {
    const deque: number[] = [];
    const res: number[] = [];

    for(let i=0;i<nums.length;i++){
        while(deque.length && deque[0] <= i-k) deque.shift();
        while(deque.length && nums[deque[deque.length-1]] < nums[i]) deque.pop();
        deque.push(i);
        if(i>=k-1) res.push(nums[deque[0]]);
    }
    return res;
}

// Usage
console.log(maxSlidingWindow([1,3,-1,-3,5,3,6,7],3)); // [3,3,5,5,6,7]
