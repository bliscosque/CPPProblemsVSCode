#include <iostream>
using namespace std;

void printBoard(int n, int board[][20]) {
    for (int i=0;i<n;i++) {
        for (int j=0;j<n;j++) {
            cout << board[i][j] << " ";
        }
        cout << endl;
    }    
}

bool canPlace(int board[][20], int n, int i, int j ) {
    for (int k=0;k<i;k++) {
        if (board[k][j]) {
            return false;
        }
    }

    //left diag
    int x=i;
    int y=j;
    while (x>=0 && y>=0) {
        if (board[x][y]) {
            return false;
        }
        x--;
        y--;
    }
    //right diag
    x=i;
    y=j;
    while (x>=0 && y<n) {
        if (board[x][y]) {
            return false;
        }
        x--;
        y++;
    }
    return true;
}

bool solveNQueen(int n,int board[][20], int i) {
    if(i==n) {
        //find a solution... print the board
        printBoard(n,board);
        return true;
    }
    for (int j=0;j<n;j++) {
        if (canPlace(board,n,i,j)) {
            board[i][j]=1;
            bool success=solveNQueen(n,board,i+1);
            if (success) {
                return true;
            }
            //backtrack
            board[i][j]=0;
        }
    }
    return false;
}

int main() {
    int board[20][20] = {0};
    int n;
    cin >> n;

    solveNQueen(n,board,0);

    return 0;
}