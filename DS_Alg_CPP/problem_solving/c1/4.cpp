#include <bits/stdc++.h>
using namespace std;

int main() {
    int min_v=INT_MAX;
    vector<int> v={5,2,3,1,10};
    for (auto i:v) {
        min_v=min(min_v,i);
    }
    cout << min_v << endl;
    return 0;
}

