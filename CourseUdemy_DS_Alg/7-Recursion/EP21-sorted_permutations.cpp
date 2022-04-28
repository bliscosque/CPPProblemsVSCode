#include<bits/stdc++.h>
using namespace std;

set<string> ans;

void findSortedPermutations(string s, string perm, int i){
    int n=s.size();
    if (i==n) {
        ans.insert(perm);
        return;
    }

    for (int j=i;j<n;j++) {
        swap(s[i],s[j]);
        findSortedPermutations(s,perm+s[i],i+1);
        swap(s[i],s[j]);
    }
}



vector<string> findSortedPermutations(string s){
    ans.clear();
    findSortedPermutations(s,"",0);
    vector<string> ans2;
    for (auto s:ans) {
        ans2.push_back(s);
    }
    return ans2;
}

int main() {
    string input="abc";
    vector<string> ans=findSortedPermutations(input);
    for (auto i: ans) {
        cout << i << endl;
    }
}