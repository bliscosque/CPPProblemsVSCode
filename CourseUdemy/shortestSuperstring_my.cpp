#include <bits/stdc++.h>
using namespace std;

//based on https://www.youtube.com/watch?v=6LpQOyiPxY0 and https://github.com/RevathyGovindarasu/LeetCode_codes/blob/master/FindtheShortestSuperstring

//return string 2 after removing common sequence between string1 and string2
string getSuffix(string s1, string s2) {
    int l1=s1.size();
    int l2=s2.size();
    cout << "getS: " << s1 << " " << s2 << endl;
    for (int j=max(0,l1-l2);j<l1;j++) {
        cout << "j: " << j << endl;
        cout << "s1.substr(j): " << s1.substr(j) << endl;
        cout << "s2.substr(0,l1-j): " << s2.substr(0,l1-j) << endl;
        if (s1.substr(j)==s2.substr(0,l1-j))
            return s2.substr(l1-j);
    }
    return s2;

}

string shortestSuperstring(vector<string> words) {
    int size=words.size();
    if (size==1) return words[0];
    map<int,vector<string>> dp;
    vector<vector<string>> memo; //TODO: MEMO has to be initialized
    
    for (int j=0;j<size;j++) {
        for (int k=0;k<size;k++) {
            if (j==k) continue;
            memo[j][k]=getSuffix(words[j],words[k]);
            cout << "memo " << j << " " << k << " " << memo[j][k];
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
    return "";
}

int main() {
    vector<string> words = {"catg", "ctaag", "gcta", "ttca", "atgcatc"};
    cout << shortestSuperstring(words) << endl;
    return 0;
}