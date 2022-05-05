#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    void duplicateZeros(vector<int>& arr) {
        int cnt=0;
        for (int i:arr) {
            if (i==0) cnt++;
        }
        int last_orig=arr.size()-1;
        arr.resize(arr.size()+cnt);
        for (int i=arr.size()-1;i>=0;i--) {
            arr[i]=arr[last_orig];
            last_orig--;
            if (arr[i]==0) {
                arr[i-1]=0;
                i--;
            }
        }
        while (cnt>0) {
            arr.pop_back();
            cnt--;
        }
    }
};

int main() {
    Solution s;
    vector<int> v1={1,0,2,3,0,4,5,0};
    s.duplicateZeros(v1);
    
    for (auto i:v1) {
        cout << i << " ";
    }
    cout << endl;

    vector<int> v2={1,2,3};
    s.duplicateZeros(v2);
    
    for (auto i:v2) {
        cout << i << " ";
    }
    cout << endl;

    return 0;
}