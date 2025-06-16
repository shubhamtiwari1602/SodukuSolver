


# 🧩 Sudoku Solver in C++

This is a simple yet powerful C++ implementation of a Sudoku Solver using **backtracking**. It solves a standard 9×9 Sudoku puzzle with some pre-filled numbers and blank cells.

---

## 📌 What This Project Does

- Accepts a Sudoku board with `-1` as blank cells.
- Uses **recursive backtracking** to try all possible values.
- Checks each placement for validity according to Sudoku rules.
- Prints the solved Sudoku grid or tells if no solution exists.

---

## 🧠 How It Works 

1. **What is Sudoku?**  
   A 9×9 grid divided into 3×3 subgrids. Fill it such that:
   - Every row has numbers from 1 to 9 with no repetition.
   - Every column has numbers from 1 to 9 with no repetition.
   - Every 3×3 subgrid has numbers from 1 to 9 with no repetition.

2. **How Do We Solve It?**  
   We look at every empty cell (i.e., `-1`) and try placing numbers 1 to 9. For each number:
   - If it doesn't break any rules (row, column, or box), we place it and move to the next cell.
   - If it leads to a dead end, we **undo** the move and try the next number.
   - This is called **backtracking** – trying possibilities and going back when stuck.

3. **How We Find 3×3 Grid?**  
   Each cell belongs to a 3×3 block. For cell `(row, col)`:
   ```cpp
   int startRow = row - row % 3;
   int startCol = col - col % 3;


This gives the **top-left corner** of the subgrid the cell is in.

---

## 🔍 Code Overview

### `isValid(board, row, col, num)`

Checks if placing `num` in `(row, col)` follows Sudoku rules:

* No duplicate in same row.
* No duplicate in same column.
* No duplicate in the 3×3 subgrid.

### `solveSudoku(board)`

Recursive backtracking function:

* Finds the next empty cell.
* Tries numbers 1 to 9.
* If placing a number works, recursively solve next cells.
* If not, reset the cell to `-1` (backtrack).

### `printBoard(board)`

Prints the board, showing `-1` as `.` for readability.

---



## 📚 Topics Covered

* Recursion
* Backtracking
* 2D Vectors
* Condition Checking


---


