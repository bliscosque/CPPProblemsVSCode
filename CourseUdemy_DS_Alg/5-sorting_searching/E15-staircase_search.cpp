#include<bits/stdc++.h>
using namespace std;


pair<int,int> search(int m, int n, vector<vector<int>> v, int k){
    int x=m-1;
    int y=0;

    while (y<n && x>=0) {
        cout << "x: " << x << " y: " << y << endl;
        if (v[x][y]==k) {
            break;
        }
        else if (v[x][y]<k) {
            y++;
        }
        else {
            x--;
        }
    }
    return {x,y};
}

int main() {
    vector<vector<int>> v = {{1,4,9},{2,5,10},{6,7,11}};

    pair<int,int> ans=search(3,3,v,10);
    
    cout << ans.first << " " << ans.second;

    return 0;
}