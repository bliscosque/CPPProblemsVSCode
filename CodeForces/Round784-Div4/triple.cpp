#include <bits/stdc++.h>

using namespace std;

int main() {
    int tc;
    cin >> tc;
    while (tc>0) {
        int n;
        cin >> n;
        map<int,int> m;
        for (int i=0;i<n;i++) {
            int value;
            cin >> value;
            if (m.find(value)==m.end()) { //not exists
                m.insert({value,1});
            }
            else {
                m[value]++;
            }
        }
        bool found=false;
        for (auto i:m) {
            if (i.second >=3) {
                cout << i.first << endl;
                found=true;
                break;
            }
        }
        if (!found) {
            cout << -1 << endl;
        }
        tc--;
    }
    return 0;
}