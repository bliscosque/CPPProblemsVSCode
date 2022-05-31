//find min coins required to make the change
//coin={1,3,7,10}
//M=15
//output=3 

#include <bits/stdc++.h>
using namespace std;

//bottom up approach
int minCoinsChange(int m, vector<int> coins) {
    vector<int> dp(m+1,0);
    dp[0]=0;
    for (int i=1;i<=m;i++) {
        dp[i]=INT_MAX;
        for (int c:coins) {
            if (i-c >=0 && dp[i-c]!=INT_MAX) { //se o valor anterior for infinito, nao há como somar
                dp[i]=min(dp[i], dp[i-c]+1);
            }
        }
    }
    return dp[m]==INT_MAX?-1:dp[m];
}

int main() {
    vector<int> coins={1,3,7,10};
    int n=15;
    cout << minCoinsChange(n,coins) << endl;
    return 0;
}