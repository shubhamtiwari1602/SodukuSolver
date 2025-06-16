// Sudoku Solver in C++ with user input
#include <iostream>
#include <vector>
using namespace std;

const int SIZE = 9; // Standard size for Sudoku board

// Function to print the Sudoku board
void printBoard(const vector<vector<int>>& board) {
    for (int i = 0; i < SIZE; ++i) {
        for (int j = 0; j < SIZE; ++j) {
            // Show blank cells as '.' for better readability
            if (board[i][j] == -1)
                cout << ". ";
            else
                cout << board[i][j] << " ";
        }
        cout << "\n";
    }
}

// Function to check whether placing a number is valid according to Sudoku rules
bool isValid(const vector<vector<int>>& board, int row, int col, int num) {
    // Check if the number is already in the current row or column
    for (int i = 0; i < SIZE; ++i) {
        if (board[row][i] == num || board[i][col] == num)
            return false;
    }

    // Find the top-left cell of the 3x3 subgrid the cell belongs to
    // For example, if row=4, row%3=1, so startRow = 4 - 1 = 3
    // This ensures we always begin checking from the top-left of the 3x3 box
    int startRow = row - row % 3;
    int startCol = col - col % 3;

    // Check all cells within the 3x3 subgrid for duplicates
    for (int i = 0; i < 3; ++i) {
        for (int j = 0; j < 3; ++j) {
            if (board[startRow + i][startCol + j] == num)
                return false;
        }
    }
    return true; // It's safe to place the number
}

// Recursive backtracking function to solve the Sudoku puzzle
bool solveSudoku(vector<vector<int>>& board) {
    for (int row = 0; row < SIZE; ++row) {
        for (int col = 0; col < SIZE; ++col) {
            if (board[row][col] == -1) { // Found a blank cell
                // Try placing digits from 1 to 9
                for (int num = 1; num <= 9; ++num) {
                    // Check if placing the number is valid
                    if (isValid(board, row, col, num)) {
                        board[row][col] = num; // Place the number

                        // Recursively try to solve the rest of the board
                        if (solveSudoku(board))
                            return true; // Found a valid configuration

                        board[row][col] = -1; // Backtrack if not valid
                    }
                }
                return false; // Trigger backtracking if no number fits
            }
        }
    }
    return true; // Board is completely filled and valid
}

int main() {
    // Initialize a Sudoku board with -1 representing blank cells
    vector<vector<int>> board = {
        {5, 3, -1, -1, 7, -1, -1, -1, -1},
        {6, -1, -1, 1, 9, 5, -1, -1, -1},
        {-1, 9, 8, -1, -1, -1, -1, 6, -1},
        {8, -1, -1, -1, 6, -1, -1, -1, 3},
        {4, -1, -1, 8, -1, 3, -1, -1, 1},
        {7, -1, -1, -1, 2, -1, -1, -1, 6},
        {-1, 6, -1, -1, -1, -1, 2, 8, -1},
        {-1, -1, -1, 4, 1, 9, -1, -1, 5},
        {-1, -1, -1, -1, 8, -1, -1, 7, 9}
    };

    // Solve and display the Sudoku board
    if (solveSudoku(board)) {
        cout << "\nSolved Sudoku:\n";
        printBoard(board);
    } else {
        cout << "\nNo solution exists for the given Sudoku.\n";
    }

    return 0;
}
