#include <bits/stdc++.h>
using namespace std;

int main() {
    vector<int> vi{1,2,1,1,1,1,0,2,2,0,0};
    int s=0, e=vi.size()-1;
    while (s<e) {
        //cout << s << " " << e << endl;
        if (vi[s]==0||vi[s]==1) s++;
        else if (vi[e]==2) e--;
        else if (vi[s]==2 && (vi[e]==0 || vi[e]==1))  
            swap(vi[s],vi[e]);
        //for (auto a:vi) cout << a << " ";
        //cout << endl;
    }    
    
    for (auto a:vi) cout << a << " ";
    cout << endl;
    
    s=0;
    while (s<e) {
        if (vi[s]==0) s++;
        else if (vi[e]>=1) e--;
        else if (vi[s]==1 && vi[e]==0) swap(vi[s],vi[e]);
    }
    for(auto a:vi) {
        cout << a << " ";
    }
    cout << endl;
    return 0;
}

