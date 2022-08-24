#include <bits/stdc++.h>
using namespace std;

vector<int> dup(vector<int> a) {
    unordered_set<int> us;
    int n=a.size();
    vector<int> ans;
    for (int i=0;i<n;i++) {
        if (us.contains(a[i])) {
            ans.push_back(a[i]);
        }
        else (us.insert(a[i]));
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

