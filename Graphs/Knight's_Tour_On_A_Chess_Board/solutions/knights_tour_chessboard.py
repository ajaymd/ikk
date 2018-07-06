from collections import deque

DIRECTIONS = [(2, 1), (2, -1), (-2, 1), (-2, -1), (1, 2), (1, -2), (-1, 2), (-1, -2)]


def find_minimum_number_of_moves(rows, cols, start_row, start_col, end_row, end_col):
    def get_neighbors(r, c):
        neighbors = []
        for dr, dc in DIRECTIONS:
            new_r, new_c = r + dr, c + dc
            if 0 <= new_r < rows and 0 <= new_c < cols:
                neighbors.append((new_r, new_c))

        return neighbors

    start_cell = start_row, start_col

    # visited set to keep track of visited cells
    visited = {start_cell}

    # make a queue with cell and number of moves to get to that cell
    q = deque([(start_cell, 0)])

    while q:
        cell, count = q.popleft()
        if cell == (end_row, end_col):
            return count

        # using * operator to convert tuple into 2 arguments as get_neighbors function expects
        for new_cell in get_neighbors(*cell):
            if new_cell not in visited:
                q.append((new_cell, count + 1))
                visited.add(new_cell)

    return -1


print find_minimum_number_of_moves(5, 5, 0, 0, 4, 1)