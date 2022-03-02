#include <bits/stdc++.h>
using namespace std;

//based on https://www.youtube.com/watch?v=6LpQOyiPxY0 and https://github.com/RevathyGovindarasu/LeetCode_codes/blob/master/FindtheShortestSuperstring

//return string 2 after removing common sequence between string1 and string2
string getSuffix(string s1, string s2) {
    int l1=s1.size();
    int l2=s2.size();
    //cout << "getS: " << s1 << " " << s2 << endl;
    for (int j=max(0,l1-l2);j<l1;j++) {
        //cout << "j: " << j << endl;
        //cout << "s1.substr(j): " << s1.substr(j) << endl;
        //cout << "s2.substr(0,l1-j): " << s2.substr(0,l1-j) << endl;
        if (s1.substr(j)==s2.substr(0,l1-j))
            return s2.substr(l1-j);
    }
    return s2;

}

string shortestSuperstring(vector<string> words) {
    int size=words.size();
    if (size==1) return words[0];
    map<int,vector<string>> dp;
    vector<vector<string>> memo(size,vector<string>(size,"")); 
    
    for (int j=0;j<size;j++) {
        for (int k=0;k<size;k++) {
            if (j==k) continue;
            memo[j][k]=getSuffix(words[j],words[k]);
            //cout << "memo " << j << " " << k << " " << memo[j][k];
            dp[(1<<j)|(1<<k)].push_back(words[j]+memo[j][k]);
        }
    }
    for (auto i:dp) {
        cout << i.first << " ";
        for (auto j: i.second) {
            cout << j<< ",";
        }
        cout << endl;
    } 

    //merge values in map
    for (int n=3;n<=size;n++) {
        for (auto a: dp) {
            int key=a.first;
            cout << "key: " << key << endl;
            vector<string> arr=a.second;
            for (int j=0;j<arr.size();j++) {
                    cout << "j: " << j << " k: " << k << endl;
                    dp[(key & (1<<k))].push_back(arr[j] + memo[j][k]);
            }
            
        }
        for (auto i:dp) {
            cout << i.first << " ";
            for (auto j: i.second) {
                cout << j<< ",";
            }
            cout << endl;
        } 
    }
    cout << "outside for" << endl;
    string res=dp[((1<<size)-1)][0];
    for (string s:dp[((1<<size)-1)]) {
        if (res.length() > s.length()) 
            res=s;
    }
    return res;
}

int main() {
    vector<string> words = {"catg", "ctaag", "gcta", "ttca", "atgcatc"};
    cout << shortestSuperstring(words) << endl;
    return 0;
}