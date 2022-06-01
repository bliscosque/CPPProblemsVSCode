//there are N stores given (array)
//each element -> high of stone
//frog in stone 1 to stone N
//can jump to stone+1 or stone+2
//cost is |hi - hj|
//what is minimun possible total cost

//{10,10}
//0

//{30,10,60,10,60,50}
//40

//{10,30,40,20}
//30
//10->30->20

//dp[i] -> minimun cost to reach ith stone. [0]-> 0, [1] = |dp[1]-dp[0]|
//outros... menos custo de dp[h-1] ou dp[h-2] até atual 

#include <bits/stdc++.h>
using namespace std;

//bottom-up approach
int getMinCost(vector<int> stones) {
    int n=stones.size();
    vector<int> dp(n,0);
    dp[1]=abs(stones[1]-stones[0]);
    for (int i=2;i<n;i++) {
        //previous stone
        int op1 = abs(stones[i]-stones[i-1]) + dp[i-1];
        //2 previous stones
        int op2 = abs(stones[i]-stones[i-2]) + dp[i-2];
        dp[i]=min(op1,op2);
    }
    return dp[n-1];
}

int main() {
    vector<int> stones={30,10,60,10,60,50};
    cout << getMinCost(stones) << endl;
    return 0;
}