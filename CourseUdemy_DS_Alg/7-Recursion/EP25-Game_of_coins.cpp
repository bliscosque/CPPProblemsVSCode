#include <bits/stdc++.h>
using namespace std;


int MV;
int MaxValue(int n, vector<int> v, int i, int j, bool Oswald, int sumP) {
    if (i==j) { //ou >??
        MV=max(MV,sumP);
    }

}


int MaxValue(int n, vector<int> v){
    MV=INT_MIN;
    int j=n-1;
    return MaxValue(n,v,0,j, true,0);

}
int main() {
    int n=4;
    vector<int> v= {1,2,3,4};
    cout << MaxValue(n,v) << endl;
}