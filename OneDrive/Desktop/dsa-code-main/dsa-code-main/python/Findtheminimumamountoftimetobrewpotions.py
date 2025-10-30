from typing import List

class Solution:
    def minTime(self, skill: List[int], mana: List[int]) -> int:
        n, m = len(skill), len(mana)
        dp = [0] * (n + 1)

        for i in range(m):
            for j in range(n):
                dp[j + 1] = max(dp[j + 1], dp[j]) + skill[j] * mana[i]
            for j in range(n - 1, 0, -1):
                dp[j] = dp[j + 1] - skill[j] * mana[i]

        return dp[n]


if __name__ == "__main__":
    s = Solution()

    skill = [1, 5, 2, 4]
    mana = [5, 1, 4, 2]
    print("Input:", skill, mana)
    print("Output:", s.minTime(skill, mana))
