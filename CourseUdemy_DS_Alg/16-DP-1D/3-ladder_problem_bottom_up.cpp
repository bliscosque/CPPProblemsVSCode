//given a ladder of size N, and an integer K, 
//write a function to compute number of ways to climb the ladder if you can take a jump of at most k at every step

//top-down approach
//para chegar ao degrau N(final), pode vir de N-1, N-2,...,N-K

//botton-up approach
//no degrau N, posso chegar a partir de N-1,N-2,...,N-K

//approach 3 - optimise the recurrence
//dp[n]=dp[n-1]+dp[n-2]+...+dp[n-k]
//para cada celula, retiramos uma celula e adicionamos a celula nova
//dp[n]=2*dp[n-1]-dp[n-k-1]

//N=4
//K=3

//7

#include <bits/stdc++.h>
using namespace std;

//recursive
int countWays(int n, int k) {
    if (n==0) {
        return 1;
    }
    if (n<0) {
        return 0;
    }
    //recursive case
    int ans=0;
    for (int jump=1;jump<=k;jump++) {
        ans+=countWays(n-jump,k);
    }
    return ans;
}

//top Down
int countWaysDP(int n, int k, vector<int> dp) {
    if (n==0) {
        return 1;
    }
    if (n<0) {
        return 0;
    }
    if (dp[n]!=0) { //check if state is already computed (DP)
        return dp[n];
    }
    //recursive case
    int ans=0;
    for (int jump=1;jump<=k;jump++) {
        ans+=countWaysDP(n-jump,k,dp);
    }
    return dp[n]=ans;//atualizando DP
}

//bottom up (O(n*k))
int countWaysBU(int n,int k) {
    //iterative approach
    vector<int> dp(n+1,0);
    dp[0]=1;
    for (int i=1;i<=n;i++) {
        for (int jump=1;jump<=k;jump++) {
            if (i-jump>=0) {
                dp[i] +=dp[i-jump];
            }
        }
    }
    return dp[n];
}

//bottom up - optimized O(n+k)
int countWaysOpt(int n, int k) {
    vector<int> dp(n+1,0);
    dp[0]=dp[1]=1;
    for (int i=2;i<=k;i++) {
        dp[i]=2*dp[i-1];
    }
    for (int i=k+1;i<=n;i++) {
        dp[i]=2*dp[i-1]-dp[i-k-1];
    }
    return dp[n];
}


int main() {
    int n=4,k=3;
    cout << countWays(n,k) << endl;
    cout << countWaysDP(n,k,vector<int>(1000,0)) << endl;
    cout << countWaysBU(n,k) << endl;
    cout << countWaysOpt(n,k) << endl;
    return 0;
}