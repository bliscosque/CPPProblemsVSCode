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


int matrixScore(vector<vector<int>> grid) {
    int max = calculate(grid);
    for (int i=0; i<grid.size();i++) {
        
    }
}

int main() {
    vector<vector<int>> grid = {{0,0,1,1}, {1,0,1,0}, {1,1,0,0}};
    cout << "RES: " << matrixScore(grid) << endl;
    return 0;
}