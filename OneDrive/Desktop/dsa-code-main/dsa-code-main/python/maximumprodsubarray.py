from typing import List

class Solution:
    def maxProduct(self, nums: List[int]) -> int:
        """
        Finds the contiguous subarray within an array that has the largest product.
        """
        if not nums:
            return 0
        max_so_far = nums[0]
        min_so_far = nums[0]
        result = nums[0]

        for i in range(1, len(nums)):
            current = nums[i]
            
            temp_max = max_so_far
            
            max_so_far = max(current, max_so_far * current, min_so_far * current)
            
            min_so_far = min(current, temp_max * current, min_so_far * current)
            
            result = max(result, max_so_far)
            
        return result