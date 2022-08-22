#include <bits/stdc++.h>
using namespace std;

long long maxSumSubarray(vector<int> a) {
    int n=a.size();
    long long sum=0, ans=a[0];
    for(int i=0;i<n;i++) {
        sum+=a[i];
        ans=max(sum,ans);
        if (sum<0) sum=0;
    }
    return ans;
}

int main() {
    vector<int> a{5,-6,3,4,-2,3,-3};
    cout << maxSumSubarray(a) << endl;
    return 0;
}

