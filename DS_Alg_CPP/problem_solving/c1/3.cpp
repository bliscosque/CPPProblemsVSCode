#include <bits/stdc++.h>
using namespace std;

int main() {
    int max_v=INT_MIN;
    vector<int> v={5,2,3,1,10};
    for (auto i:v) {
        max_v=max(max_v,i);
    }
    cout << max_v << endl;
    return 0;
}

