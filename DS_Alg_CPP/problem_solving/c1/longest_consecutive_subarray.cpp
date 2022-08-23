#include <bits/stdc++.h>
using namespace std;

int longestConsecNumsSubarray(vector<int> a) {
    int n=a.size();
    int ans=0;
    vector<bool> fr(n,false);
    for (int l=0;l<n;l++) {
        for (int i=0;i<n;i++) { //clear freq array
            fr[i]=false;
        }
        int minN=a[l], maxN=a[l];
        for (int r=l;r<n;r++) {
            if (fr[a[r]]==true) break;
            fr[a[r]]=true;
            minN=min(minN,a[r]);
            maxN=max(maxN,a[r]);
            if (r-l == maxN-minN)
                ans=max(ans,r-l+1);
        }
    }
    return ans;
}

int main() {
    vector<int> a={3,7,1,4,2,5,3,8,10,9};
    cout << longestConsecNumsSubarray(a) << endl;
    return 0;
}

