/*
 * Name: Benjamin McDonnough
 * Date Submitted:
 * Lab Section: 006
 * Assignment Name: nQueens
 */

#include <iostream>
#include <vector>

using namespace std;


//Uses recursion to count how many solutions there are for
//placing n queens on an nxn chess board
bool checkIfAvailable(vector<int> &board, int row, int col){
    for(int i = 0; i < row; ++i){
        if(board[i] == col || abs(board[i] - col) == abs(i-row))
            return false;
    }
    return true;
}
int checkNumQueens(int n, vector<int> &currentBoard, int row){
     if (row == n) {
        return 1;
    }

    int count = 0;

    for(int col = 0; col < n; ++col){
        if(checkIfAvailable(currentBoard, row, col)){
            currentBoard[row] = col;

            count += checkNumQueens(n, currentBoard, row + 1);
        }
    }

   

    return count;
}

int nQueens(int n)
{
    //Implement int nQueens(int n)
    //Feel free to implement any recursive helper functions

    vector<int> board(n*n, -1);

    if(n == 1){
        return 1;
    }
    else{
        return checkNumQueens(n, board, 0);
    }
}

/*int main()
{
    cout << "1: " << nQueens(1) << endl;
    cout << "2: " << nQueens(2) << endl;
    cout << "3: " << nQueens(3) << endl;
    cout << "4: " << nQueens(4) << endl;
    cout << "5: " << nQueens(5) << endl;
    cout << "6: " << nQueens(6) << endl;
    cout << "7: " << nQueens(7) << endl;
    cout << "8: " << nQueens(8) << endl;
    cout << "9: " << nQueens(9) << endl;
    cout << "10: " << nQueens(10) << endl;
    cout << "11: " << nQueens(11) << endl;
    cout << "12: " << nQueens(12) << endl;
    return 0;
}*/