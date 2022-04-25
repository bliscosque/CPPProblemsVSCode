#include<vector>
#include<algorithm>
#include<climits>
#include<iostream>
using namespace std;


pair<int,int> minDifference(vector<int> a,vector<int> b){
    sort(a.begin(),a.end());
    sort(b.begin(),b.end());
    // for (int el:a) {
    //     cout << el << " ";
    // }
    // cout << endl;
    // for (int el:b) {
    //     cout << el << " ";
    // }
    // cout << endl;

    int na=a.size();
    int nb=b.size();
    int ans=INT_MAX;
    pair<int,int> pans;

    int pb=0;
    for(int elA: a) {
        bool next=false;
        while(b[pb] <= elA ){
            cout << "comparing: " << elA << " with: " << b[pb] << endl;
            if (pb==nb) {
                pb=nb-1;
                break;
            }
            if (abs(elA-b[pb])<ans) {
                ans=abs(elA-b[pb]);
                pans={elA,b[pb]};
                cout << "min val: " << ans << endl;
            }
            pb++;
        }
        if (abs(elA-b[pb])<ans) {
            ans=abs(elA-b[pb]);
            pans={elA,b[pb]};
            cout << "min val: " << ans << endl;
        }

        if (pb>1) pb--;
    }
    
    return pans;
}

int main() {
    vector<int> a={23,5,10,17,30};
    vector<int> b={26,134,135,14,19};

    pair<int,int> p=minDifference(a,b);
    cout << p.first << " " << p.second;

    return 0;
}