#include <bits/stdc++.h>

using namespace std;

int main() {
    int tc;
    cin >> tc;
    while (tc>0) {
        int n;
        cin >> n;
        bool valid_0=true;
        bool valid_1=true;
        bool par_0;
        bool par_1;
        for (int i=0;i<n;i++) {
            int value;
            cin >> value;
            if (i==0) {
                par_0=value%2;
            }
            else if (i==1) {
                par_1=value%2;
            }
            else {
                if (i%2==0) {
                    if (value%2 == par_0) valid_0=true;
                    else valid_0=false;
                }
                else {
                    if (value%2 == par_1) valid_1=true;
                    else valid_1=false;
                }
            }
        }
        if (valid_0 && valid_1) cout << "YES" << endl;
        else cout << "NO" << endl;
        tc--;
    }
    
    return 0;
}