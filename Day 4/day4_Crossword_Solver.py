grid = []

with open(r"C:\Code\AdventofCode24\Day 4\input.txt") as file:
    for line in file:
        # Convert each line (string) into a list of its characters
        grid.append(list(line.strip()))

#print(grid) # debug print to verify correct grid structure

# Safely retrieves a character from the grid at (row, col).
def get_cell(grid, row, col):
    """
    Safely retrieves a character from the grid at (row, col) if were within bounds of the grid

    Args:
        row (int): The row index
        col (int): The column index

    Returns:
        True (Char): The character if within grid boundaries
        False (None): outside grid bounds
    """

    # get grid size / len lookups are fast so we can do them without significant slow down. If I remember ill investigate exactly how much slower it makes it.
    # the performance gain from avoiding it in this context is usually negligible compared to the benefits of having a flexible and easy-to-understand get_cell function.
    num_rows = len(grid)
    num_cols = len(grid[0])

    # checks if the requested character is within grid boundaries
    if 0 <= row < num_rows and 0 <= col < num_cols:
        return grid[row][col]
    return None

def check_word_in_direction(grid, start_row, start_col, word, delta_row, delta_col):
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
    
    for index in range(len(word)):
        # Get location in the grid to check
        row = start_row + index * delta_row
        col = start_col + index * delta_col

        # Retreive character from grid if None then out of bounds, True if matches word.
        char = get_cell(grid, row, col)
        if char is None or char != word[i]:
            return False
    
    return True # if we reach here the for loop has completed and the entire word was found