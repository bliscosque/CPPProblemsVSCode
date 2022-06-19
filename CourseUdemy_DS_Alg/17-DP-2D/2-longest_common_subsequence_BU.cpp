//s1="ABCD"
//s2="ABEDG"
//3 (ABD)

//if (s(i) == s(j)), inclui ambos e faz recursao no subproblema (1+subproblema)
//se nao faz 2 chamadas, ignorando s[i] e s[j]
//se algum das string estiver null, base case

#include <string>
#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int lcs(string s1, string s2) {
    int n1=s1.length();
    int n2=s2.length();
    vector<vector<int>> dp(n1+1,vector<int>(n2+1,0));

    for (int i=1;i<=n1;i++) {
        for (int j=1;j<=n2;j++) {
            if (s1[i-1]==s2[j-1]) {
                dp[i][j]=1+dp[i-1][j-1];
            }
            else {
                int op1=dp[i-1][j];
                int op2=dp[i][j-1];
                dp[i][j]=max(op1,op2);
            }
        }
    }

    for (int i=0;i<=n1;i++) {
        for (int j=0;j<=n2;j++) {
            cout << dp[i][j] << " ";
        }
        cout << endl;
    }

    //print the LCS
    vector<char> result;
    int i=n1,j=n2;
    while (i!=0 && j!=0) {
        if (dp[i][j]==dp[i][j-1]) {
            j--;
        }
        else if (dp[i][j]==dp[i-1][j]) {
            i--;
        }
        else {
            result.push_back(s1[i-1]);
            i--;
            j--;
        }
    }
    reverse(result.begin(),result.end());
    for (char ch:result) {
        cout << ch << ",";
    }
    cout << endl;

    return dp[n1][n2];
}


int main() {
    string s1="ABCD";
    string s2="ABEDG";
    int n1=s1.length();
    int n2=s2.length();


    cout << lcs(s1,s2) << endl;

    return 0;
}