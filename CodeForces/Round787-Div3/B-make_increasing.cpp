//WA

#include <bits/stdc++.h>
using namespace std;


int solve(vector<int> vi, int n) {
    int it=0;
    reverse(vi.begin(),vi.end());  
    vector<int> vi2=vi;
    int last=vi[0];
    int sum=0;
    for (int i=1;i<vi.size();i++) {
        if (last==1) {
            //restart trying to divide vi[0]
            vi=vi2;
            vi[0]=vi[0]/2;
            vi2=vi;

            sum=it+1;
            it++;
            last=vi[0];
            i=1;

            cout << endl;
            cout << "rest" << endl;
            for (auto i:vi) {
                cout << i << " ";
            }
            cout << endl << "LAST: " << last << endl << endl;
            
            if (last == 0) return -1;

        }
        while(vi[i] >= last) {
            vi[i]/=2;
            sum++;
        }
        last=vi[i];
    }
    return sum;
}



int main() {
    int tc;
    cin >> tc;
    while (tc>0) {
        int n;
        vector<int> vi;
        cin >> n;
        int v;
        for (int i=0;i<n;i++) {
            cin >> v;
            vi.push_back(v);
        }                
        cout << "s: " << solve(vi,n) << endl;

        tc--;
    }
    return 0;
}