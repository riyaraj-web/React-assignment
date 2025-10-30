def frog_jump(heights):
    prev = 0
    prev2 = 0

    for i in range(1, len(heights)):
        one = prev + abs(heights[i] - heights[i - 1])
        two = prev2 + abs(heights[i] - heights[i - 2]) if i > 1 else float('inf')
        curr = min(one, two)
        prev2 = prev
        prev = curr

    return prev

if __name__ == "__main__":
    heights = [10, 30, 40, 20]
    print(frog_jump(heights))  # Output: 30