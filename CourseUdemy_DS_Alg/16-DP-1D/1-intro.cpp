//DP is a optimisation technique
//For problems with optimal substructure and overlapping subproblems

#include <bits/stdc++.h>
using namespace std;

//top down DP -> recursion+memoisation
int fib(int n, vector<int> &dp) {
    if (n==0 || n==1) return n;
    if (dp[n]!=0) {
        return dp[n];
    }
    return dp[n]=fib(n-1,dp)+fib(n-2,dp); //store and return
}

//botton up DP -> iterative
int fib2(int n) {
    vector<int> dp(n+1,0);
    dp[0]=0;dp[1]=1;
    for (int i=2;i<=n;i++) {
        dp[i]=dp[i-1]+dp[i-2];
    }
    return dp[n];
}

int main() {
    vector<int> dp(100,0);
    cout << fib(20,dp) << endl;
    cout << fib2(20) << endl;

    return 0;
}