//given an array of positive integers
//each element -> max no of steps you can jump in array
//find minimum jumps to reach to final idx

#include <bits/stdc++.h>
using namespace std;

//top down DP
int min_jumps(vector<int> arr, int n, vector<int> dp, int i=0) {
    if (i==n-1) {
        return 0; //chegou no fim
    }
    if (i>=n) {
        return INT_MAX; //além da matriz... infinito
    }
    //rec case
    //using DP, if already calculated
    if (dp[i]!=0) {
        return dp[i];
    }
    //assume
    int steps=INT_MAX;
    int max_jump=arr[i];

    for (int jump=1;jump<=max_jump;jump++) {
        int next_idx=i+jump;
        int subprob=min_jumps(arr,n,dp,next_idx);
        if (subprob!=INT_MAX) {
            steps=min(steps,subprob+1);
        }
    }

    return dp[i]=steps;
}

int main() {
    vector<int> arr={3,4,2,1,2,3,7,1,1,1,2,5}; //4 (3->4->2->7->5)
    int n=arr.size();

    vector<int> dp(n,0);
    cout << min_jumps(arr,n,dp,0) << endl;
    return 0;   
}