#include <bits/stdc++.h>
using namespace std;

vector<vector<int>> ans;

bool isSafe(vector<vector<int>> mat, int i, int j, int no, int n) {
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

bool solveSudoku(vector<vector<int>> mat, int i, int j, int n) {
    //base case
    if (i==n) {
        //set the solution
        ans=mat;


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

vector<vector<int>> solve(vector<vector<int>> matrix) {
    solveSudoku(matrix, 0, 0, 9);
    return ans;
}

int main() {
    int n=9;
    vector<vector<int>> matrix = {
        {0,2,0,5,0,1,0,9,0},
        {8,0,0,2,0,3,0,0,6},
        {0,3,0,0,6,0,0,7,0},
        {0,0,1,0,0,0,6,0,0},
        {5,4,0,0,0,0,0,1,9},
        {0,0,2,0,0,0,7,0,0},
        {0,9,0,0,3,0,0,8,0},
        {2,0,0,8,0,4,0,0,7},
        {0,1,0,9,0,7,0,6,0}
    };
    vector<vector<int>> ansi=solve(matrix);
    for (auto i:ansi) {
        for (auto i2:i) {
            cout << i2 << " ";
        }
        cout << endl;
    }
    return 0;
}