# **Crossword Pattern Finder**

This Python script is designed to find a specific word pattern ("XMAS") within a large grid of characters, considering all horizontal, vertical, and diagonal orientations. It's a foundational tool for solving word search puzzles or analyzing character matrices. Advent of Code 2024 Day 4 Challenge

## **Features**

* Reads a character grid from a text file.  
* Converts each row string into a list of individual characters for easy processing.  
* Safely accesses grid cells, handling out-of-bounds attempts.  
* Searches for the hardcoded pattern "XMAS" in 8 directions:  
  * Horizontal (Left-to-Right, Right-to-Left)  
  * Vertical (Top-to-Bottom, Bottom-to-Top)  
  * Diagonal (all four orientations)  
* Counts and reports the total number of times the pattern is found.

## **How to Use**

### **Prerequisites**

* Python 3.x installed on your system.

### **Setup**

1. **Save the Python Script:** Save the provided Python code (your solver.py or similar) to a .py file.  
2. **Create the Input File:** Create a text file named input.txt in the specified directory (C:\\Code\\AdventofCode24\\Day 4\\ or update the script with the correct path). This file should contain your grid of characters, with each line representing a row in the grid.  
   *Example input.txt (partial):*  
   MSSMSAMXSAMASMSMSAMMMMMMMXSXSMMSAMXSSSMXMSMMSMXMXSXMMSAMXMSSSSSSMSASMSSMSAMXMSMXSXSMMMXSSMAMXXMXSXMAMSAMXXMXAXXSASAMXMMAMMSSXSXMMXSMMXSXXMXX  
   AAMAMXAMMAMSAAAAMAMAAAAMMAMMSAAXAAMAAAMAXAMAAAAAASAMXSXMASMAXMAAMMASMAAAMAMAMAAMSAXAAXMXAXMASXSAMASAMXSSMMSSSMASAAAXMASMMAAMMMAMSMSASMSXAMAM  
   ...

### **Running the Script**

1. **Open a Terminal/Command Prompt:** Navigate to the directory where you saved your Python script.  
2. **Execute the Script:** Run the script using the Python interpreter:  
   python your\_script\_name.py

   (Replace your\_script\_name.py with the actual name of your Python file.)

The script will print the grid as a list of lists initially, and then for each instance of "XMAS" found, it will print "match found\! | total found: X", indicating the running count of matches.

## **Code Breakdown**

The script is structured with a main execution block and two helper functions:

### **1\. Input Reading**

grid \= \[\]  
with open(r"C:\\Code\\AdventofCode24\\Day 4\\input.txt") as file:  
    for line in file:  
        grid.append(list(line.strip()))

This section reads each line from the input.txt file. For each line, strip() removes leading/trailing whitespace (like newlines), and list() converts the resulting string into a list of its individual characters. These character lists are then appended to the grid, creating a list of lists representing the crossword.

### **2\. get\_cell(grid, row, col, num\_rows, num\_cols)**

def get\_cell(grid, row, col, num\_rows, num\_cols):  
    """  
    Safely retrieves a character from the grid at (row, col) if within bounds.

    Args:  
        grid (list of lists): The crossword grid.  
        row (int): The row index to check.  
        col (int): The column index to check.  
        num\_rows (int): Total number of rows in the grid.  
        num\_cols (int): Total number of columns in the grid.

    Returns:  
        str: The character at (row, col) if valid.  
        None: If the coordinates are outside grid boundaries.  
    """  
    if 0 \<= row \< num\_rows and 0 \<= col \< num\_cols:  
        return grid\[row\]\[col\]  
    return None

This helper function provides a safe way to access characters in the grid. It takes the grid, the desired row and col indices, and the grid's dimensions (num\_rows, num\_cols). It checks if the requested coordinates are within the valid zero-based indexing range (0 up to length \- 1). If they are, it returns the character; otherwise, it returns None to signal that the coordinates are out of bounds.

### **3\. check\_word\_in\_direction(grid, start\_row, start\_col, delta\_row, delta\_col)**

def check\_word\_in\_direction(grid, start\_row, start\_col, delta\_row, delta\_col):  
    """  
    Checks if the word "XMAS" exists starting at (start\_row, start\_col)  
    and extending in the direction specified by (delta\_row, delta\_col).

    Args:  
        grid (list of lists): The crossword grid of characters.  
        start\_row (int): The starting row index.  
        start\_col (int): The starting column index.  
        delta\_row (int): Row increment for the direction (e.g., 1 for down, \-1 for up, 0 for horizontal).  
        delta\_col (int): Column increment for the direction (e.g., 1 for right, \-1 for left, 0 for vertical).

    Returns:  
        bool: True if "XMAS" is found in that direction, False otherwise.  
    """  
    word \= "XMAS" \# The word currently being searched for  
    \# ... (rest of the implementation as explained previously)  
    return True \# if match, False otherwise

This function attempts to match the target word ("XMAS") character by character from a given start\_row, start\_col and moving in a specific (delta\_row, delta\_col) direction. It iterates through the length of the word, calculating the next cell's coordinates and using get\_cell to retrieve the character. If at any point it goes out of bounds or finds a mismatch, it immediately returns False. If all characters match, it returns True.

### **4\. Main Search Logic**

\# Get grid dimensions (moved outside get\_cell for efficiency)  
num\_rows \= len(grid)  
num\_cols \= len(grid\[0\])

matches\_found \= 0

\# Define all 8 directions  
directions \= \[  
    (0, 1), (0, \-1), (1, 0), (-1, 0),  
    (1, 1), (1, \-1), (-1, 1), (-1, \-1)  
\]

for row in range(num\_rows):  
    for col in range(num\_cols):  
        for delta\_row, delta\_col in directions:  
            if check\_word\_in\_direction(grid, row, col, delta\_row, delta\_col):  
                matches\_found \+= 1  
                print(f"match found\! | total found: {matches\_found}")

This is the main execution block.

* It first calculates num\_rows and num\_cols once for the entire grid.  
* It initializes a counter matches\_found.  
* It defines a list of all 8 possible directions to search.  
* It then uses nested loops to iterate through every single cell (row, col) in the grid.  
* For each cell, it iterates through every defined direction.  
* For each (cell, direction) combination, it calls check\_word\_in\_direction.  
* If check\_word\_in\_direction returns True, it increments matches\_found and prints a success message.

## **Future Improvements**

* **Make Words Configurable:** Currently, the word "XMAS" is hardcoded inside check\_word\_in\_direction. Modify it to accept a word parameter, allowing the script to search for "SAMX" or any other word from words\_to\_find list.  
* **Return Detailed Results:** Instead of just printing a count, store and print the actual start\_row, start\_col, and direction for each found word (as was discussed in find\_words\_in\_grid explanation).  
* **Case Insensitivity:** Add an option to perform case-insensitive searches.  
* **Performance Optimization:** For extremely large grids, consider more advanced algorithms (though for typical crosswords, the current approach is sufficient).  
* **More Robust Error Handling:** Add checks for malformed input files (e.g., non-rectangular grids).