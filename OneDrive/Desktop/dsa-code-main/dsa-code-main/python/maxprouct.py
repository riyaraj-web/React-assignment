class Solution(object):
    def maxProduct(self, nums):
        """
        :type nums: List[int]
        :rtype: int
        """
        if not nums:
            return 0

        max_prod = min_prod = result = nums[0]

        for i in range(1, len(nums)):
            num = nums[i]

            # Calculate the maximum and minimum product up to the current position
            temp_max = max(num, max_prod * num, min_prod * num)
            min_prod = min(num, max_prod * num, min_prod * num)
            
            max_prod = temp_max

            # Update the result with the maximum product found so far
            result = max(result, max_prod)

        return result
