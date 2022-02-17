#include<bits/stdc++.h>
using namespace std;

int calculate(vector<vector<int>> grid) {
    int sum=0;
    for (vector<int> vi: grid) {
        int parc=0;
        for (int i:vi) {
            if (parc==0) parc = i;
            else {
                parc = (parc<<1)+i;
            }
            //cout << parc << endl;
        }
        //cout << "PARC1: " << parc << endl;
        sum+=parc;
    }
    return sum;
}

void print(vector<vector<int>> grid) {
    int nlin=grid.size();
    int ncol=grid[0].size();
    cout << "GRID: " << endl;
    //change lines that has first elem not 0
    for (int i=0;i<nlin;i++) {
        for (int j=0;j<ncol;j++) {
            cout << grid[i][j] << " ";
        }
        cout << endl;
    }
    cout << endl;
}

int matrixScore(vector<vector<int>> grid) {
    int nlin=grid.size();
    int ncol=grid[0].size();
    //change lines that has first elem not 0
    for (int i=0;i<nlin;i++) {
        if (grid[i][0]==0) {
            for (int j=0;j<ncol;j++) {
                grid[i][j]=grid[i][j]==0?1:0;
            }
        }
    }
    //print(grid);
    //change columns that have more 0s than 1s, except first column that have all elements=1
    for (int j=1;j<ncol;j++) {
        int sum=0;
        for (int i=0;i<nlin;i++) {
            sum+=grid[i][j];
        }
        if (sum <= nlin/2) {
            for (int i=0;i<nlin;i++) {
                grid[i][j]=grid[i][j]==0?1:0;
            }
        }
    }
    //print(grid);
    return calculate(grid);
}

int main() {
    vector<vector<int>> grid = {{0,0,1,1}, {1,0,1,0}, {1,1,0,0}};
    cout << "RES: " << matrixScore(grid) << endl;
    return 0;
}