#include <bits/stdc++.h>
using namespace std;

bool isSafe(int mat[9][9], int i, int j, int no, int n) {
    //cout << i << j << no << endl;
    for (int k=0;k<9;k++) {
        if (mat[k][j]==no || mat[i][k]==no) {
            //cout << "F1" << endl;
            return false;
        }
    }

    //subgrid
    int sx=(i/3)*3;
    int sy=(j/3)*3;

    for (int x=sx;x<sx+3;x++) {
        for (int y=sy;y<sy+3;y++) {
            if (mat[x][y]==no) {
                //cout << "F2 " << mat[x][y] << " x: " << x << " y: " << y << endl;
                return false; 
            }
        }
    }
    return true;
}

bool solveSudoku(int mat[9][9], int i, int j, int n) {
    //base case
    if (i==n) {
        //print the solution
        for (int i=0;i<9;i++) {
            for (int j=0;j<9;j++) {
                cout << mat[i][j] << " ";
            }
            cout << endl;
        }

        return true;
    }

    //recursive case
    if (j==n) {
        return solveSudoku(mat, i+1, 0, n); //next line
    }
    //skip pre filled value (not 0)
    if (mat[i][j]!=0) {
        return solveSudoku(mat,i,j+1,n);
    }
    //try all values
    for (int no=1;no<=n;no++) {
        if (isSafe(mat,i,j,no,n)) {
            mat[i][j] = no;
            bool solveSubproblem=solveSudoku(mat,i,j+1,n);
            if (solveSubproblem) {
                return true;
            }

        }
    }

    //if no option works
    mat[i][j]=0;
    return false;
}

int main() {
    int n=9;
    int mat[9][9] = {
        {5,3,0,0,7,0,0,0,0},
        {6,0,0,1,9,5,0,0,0},
        {0,9,8,0,0,0,0,6,0},
        {8,0,0,0,6,0,0,0,3},
        {4,0,0,8,0,3,0,0,1},
        {7,0,0,0,2,0,0,0,6},
        {0,6,0,0,0,0,2,8,0},
        {0,0,0,4,1,9,0,0,5},
        {0,0,0,0,8,0,0,7,9}
    };
    if (!solveSudoku(mat,0,0,n)) {
        cout << "no solution" << endl;
    }
    return 0;
}