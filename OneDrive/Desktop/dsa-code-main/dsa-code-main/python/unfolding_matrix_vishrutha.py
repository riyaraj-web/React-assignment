def spiral(matrix):
    if not matrix:
        return []
    # Step 1: Take first row
    first_row = matrix[0]
    # Step 2: Rotate remaining matrix 90° counterclockwise
    rotated = list(zip(*matrix[1:]))[::-1]
    # Step 3: Recur
    return first_row + spiral([list(row) for row in rotated])