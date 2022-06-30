//collection on N wines on sheld
//price cost pi[i]
//year y: price = y*pi
//can sell 1 wine per year
//can sell leftmost or rightmost

//input={2,3,5,1,4}
//output= 50
//2*1 + 4*2 + 1*3 + 3*4 + 5*5

#include <bits/stdc++.h>
using namespace std;

//top-down code
int wines (vector<vector<int>> dp, vector<int> prices, int L, int R, int y) {

    if (L>R) return 0; //lucro é 0

    if (dp[L][R]!=0) return dp[L][R]; //already computed

    int pick_left=y*prices[L] + wines(dp,prices,L+1,R,y+1);
    int pick_right=y*prices[R] + wines(dp,prices,L,R-1,y+1);
    return dp[L][R] = max(pick_right,pick_left);

}

int main() {
    vector<int> input={2,3,5,1,4};
    int n=input.size();
    vector<vector<int>> dp(10,vector<int>(10,0));

    cout << wines(dp,input,0,n-1,1) << endl;


    return 0;
}