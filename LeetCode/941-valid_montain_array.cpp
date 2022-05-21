#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    bool validMountainArray(vector<int>& arr) {
        if (arr.size()<3) return false;
        if (arr[0]>arr[1]) return false;
        if (arr[arr.size()-2]<arr[arr.size()-1]) return false;
        bool p1=true;
        for (int i=0;i<arr.size()-1;i++) {
            if (arr[i]==arr[i+1]) return false;
            if (p1) {
                if (arr[i]>arr[i+1]) {
                    p1=false;
                }
            }
            else {
                if (arr[i]<arr[i+1]) return false;
            }
        }
        return true;
    }
};

int main() {
    Solution s;
    vector<int> v1={2,1};
    cout << s.validMountainArray(v1) << endl;
    
    vector<int> v2={3,5,5};
    cout << s.validMountainArray(v2) << endl;

    vector<int> v3={0,3,2,1};
    cout << s.validMountainArray(v3) << endl;
    
    vector<int> v4={0,1,2,3,4,5,6,7,8,9};
    cout << s.validMountainArray(v4) << endl;
    return 0;
}