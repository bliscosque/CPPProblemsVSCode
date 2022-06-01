//given array, find length of the longest subseq such as that all elem of the subseq are ordered
//{50,4,10,8,30,100}
//4 {4,8,30,100}

//dp[0]=1 (1 elemento na subsequencia)
//dp[i]=se tiver elemento menor dele, anexar ao que tem o maior DP até o momento
//dp[i]=1+max(dp[j], para 0..i-1 and arr[j]<arr[i])
//iterar por todo dp e ver o maior valor

#include <bits/stdc++.h>
using namespace std;

//bttom-up solution
int lis(vector<int> arr) {
    int n=arr.size();
    vector<int> dp(n,1);
    int lis=1;
    for (int i=1;i<n;i++) {
        for (int j=0;j<i;j++) {
            if (arr[i] > arr[j]) {
                dp[i]=max(dp[i],1+dp[j]);
                lis=max(lis,dp[i]);
            }
        }
    }

    return lis;
}


int main() {
    vector<int> arr={50,4,10,8,30,100};
    cout << lis(arr) << endl;
    return 0;
}
