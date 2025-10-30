import collections

def solve_activity_day():
    """
    Solves the Activity Day problem by identifying boxes from partition lines,
    ranking them based on area and coordinates, and then calculating the value
    of the string in the box corresponding to a given rank.
    """
    
    # --- 1. READ INPUT ---
    try:
        n, m = map(int, input().split())
        l = int(input())
        all_lines = [list(map(int, input().split())) for _ in range(l)]
        raghu_rank = int(input())
        strings = input().split()
    except (IOError, ValueError):
                      return

    # --- 2. IDENTIFY BOXES ---
    horizontal_lines = []
    vertical_lines = []
    x_coords_set = {0, n}
    y_coords_set = {0, m}

    for x1, y1, x2, y2 in all_lines:
        if x1 == x2:  # Vertical line
            vertical_lines.append((x1, min(y1, y2), x2, max(y1, y2)))
            x_coords_set.add(x1)
        else:  # Horizontal line
            horizontal_lines.append((min(x1, x2), y1, max(x1, x2), y2))
            y_coords_set.add(y1)
            
    x_coords = sorted(list(x_coords_set))
    y_coords = sorted(list(y_coords_set))
    
    num_x_cells = len(x_coords) - 1
    num_y_cells = len(y_coords) - 1
    
    
    vertical_walls_by_x = collections.defaultdict(list)
    for x, y_start, _, y_end in vertical_lines:
        vertical_walls_by_x[x].append((y_start, y_end))

    horizontal_walls_by_y = collections.defaultdict(list)
    for x_start, y, x_end, _ in horizontal_lines:
        horizontal_walls_by_y[y].append((x_start, x_end))

    def has_vertical_wall(i, j):
        """Check for a vertical partition to the right of cell (i, j)."""
        wall_x = x_coords[i + 1]
        if wall_x not in vertical_walls_by_x:
            return False
        cell_y_start, cell_y_end = y_coords[j], y_coords[j + 1]
        for line_y_start, line_y_end in vertical_walls_by_x[wall_x]:
           
            if max(line_y_start, cell_y_start) < min(line_y_end, cell_y_end):
                return True
        return False

    def has_horizontal_wall(i, j):
        """Check for a horizontal partition above cell (i, j)."""
        wall_y = y_coords[j + 1]
        if wall_y not in horizontal_walls_by_y:
            return False
        cell_x_start, cell_x_end = x_coords[i], x_coords[i + 1]
        for line_x_start, line_x_end in horizontal_walls_by_y[wall_y]:
            if max(line_x_start, cell_x_start) < min(line_x_end, cell_x_end):
                return True
        return False

    # 2c. Use BFS to find all connected components (boxes)
    found_boxes = []
    visited = [[False for _ in range(num_x_cells)] for _ in range(num_y_cells)]
    
    for j_start in range(num_y_cells):
        for i_start in range(num_x_cells):
            if not visited[j_start][i_start]:
                q = collections.deque([(i_start, j_start)])
                visited[j_start][i_start] = True
                
                min_i, max_i = i_start, i_start
                min_j, max_j = j_start, j_start

                while q:
                    ci, cj = q.popleft()
                    
                    min_i, max_i = min(min_i, ci), max(max_i, ci)
                    min_j, max_j = min(min_j, cj), max(max_j, cj)

                    
                    if ci + 1 < num_x_cells and not visited[cj][ci + 1] and not has_vertical_wall(ci, cj):
                        visited[cj][ci + 1] = True; q.append((ci + 1, cj))
                    if ci - 1 >= 0 and not visited[cj][ci - 1] and not has_vertical_wall(ci - 1, cj):
                        visited[cj][ci - 1] = True; q.append((ci - 1, cj))
                    if cj + 1 < num_y_cells and not visited[cj + 1][ci] and not has_horizontal_wall(ci, cj):
                        visited[cj + 1][ci] = True; q.append((ci, cj + 1))
                    if cj - 1 >= 0 and not visited[cj - 1][ci] and not has_horizontal_wall(ci, cj - 1):
                        visited[cj - 1][ci] = True; q.append((ci, cj - 1))
                
                # After BFS, define the found box by its corner coordinates
                bottom_left_x = x_coords[min_i]
                bottom_left_y = y_coords[min_j]
                top_right_x = x_coords[max_i + 1]
                top_right_y = y_coords[max_j + 1]
                
                found_boxes.append({
                    "x": bottom_left_x,
                    "y": bottom_left_y,
                    "w": top_right_x - bottom_left_x,
                    "h": top_right_y - bottom_left_y
                })
    
    # --- 3. ASSIGN STRINGS & CALCULATE AREA ---
    # Sort boxes by y, then x, to match the specified string assignment order
    sorted_for_strings = sorted(found_boxes, key=lambda b: (b['y'], b['x']))

    all_box_data = []
    for i, box in enumerate(sorted_for_strings):
        box['string'] = strings[i]
        box['area'] = box['w'] * box['h']
        all_box_data.append(box)

    # --- 4. RANK BOXES ---
    # Sort using the specified ranking criteria: Area (desc), x (asc), y (asc)
    ranked_boxes = sorted(all_box_data, key=lambda b: (-b['area'], b['x'], b['y']))

    # --- 5. OUTPUT THE RESULT ---
        
    if 1 <= raghu_rank <= len(ranked_boxes):
        raghus_string = ranked_boxes[raghu_rank - 1]['string']
        value = sum(ord(c) for c in raghus_string)
        print(value)

# Call the main function to run the solution
solve_activity_day()
