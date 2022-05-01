#include<bits/stdc++.h>
using namespace std;

vector<int> sol;

bool findPathRec(int n, vector<vector<char>> c, int i, int j){
    //cout << "i: " << i << " j: " << j << endl;
    bool find1=false, find2=false;
    if (i==n-1 && j==n-1) {
        //cout << "final!!!" << endl;
        return true;
    }
    else {
        if (i+1 < n && c[i+1][j]=='O') {
            find1=findPathRec(n,c,i+1,j);
            if (find1) {
                //cout << "enc" << endl;
                sol.push_back(n*(i+1)+j+1);
            }
        }
        if (j+1 < n && c[i][j+1]=='O') {
            find2=findPathRec(n,c,i,j+1);
            if (find2) { 
                //cout << "enc" << endl;
                sol.push_back(n*i+j+2);
            }
        }
        return find1 || find2;
    }
}

vector<int> findPath(int n, vector<vector<char>> c){
    sol.erase(sol.begin(), sol.end());
    findPathRec(n,c,0,0);
    sol.push_back(1);
    reverse(sol.begin(),sol.end());
    return sol;
}

int main() {
    vector<vector<char>> vvc = {{'O','O','X','O'},{'O','X','O','O'},{'O','O','O','X'},{'X','X','O','O'}};

    vector<int> vi = findPath(vvc.size(),vvc);
    cout << endl;
    for (auto i:vi) {
        cout << i << " ";
    }


    return 0;
}