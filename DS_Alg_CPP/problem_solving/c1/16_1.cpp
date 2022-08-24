#include <bits/stdc++.h>
using namespace std;

void findElemSum(vector<int> a, int s) {
    sort(a.begin(),a.end());
    int n=a.size();
    int l=0,r=n-1;
    while(l<=r) {
        if (a[l]+a[r]==s) {
            cout << a[l] << " " << a[r] << endl;
            break;
        }
        if (a[l]+a[r]>s) r--;
        else l++; 
    }
}

int main() {
    vector<int> a={6,10,38,2,9,8,50};
    findElemSum(a,40);
    return 0;
}

