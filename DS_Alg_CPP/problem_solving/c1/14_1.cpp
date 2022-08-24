#include <bits/stdc++.h>
using namespace std;

vector<int> dup(vector<int> a) {
    int n=a.size();
    vector<int> ans;
    vector<bool> verified(n,true);
    for (int i=0;i<n;i++) {
        if (!verified[i]) continue;
        for (int j=i+1;j<n;j++) {
           if (a[i] == a[j]) {
               ans.push_back(a[i]);
               verified[j]=false;
           } 
        }
    }
    return ans;
}
int main() {
    vector<int> a{1,2,0,1,1,0,3,10,6,2};
    vector<int> ans=dup(a);
    for(auto a:ans) {
        cout << a << " ";
    }  
    cout << endl;
    return 0;
}

