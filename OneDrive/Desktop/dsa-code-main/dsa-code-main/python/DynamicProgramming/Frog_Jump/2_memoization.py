def frog_jump(index, heights, dp):
    if index == 0:
        return 0
    if dp[index] != -1:
        return dp[index]

    one = frog_jump(index - 1, heights, dp) + abs(heights[index] - heights[index - 1])
    two = float('inf')
    if index > 1:
        two = frog_jump(index - 2, heights, dp) + abs(heights[index] - heights[index - 2])

    dp[index] = min(one, two)
    return dp[index]

if __name__ == "__main__":
    heights = [10, 30, 40, 20]
    n = len(heights)
    dp = [-1] * n
    print(frog_jump(n - 1, heights, dp))  # Output: 30