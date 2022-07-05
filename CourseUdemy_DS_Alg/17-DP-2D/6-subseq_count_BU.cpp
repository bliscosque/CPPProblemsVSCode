//given 2 str, find number of times second string occurs as a subseq in the first str
//s1="ABCDCE"
//s2="ABC"
//2

#include <bits/stdc++.h>
using namespace std;

//Recursive code
int countSub(string a, string b) {
    int m=a.length();
    int n=b.length();

    vector<vector<int>> dp(m+1,vector<int>(n+1,0));

    //1st column=1
    for (int i=0;i<=m;i++) {
        dp[i][0]=1;
    }

    for (int i=1;i<=m;i++) {
        for (int j=1;j<=n;j++) {
            if (a[i-1]==b[j-1]) {
                dp[i][j]=dp[i-1][j-1]+dp[i-1][j];
            }
            else dp[i][j]=dp[i-1][j];
        }
    }

    return dp[m][n];

}


int main() {
    string a="ABCECDG";
    string b="ABC";

    cout << countSub(a,b) << endl;

    return 0;
}