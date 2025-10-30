def frog_jump(heights):
    n = len(heights)
    dp = [0] * n
    dp[0] = 0

    for i in range(1, n):
        one = dp[i - 1] + abs(heights[i] - heights[i - 1])
        two = dp[i - 2] + abs(heights[i] - heights[i - 2]) if i > 1 else float('inf')
        dp[i] = min(one, two)

    return dp[-1]

if __name__ == "__main__":
    heights = [10, 30, 40, 20]
    print(frog_jump(heights))  # Output: 30