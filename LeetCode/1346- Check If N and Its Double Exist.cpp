#include <bits/stdc++.h>
#include <unordered_set>
using namespace std;

class Solution {
public:
    bool checkIfExist(vector<int>& arr) {
        unordered_multiset<int> us;
        for (auto i:arr) {
            us.insert(i);
        }
        for (auto i:arr) {
            if (us.count(i*2)>0 && i!=0) return true;
            if (i==0) {
                if (us.count(0)>=2) return true;
            }
        }
    return false;
    }
};


int main() {
    Solution s;
    vector<int> v1={10,2,5,3};
    cout << s.checkIfExist(v1) << endl;
    
    vector<int> v2={7,1,14,11};
    cout << s.checkIfExist(v2) << endl;
    
    vector<int> v3={0,0};
    cout << s.checkIfExist(v3) << endl;

    return 0;
}