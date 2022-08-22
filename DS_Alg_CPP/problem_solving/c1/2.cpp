#include <bits/stdc++.h>
using namespace std;

int main() {
    vector<vector<int>> v = {{1,2},{3,4}};
    int sum=0;
    for (auto i=0;i<v[0].size();i++) {
        for (auto j=0;j<v.size();j++) {
            sum+=v[i][j];
        }
    }
    cout << sum << endl;
    return 0;
}

