#include <bits/stdc++.h>
using namespace std;

int cnt=0;

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

void solveNQueen(int n, int board[20][20],int i) {
    //base case
    if (i==n) { // end of board
        printBoard(n,board);
        cnt++;
        return ;
    }


    //recursive case
    //try to place a queen in every row
    bool isThereSol=false;
    for (auto j=0;j<n;j++) {
        //is i,j a safe position?
        if (canPlace(board,n,i,j)) {
            board[i][j]=1;
            solveNQueen(n,board,i+1);
            //backtrack
            board[i][j]=0;
        }
    }
    return;
}


int nQueen(int n){
    cnt=0;
    int board[20][20]={0};
    solveNQueen(n,board,0);
    return cnt;
}

int main() {
    int n;
    cin >> n;

    cout << nQueen(n) << endl;

    return 0;
}