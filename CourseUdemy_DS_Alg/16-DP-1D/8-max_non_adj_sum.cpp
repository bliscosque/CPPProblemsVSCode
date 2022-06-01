//given array of positives int
//find max sum of non adjacent elements

//{6,10,12,7,9,14}
//32 (12+6+14)

//ans[i] = elem+max until 2 elements before (no adj) OU max until 1 elem before 

#include <bits/stdc++.h>
using namespace std;

int maxNASum(vector<int> arr) {
    int n=arr.size();
    vector<int> dp(n);

    if (n==1) {
        return max(arr[0],0);
    }
    else if (n==2) {
        return max (0,max(arr[0],arr[1]));
    }

    dp[0]=max(arr[0],0);
    dp[1]=max(0,max(arr[0],arr[1]));
    for (int i=2;i<n;i++) {
        int op1=arr[i]+dp[i-2];
        int op2=dp[i-1];
        dp[i]=max(op1,op2);
    }
    return dp[n-1];
}



int main() {
    vector<int> arr={6,10,12,7,9,14};
    cout << maxNASum(arr) << endl;
    
    return 0;
}