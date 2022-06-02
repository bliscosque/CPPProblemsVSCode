//count number of BST that can be formed using N nodes (numbered 1...N).

//3
//5

//4
//14

//1, 2, 3, ..., i, ..., n
//if put ith node as root, all nodes with less value will be in left and bigger, in the right
//i-1 nodes in left, n-i nodes in right
//f(n)=f(i-1)*f(n-1)
//f(0)=f(1)=1

#include <bits/stdc++.h>
using namespace std;


int countBST(int n) {
    if (n==0 || n==1) return 1;
    int ans=0;
    for (int i=1;i<=n;i++) {
        int x=countBST(i-1);
        int y=countBST(n-i);
        ans+=x*y;
    }
    return ans;
}

int countBST(int n, vector<int> &dp) {
    if (n==0 || n==1) return 1;
    if (dp[n!=0]) return dp[n];
    int ans=0;
    for (int i=1;i<=n;i++) {
        int x=countBST(i-1, dp);
        int y=countBST(n-i, dp);
        ans+=x*y;
    }
    return dp[n]=ans;
}

int countBSTBottomUp(int N) {
    vector<int> dp(N+1,0);
    dp[0]=dp[1]=1;
    for (int n=2;n<=N;n++) {
        for (int i=1;i<=n;i++) {
            dp[n]+=(dp[i-1]*dp[n-i]);
        }
    }
    return dp[N];
}

int main() {
    cout << countBST(4) << endl;
    vector<int> dp(4,0);
    cout << countBST(4,dp) << endl;
    cout << countBSTBottomUp(4) << endl;
    return 0;
}