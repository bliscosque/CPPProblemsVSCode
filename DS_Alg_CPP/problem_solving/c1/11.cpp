#include <bits/stdc++.h>
using namespace std;

int main() {
    vector<int> v{1,2,3,4,5};
    int i=0, e=v.size()-1;
    while (i<e) {
        swap(v[i],v[e]);
        i++;
        e--;
    }
    for (auto i:v) {
        cout << i << " ";
    }
    cout << endl;
    return 0;
}

