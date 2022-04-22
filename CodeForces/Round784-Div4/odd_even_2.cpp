#include <bits/stdc++.h>

using namespace std;

int main() {
    int tc;
    cin >> tc;
    while (tc>0) {
        int n;
        cin >> n;
        vector<int> vi;
        for (int i=0;i<n;i++) {
            int value;
            cin >> value;
            vi.push_back(value);
        }
        if (n<=2) {
            cout << "YES" << endl;
        }
        else {
            bool b0=vi[0]%2;
            bool valid_0=true;
            for (int i=2;i<n;i+=2) {
                if (vi[i]%2!=b0) valid_0=false;
            }

            bool b1=vi[1]%2;
            bool valid_1=true;
            for (int i=3;i<n;i+=2) {
                if (vi[i]%2!=b1) valid_1=false;
            }


            if (valid_0 && valid_1) cout << "YES" << endl;
            else cout << "NO" << endl;
        }

        tc--;
    }
    
    return 0;
}