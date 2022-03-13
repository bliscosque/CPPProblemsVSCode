#include<bits/stdc++.h>
using namespace std;


bool isSorted(vector<int> &v,int n) {
    if (n==v.size()-1) return true;
    else {
        if (v[n] <= v[n+1]) return isSorted(v, n+1);
        else return false;
    }
}

int main()
{
    vector<int> v = {1,2,3,5,5};
    cout << isSorted(v, 0) << endl;

    vector<int> v2 = {1,2,3,5,7,1};
    cout << isSorted(v2, 0) << endl;
    
    return 0;
}