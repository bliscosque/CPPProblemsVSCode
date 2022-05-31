//dado uma vara (rod), cada parte tem um preco

//len: 1 2 3 4 5  6  7  8 
//prc: 1 5 8 9 10 17 17 20 
//exemplo, se quiser 8 pode selecionar 8 pecas do tamanho 1 (preco 1) = $8
//max profit: 22 

//len: 1 2 3 4 5  6  7  8
//prc: 3 5 8 9 10 17 17 20
//Max profit: 24

#include <bits/stdc++.h>
using namespace std;

int maxProfit(vector<int> prices, int n) {
    //base case
    if (n<=0) {
        return 0;
    }
    //rec case
    int ans=INT_MIN;
    for (int i=0;i<n;i++) {
        int cut=i+1; //matriz comeca no 0
        int current_ans=prices[i]+maxProfit(prices,n-cut);
        ans=max(ans,current_ans);
    }
    return ans;
}
//bottom up + memoization
int maxProfitDP(vector<int> prices, int n) {
    vector<int> dp(n+1);
    dp[0]=0;

    for (int i=1;i<=n;i++) {
        int ans=INT_MIN;
        for (int j=0;j<i;j++) {
            int cut=j+1;
            int current_ans=prices[j]+dp[i-cut];
            ans=max(current_ans,ans);
        }
        dp[i]=ans;
    }
    return dp[n];
}


int main() {
    vector<int> prices={1,5,8,9,10,17,17,20};
    int n=prices.size();
    cout << maxProfit(prices,n) << endl;
    cout << maxProfitDP(prices,n) << endl;

    return 0;
}