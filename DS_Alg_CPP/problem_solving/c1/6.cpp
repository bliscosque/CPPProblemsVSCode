#include <bits/stdc++.h>
using namespace std;

void findMaximas(vector<int> a) {
    int n=a.size();
    if (a[0]>a[1]) cout << a[0] << " ";
    for (int i=1;i<n-1;i++) {
        if (a[i-1]<a[i] && a[i]>a[i+1]) cout << a[i] << " ";
    }
    if (a[n-1]>a[n-2]) cout << a[n-1] << " ";
    cout << endl;
}

int main() {
    vector<int> a={100, 180, 260, 310, 40, 535, 695};
    findMaximas(a);
    vector<int> b={23, 13, 25, 29, 33, 19, 34, 45, 65, 67};
    findMaximas(b);
    return 0;
}

