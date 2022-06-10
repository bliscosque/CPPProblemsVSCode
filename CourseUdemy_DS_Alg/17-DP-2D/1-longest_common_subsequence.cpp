//s1="ABCD"
//s2="ABEDG"
//3 (ABD)

//if (s(i) == s(j)), inclui ambos e faz recursao no subproblema (1+subproblema)
//se nao faz 2 chamadas, ignorando s[i] e s[j]
//se algum das string estiver null, base case

#include <string>
#include <iostream>
#include <vector>
using namespace std;

int lcs(string s1, string s2) {
    if (s1=="" || s2=="") return 0;
    if (s1[0]==s2[0]) {
        return 1+lcs(s1.substr(1),s2.substr(1));
    }
    else {
        return max(lcs(s1.substr(1),s2),lcs(s1,s2.substr(1)));
    }
}

/* Outra opcao, de acordo com curso */
int lcs(string s1, string s2, int i, int j, vector<vector<int>> &dp) {
    if (i==s1.length() || j==s2.length()) return 0;

    //check if already computed
    if (dp[i][j]!=-1) {
        return dp[i][j];
    }

    if (s1[i]==s2[j]) {
        return dp[i][j]=1+lcs(s1,s2,i+1,j+1,dp);
    }
    int op1=lcs(s1,s2,i+1,j,dp);
    int op2=lcs(s1,s2,i,j+1,dp);
    return dp[i][j]=max(op1,op2);
}


int main() {
    string s1="ABCD";
    string s2="ABEDG";
    int n1=s1.length();
    int n2=s2.length();

    vector<vector<int>> dp(n1,vector<int>(n2,-1));

    cout << lcs(s1,s2,0,0,dp) << endl;

    return 0;
}