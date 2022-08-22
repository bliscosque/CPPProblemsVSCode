#include <bits/stdc++.h>
using namespace std;

int main() {
    vector<int> vi{1,0,0,0,1,1};
    int s=0,e=vi.size()-1;
    while (s<e) {
        if (vi[s]==0) s++;
        else if (vi[e]==1) e--;
        else if (vi[s]==1 && vi[e]==0) swap(vi[s],vi[e]);
    }
    for (auto i:vi) {
        cout << i << " ";
    }
    cout << endl;
    return 0;
}

