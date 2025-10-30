from collections import deque

def water_jug_problem_trace_path(jug1_capacity, jug2_capacity, target):
    # Queue to keep track of states and the path to reach them
    queue = deque([((0, 0), [(0, 0)])])
    # Set to keep track of visited states
    visited = set()
    visited.add((0, 0))
    while queue:
        (jug1, jug2), path = queue.popleft()
        # Check if we have reached the target amount of water in either jug
        if jug1 == target or jug2 == target:
            return path
        # List of possible actions
        actions = [
            (jug1_capacity, jug2),                    # Fill jug1
            (jug1, jug2_capacity),                    # Fill jug2
            (0, jug2),                               # Empty jug1
            (jug1, 0),                               # Empty jug2
            # Pour jug2 into jug1
            (min(jug1_capacity, jug1 + jug2), jug2 - (min(jug1_capacity, jug1 + jug2) - jug1)),
            # Pour jug1 into jug2
            (jug1 - (min(jug2_capacity, jug1 + jug2) - jug2), min(jug2_capacity, jug1 + jug2))
        ]
        for action in actions:
            if action not in visited:
                visited.add(action)
                queue.append((action, path + [action]))
    return None

# Example usage
jug1_capacity = 4
jug2_capacity = 3
target = 2
path = water_jug_problem_trace_path(jug1_capacity, jug2_capacity, target)
if path:
    print("Path of states followed:", path)
else:
    print("No solution found.")
