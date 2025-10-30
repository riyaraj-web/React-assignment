def frog_jump(index, heights):
    if index == 0:
        return 0

    one_jump = frog_jump(index - 1, heights) + abs(heights[index] - heights[index - 1])

    two_jumps = float('inf')
    if index > 1:
        two_jumps = frog_jump(index - 2, heights) + abs(heights[index] - heights[index - 2])

    return min(one_jump, two_jumps)

if __name__ == "__main__":
    heights = [20, 30, 40, 20]
    print(frog_jump(len(heights) - 1, heights))  # Output: 20