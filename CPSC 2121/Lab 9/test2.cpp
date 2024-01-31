#include <iostream>
#include <vector>

using namespace std;

void changeBoard(int n, vector<int> &board, int row, int col, int value) {
    // Set or unset the entire row to 0
    for (int i = 0; i < n; ++i) {
        board[row * n + i] = value;
    }

    // Set or unset the entire column to 0
    for (int i = 0; i < n; ++i) {
        board[i * n + col] = value;
    }

    // Set or unset the diagonals to 0
    for (int i = 1; i < n; ++i) {
        if (row + i < n && col + i < n) {
            board[(row + i) * n + (col + i)] = value; // Down-right diagonal
        }
        if (row + i < n && col - i >= 0) {
            board[(row + i) * n + (col - i)] = value; // Down-left diagonal
        }
    }
}

int checkNumQueens(int n, vector<int> &currentBoard, int currentRow) {
    if (currentRow == n) {
        // Successfully placed queens in all rows
        return 1;
    }

    int count = 0;

    for (int i = 0; i < n; ++i) {
        if (currentBoard[currentRow * n + i] != 0) {
            // Place queen
            changeBoard(n, currentBoard, currentRow, i, 0);
            count += checkNumQueens(n, currentBoard, currentRow + 1);
            // Backtrack: undo changes
            changeBoard(n, currentBoard, currentRow, i, 1);
        }
    }

    return count;
}

int nQueens(int n) {
    if (n <= 0) {
        return 0; // No solutions for n <= 0
    }

    vector<int> board(n * n, 1); // Initialize the board with all 1s

    return checkNumQueens(n, board, 0);
}

int main() {
    cout << "4: " << nQueens(4) << endl;

    return 0;
}
