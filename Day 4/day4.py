grid = []

with open(r"C:\Code\AdventofCode24\Day 4\input.txt") as file:
    for line in file:
        # Convert each line (string) into a list of its characters
        grid.append(list(line.strip()))
print(grid)

def get_cell(grid, r, c):
    # Safely retrieves a character from the grid at (r, c).
    num_rows = len(grid)
    num_cols = len(grid[0])

