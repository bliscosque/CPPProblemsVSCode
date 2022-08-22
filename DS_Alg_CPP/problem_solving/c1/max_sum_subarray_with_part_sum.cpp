#include <bits/stdc++.h>
using namespace std;

long long maxSumSubarray(vector<int> a) {
    int n=a.size();
    long long minS=0, ans=a[0];
    vector<int> s(n);
    s[0]=a[0];
    for (int i=1;i<n;i++) s[i]=s[i-1]+a[i];
    for(int i=0;i<n;i++) {
        if (s[i]-minS > ans) ans=s[i]-minS;
        if (s[i] < minS) minS=s[i];
    }
    return ans;
}

int main() {
    vector<int> a{5,-6,3,4,-2,3,-3};
    cout << maxSumSubarray(a) << endl;
    return 0;
}

