
# N-Queens Problem Solver

This project solves the generalized N-Queens problem using a stack-based backtracking algorithm, specifically developed for CS300 Homework 1 at Sabancı University.

## Overview

The N-Queens problem requires placing N queens on an N x N chessboard so that no two queens threaten each other. This project uses a template-based stack implementation to manage the backtracking process efficiently without recursion.

## Project Structure

- **`main.cpp`**: Contains the main logic for solving the N-Queens problem, implementing the stack-based backtracking algorithm and handling file output for solutions.
- **`stack.h`**: Header file defining the template-based `Stack` class, which is used to store `State` structures during the backtracking process.
- **`stack.cpp`**: Implements the methods of the `Stack` class, including push, pop, top, and resize operations.

## How It Works

The solution leverages a custom `Stack` class to manage queen placements and backtracking efficiently:
1. **Input**: Prompts the user to enter the value of `N` (size of the chessboard).
2. **Backtracking Algorithm**:
   - Starts with an empty board.
   - Places queens row-by-row, checking for safe positions.
   - Uses the stack to backtrack when no safe positions are available in a row.
3. **Output**: Writes all solutions to a file named `Nqueens_solutions.txt` with:
   - Total number of solutions at the top.
   - Each solution in a one-dimensional array format, showing the column positions of queens for each row.

### Example Output
For `N=4`, the output file will contain:

```
Total solutions for N=4: 2

Solution 1: [1, 3, 0, 2]
Solution 2: [2, 0, 3, 1]
```

## Features

- **Stack-based Backtracking**: Uses a stack to handle backtracking efficiently.
- **Template-based Stack Implementation**: The stack can store different data types, specifically the `State` struct for this project.
- **Safe Matrix Optimization** (optional): Tracks safe positions on the board to improve efficiency for larger `N` values.
- **Input Validation**: Ensures `N > 0`; otherwise, displays an error message and exits.

## Requirements

- **C++ Compiler**: Ensure that you have a C++ compiler installed to compile and run the program.
- **Text Editor or IDE**: Use an editor of your choice (e.g., VS Code, CLion, etc.).

## Compilation & Execution

To compile and execute the program, use the following commands:

```bash
g++ main.cpp stack.cpp -o n_queens_solver
./n_queens_solver
```

## Submission Guidelines

- Submit exactly 3 files: `main.cpp`, `stack.h`, and `stack.cpp`.
- Ensure that the filenames match precisely; otherwise, the submission may not be graded.
- Upload directly to SUCourse without zipping.

## Notes

- The program should compile and run correctly; otherwise, it may receive a grade of 0.
- For grading, factors like code readability, proper indentation, and informative variable names are considered.
- Efficient implementation and adherence to output format are essential for full credit.

---

**Good luck with the N-Queens problem!**
