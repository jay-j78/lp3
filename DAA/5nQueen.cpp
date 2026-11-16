
#include<iostream>
#include<vector>
using namespace std;

int n;

// Function to display the chessboard
void printBoard(vector<vector<char>>& board) {
    for(int i=0;i<n;i++) {
        for(int j=0;j<n;j++) {
            cout << board[i][j] << " ";
        }
        cout << endl;
    }
}

// Check whether placing a queen at the given position is safe
bool isSafe(vector<vector<char>>& board, int row, int col) {

    // Check the same column
    for(int i=row-1;i>=0;i--) {
        if(board[i][col]=='Q')
            return false;
    }

    // Check upper-left diagonal
    for(int i=row-1,j=col-1;i>=0 && j>=0;i--,j--) {
        if(board[i][j]=='Q')
            return false;
    }

    // Check upper-right diagonal
    for(int i=row-1,j=col+1;i>=0 && j<n;i--,j++) {
        if(board[i][j]=='Q')
            return false;
    }

    return true;
}

// Solve N-Queens using Backtracking
bool solve(vector<vector<char>>& board, int row) {

    // Base condition: all queens are placed
    if(row==n)
        return true;

    // Try placing a queen in each column of the current row
    for(int col=0;col<n;col++) {

        if(isSafe(board,row,col)) {

            // Place queen at the safe position
            board[row][col]='Q';

            // Recursively solve the next row
            if(solve(board,row+1))
                return true;

            // Backtrack: Remove queen if no solution is found
            board[row][col]='.';
        }
    }

    return false;
}

int main() {

    cout << "Enter N: ";
    cin >> n;

    // Create an empty N x N chessboard
    vector<vector<char>> board(n,vector<char>(n,'.'));

    int row,col;

    cout << "Enter first queen position (row and column): ";
    cin >> row >> col;

    // Convert 1-based indexing to 0-based indexing
    row--;
    col--;

    // Check whether the given queen position is valid
    if(row<0 || row>=n || col<0 || col>=n) {
        cout << "wrong position";
        return 0;
    }

    // Place the first queen at the given position
    board[row][col]='Q';

    // Start solving from the next row
    if(solve(board,row+1)) {
        cout << "final solution" << endl;
        printBoard(board);
    }
    else {
        cout << "no solution";
    }

    return 0;
}
 /*Enter N: 4
Enter first queen position (row and column): 1 2*/