grid = []

with open(r"C:\Code\AdventofCode24\Day 4\input.txt") as file:
    for line in file:
        # Convert each line (string) into a list of its characters
        grid.append(list(line.strip()))

# Safely retrieves a character from the grid at (row, col).
def get_cell(grid, row, col, num_rows, num_cols):
    """
    Safely retrieves a character from the grid at (row, col) if were within bounds of the grid

    Args:
        row (int): The row index
        col (int): The column index

    Returns:
        True (Char): The character if within grid boundaries
        False (None): outside grid bounds
    """

    # checks if the requested character is within grid boundaries
    if 0 <= row < num_rows and 0 <= col < num_cols:
        return grid[row][col]
    return None

def check_word_in_direction(grid, start_row, start_col, delta_row, delta_col, num_rows, num_cols):
    """
    Checks if a word exists starting at (start_row, start_col) and extending in the direction (delta_row, delta_col)

    Args:
        grid(list of lists): The crossword grid of characters.
        start_row (int): The starting row index.
        start_col (int): The starting column index.
        word (str): The target word to find.
        delta_row (int): Row increment for the direction (1 for down, -1 for up, 0 for horizontal).
        delta_col (int): Column increment for the direction(1 for right, -1 for left, 0 for vertical).
        
    Returns:
        bool: True if the word is found in that direction, False otherwise.
    """
    
    word = "XMAS" # just looking for this guy

    for index in range(len(word)):
        # Get location in the grid to check
        row = start_row + index * delta_row
        col = start_col + index * delta_col

        # Retreive character from grid if None then out of bounds, True if matches word.
        char = get_cell(grid, row, col, num_rows, num_cols)
        if char is None or char != word[index]:
            return False
    
    return True # if we reach here the for loop has completed and the entire word was found

# Get grid dimensions
num_rows = len(grid)
num_cols = len(grid[0])

matches_found = 0

# Define all 8 directions (dr, dc)
# (row_change, col_change)
directions = [
    (0, 1),   # Right
    (0, -1),  # Left
    (1, 0),   # Down
    (-1, 0),  # Up
    (1, 1),   # Down-Right (Diagonal)
    (1, -1),  # Down-Left (Diagonal)
    (-1, 1),  # Up-Right (Diagonal)
    (-1, -1)  # Up-Left (Diagonal)
]

for row in range(num_rows):
    for col in range(num_cols):
        for delta_row, delta_col in directions:
            if check_word_in_direction(grid, row, col, delta_row, delta_col, num_rows, num_cols):
                matches_found += 1
                print(f"match found! | total found: {matches_found}")