#include <bits/stdc++.h>
using namespace std;

int main() {
    vector<int> v{0,1,1,1,0,0,0,1};
    int sum=accumulate(begin(v),end(v),0);
    int n0=v.size()-sum;
    fill_n(begin(v),n0,0);
    fill(begin(v)+n0,end(v),1);
    for (int i:v) {
        cout << i << " " ;
    }
    cout << endl;
    return 0;
}

