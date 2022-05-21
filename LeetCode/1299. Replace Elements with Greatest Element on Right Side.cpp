#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    vector<int> replaceElements(vector<int>& arr) {
        int n=arr.size();
        int greatest=arr[n-1];
        arr[n-1]=-1;
        for (int i=n-2;i>=0;i--) {
            int tmp=arr[i];
            arr[i]=greatest;
            greatest=max(greatest,tmp);
        }
        return arr;
    }
};

int main() {
    Solution s;
    vector<int> v1={17,18,5,4,6,1};
    vector<int> ans= s.replaceElements(v1);
    for (auto i:ans) {
        cout << i << ",";
    }
    cout << endl;
    
    vector<int> v2={400};
    ans= s.replaceElements(v2);
    for (auto i:ans) {
        cout << i << ",";
    }
    cout << endl;
    
    return 0;
}