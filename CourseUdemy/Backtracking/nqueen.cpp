#include <bits/stdc++.h>
using namespace std;

bool canPlace(int board[20][20], int n, int x, int y) {
    //column
    for (int k=0;k<n;k++) {
        if (board[k][y] == 1) return false;
    }
    //left diag
    int i=x;
    int j=y;
    while (i>=0 && j>=0) {
        if (board[i][j] == 1) return false;
        i--;
        j--;
    }

    //right diag
    i=x;
    j=y;
    while (i>=0 && j<n) {
        if (board[i][j] == 1) return false;
        i--;
        j++;
    }

    return true;
}

void printBoard(int n, int board[20][20]) {
    for (auto i=0;i<n;i++) {
        for (auto j=0;j<n;j++) {
            cout << board[i][j] << " ";
        }
        cout << endl;
    }
    cout << endl;
}

bool solveNQueen(int n, int board[20][20],int i) {
    //base case
    if (i==n) { // end of board
        printBoard(n,board);
        return true;
    }


    //recursive case
    //try to place a queen in every row
    for (auto j=0;j<n;j++) {
        //is i,j a safe position?
        if (canPlace(board,n,i,j)) {
            board[i][j]=1;
            bool success = solveNQueen(n,board,i+1);
            if (success) return true;
            
            //backtrack
            board[i][j]=0;
        }
    }
    return false;
}

int main() {
    int board[20][20]={0};
    int n;
    cin >> n;

    solveNQueen(n,board,0);

    return 0;
}