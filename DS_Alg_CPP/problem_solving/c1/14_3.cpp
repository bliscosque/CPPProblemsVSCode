#include <bits/stdc++.h>
using namespace std;

vector<int> dup(vector<int> a) {
    int n=a.size();
    vector<int> freq(n,0), ans;
    for (int i=0;i<n;i++) {
        freq[a[i]]++;
    }
    for (int i=0;i<n;i++) {
        if (freq[i]>=2) ans.push_back(i); 
    }
    return ans;
}
int main() {
    vector<int> a{1,2,0,1,1,0,3,9,6,2};
    vector<int> ans=dup(a);
    for(auto a:ans) {
        cout << a << " ";
    }  
    cout << endl;
    return 0;
}

