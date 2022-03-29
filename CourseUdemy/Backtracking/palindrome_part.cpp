#include<bits/stdc++.h>
using namespace std;

bool palindrome(string &str) {
    string tmp=str;
    reverse(tmp.begin(), tmp.end());
    return tmp==str;
}

void partition_rec(string &str, int pos, vector<string> &cur, vector<vector<string>> &ans ) {
    if (pos >= str.size()) {
        ans.push_back(cur);
        return;
    }
    for (int i=pos;i<str.size();i++) {
        string tmp = str.substr(pos,i-pos+1);
        if (palindrome(tmp)) {
            cur.push_back(tmp);
            partition_rec(str,i+1,cur,ans);
            cur.pop_back();
        }
    }
}

vector<vector<string>> partition(string s) {
    vector<vector<string>> ans;
    vector<string> cur;
    partition_rec(s,0,cur,ans);
    return ans;
}

int main() {
    vector<vector<string>> vvs = partition("aab");

    for (auto vs: vvs) {
        for (auto s: vs) {
            cout << s << " ";
        }
        cout << endl;
    }
    return 0;
}