from typing import List

class Solution:
    def successfulPairs(self, spells: List[int], potions: List[int], success: int) -> List[int]:
        potions.sort()
        pairs = []
        for i in range(len(spells)):
            l = 0
            r = len(potions) - 1
            index = len(potions)

            while l <= r:
                mid = l + (r - l)//2
                if spells[i] * potions[mid] >= success:
                    index = mid
                    r = mid - 1
                elif spells[i] * potions[mid] < success:
                    l = mid + 1
            pairs.append(len(potions) - index)
        return pairs


if __name__ == "__main__":
    s = Solution()

    spells1 = [5, 1, 3]
    potions1 = [1, 2, 3, 4, 5]
    success1 = 7
    print("Example 1")
    print("spells =", spells1)
    print("potions =", potions1)
    print("success =", success1)
    print("output =", s.successfulPairs(spells1, potions1, success1))  # expected [4,0,3]
    print()

