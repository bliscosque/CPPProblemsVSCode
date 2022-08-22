#include <bits/stdc++.h>
using namespace std;

int main() {
    vector<pair<int,int>> vp={{1,4},{8,10},{3,6}};
    sort(vp.begin(), vp.end());
    int idx=0;
    for(int i=1;i<vp.size();i++) {
        if (vp[idx].second>=vp[i].first) {
            vp[idx].second = max(vp[idx].second,vp[i].second);
        }
        else {
            idx++;
            vp[idx]=vp[i];
        } 
    }
    vp.erase(vp.begin()+idx+1,vp.end());
    for (auto a:vp) {
        cout << a.first << " " << a.second << endl;
    }
    return 0;
}

