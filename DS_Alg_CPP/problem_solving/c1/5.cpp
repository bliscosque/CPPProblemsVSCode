#include <bits/stdc++.h>
using namespace std;

int main() {
    vector<int> vi{99,10,2,8,100,1};
    int max0=INT_MIN,max1=INT_MIN;
    for (auto i:vi) {
        if (i>max0) {
            max1=max0;
            max0=i;
        }
        else if (i>max1) {
            max1=i;
        }
    }
    cout << max1 << endl;
    return 0;
}

