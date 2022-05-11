#include<bits/stdc++.h>
using namespace std;

vector<int> getHashValue(string s) {
    vector<int> freq(26,0);
    for (char ch:s) {
        freq[ch-'a']++;
    }
    return freq;
}

vector<vector<string>> groupAnagrams(vector<string> strs){
    map<vector<int>,vector<string>> m;
    for (string s:strs) {
        vector<int> hash=getHashValue(s);
        m[hash].push_back(s);
    }
    vector<vector<string>> vvs;
    for (auto a:m) {
        vvs.push_back(a.second);
    }
    return vvs;
}

int main() {
    vector<string> strs={"eat", "tea", "tan", "ate", "nat", "bat"};

    vector<vector<string>> ans=groupAnagrams(strs);
    for (auto a:ans) {
        for (auto s:a) {
            cout << s << " ";
        }
        cout << endl;
    }
    cout << endl;
    return 0;
}