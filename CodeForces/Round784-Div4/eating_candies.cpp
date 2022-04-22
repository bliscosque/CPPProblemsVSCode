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
        if (n==1) {
            cout << "NO" << endl;
        }
        else {
            vector<int> vinc, vdec(n,0);
            vinc.push_back(vi[0]);
            for (int i=1;i<n;i++) {
                vinc.push_back(vinc[i-1]+vi[i]);
            }    

            vdec[n-1]=vi[n-1];
            for (int i=n-2;i>=0;i--) {
                vdec[i]=vdec[i+1]+vi[i];
            }    
            
            // for (auto i:vinc) {
            //     cout << i << ",";
            // }
            // cout << endl;
            // for (auto i:vdec) {
            //     cout << i << ",";
            // }
            // cout << endl;

            int max=INT_MIN;
            int i=0;
            int j=n-1;
            while (i<j) {
                // cout << i << " - " << j << endl;
                // cout << vinc[i] << " - " << vdec[j] << endl;

                if (vinc[i] == vdec[j]) {
                    //find a solution
                    max=(i+1) + (n-j);
                    i++;
                    j--;
                }
                else if (vinc[i] < vdec[j]) {
                    i++;
                }
                else {
                    j--;
                }
            }
            if (max != INT_MIN) cout << max << endl;
            else cout << 0 << endl;
        }

        tc--;
    }
    
    return 0;
}