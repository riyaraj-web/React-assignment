# 3718. Smallest Missing Multiple of K
# weekly contest 472, problem 1

class Solution:
    def missingMultiple(self, nums: List[int], k: int) -> int:
        s = set(nums)
        current = k
        while current in s:
            current += k
        return current
