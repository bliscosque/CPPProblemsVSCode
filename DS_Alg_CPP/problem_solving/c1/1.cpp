#include <bits/stdc++.h>
using namespace std;

int main() {
    vector<int> v1={1,2,3,4,5,6,7,8,9,10};
    int total=accumulate(v1.begin(),v1.end(),0);
    int n=v1.size();
    cout << total/n;

    return 0;
}

