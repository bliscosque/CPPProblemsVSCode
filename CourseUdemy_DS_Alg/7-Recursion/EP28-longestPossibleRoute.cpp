#include<bits/stdc++.h>
using namespace std;

int mSum;

bool canPlace(int m, int n, vector<vector<int>> &v, int x, int y) {
    return (x>=0 && y >=0 && x<m && y<n && v[x][y]==1);
}

void findLongestPathRec(int m, int n, vector<vector<int>> &v, int x, int y, int sum){
    if (x==m-1 && y==n-1) {
        mSum=max(mSum,sum);
        return;
    }
    if (canPlace(m,n,v,x+1,y)) {
        v[x+1][y]=2;
        findLongestPathRec(m,n,v,x+1,y,sum+1);
        v[x+1][y]=1;
    }   
    if (canPlace(m,n,v,x-1,y)) {
        v[x-1][y]=2;
        findLongestPathRec(m,n,v,x-1,y,sum+1);
        v[x-1][y]=1;
    }   
    if (canPlace(m,n,v,x,y+1)) {
        v[x][y+1]=2;
        findLongestPathRec(m,n,v,x,y+1,sum+1);
        v[x][y+1]=1;
    }   
    if (canPlace(m,n,v,x,y-1)) {
        v[x][y-1]=2;
        findLongestPathRec(m,n,v,x,y-1,sum+1);
        v[x][y-1]=1;
    }   
}

int findLongestPath(int m, int n, vector<vector<int>> v){
    mSum=INT_MIN;
    v[0][0]=2; //2=visited
    findLongestPathRec(m,n,v,0,0,0);
    return mSum;
}

int main() {
    vector<vector<int>> v = {{1,1,1},{1,1,1},{0,0,1}};
    int m=v.size();
    int n=v[0].size();
    cout << findLongestPath(m,n,v) << endl;
    return 0;
}