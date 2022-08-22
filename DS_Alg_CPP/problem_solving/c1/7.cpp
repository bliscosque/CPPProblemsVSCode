#include <bits/stdc++.h>
using namespace std;

int main() {
    vector<int> v(10);
    iota(begin(v),end(v),0);
    for(int i=0;i<v.size();i+=2) {
       cout << v[i] << " "; 
    }
    cout << endl;
    return 0;
}

