#include <iostream>
#include <vector>

using namespace std;

// Function to check if placing a queen at board[row][col] is safe
bool isSafe(const vector<int> &queens, int row, int col) {
    for (int i = 0; i < row; ++i) {
        // Check if the queen in the same column or diagonal
        if (queens[i] == col || abs(queens[i] - col) == abs(i - row)) {
            return false;
        }
    }
    return true;
}

// Recursive function to solve N-Queens problem and count permutations
int solveNQueens(vector<int> &queens, int row, int n) {
    if (row == n) {
        // All queens are placed successfully
        return 1;
    }

    int count = 0;

    for (int col = 0; col < n; ++col) {
        if (isSafe(queens, row, col)) {
            // Place the queen
            queens[row] = col;

            // Recur for the next row
            count += solveNQueens(queens, row + 1, n);
        }
    }

    return count;
}

// Main function to solve the N-Queens problem and return the number of permutations
int nQueens(int n) {
    vector<int> queens(n, -1);  // Initialize queens vector with invalid values
    return solveNQueens(queens, 0, n);
}

int main() {
    int n;
    cout << "Enter the number of queens (N): ";
    cin >> n;

    int numPerms = nQueens(n);
    cout << "Number of permutations: " << numPerms << endl;

    return 0;
}
