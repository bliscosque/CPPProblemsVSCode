#include<bits/stdc++.h>
using namespace std;

int solve(int n, vector<int> a){
    int soma=0;
    int wait=1;
    for (int i=0;i<n;i++) {
        if (a[i]!= wait) {
            wait = wait==0?1:0;
            soma+=1;
        }
    }
    return soma;
}

int main() {
    int n=4;
    vector<int> a = {0,1,0,1};
    cout << solve(n, a) << endl;
    return 0;
}