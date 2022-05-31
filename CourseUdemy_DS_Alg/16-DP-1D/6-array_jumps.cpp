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
}

int main() {
    vector<int> arr={3,4,2,1,2,3,7,1,1,1,2,5}; //4 (3->4->2->7->5)
    int n=arr.size();

    vector<int> dp(n,0);
    cout << min_jumps(arr,n,dp,0) << endl;
    return 0;   
}