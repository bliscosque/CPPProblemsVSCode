#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    vector<int> sortedSquares(vector<int>& nums) {
        vector<int> ans;
        for (int i:nums) {
            ans.push_back(i*i);
        }
        sort(ans.begin(), ans.end());
        return ans;
    }
};


int main() {
    Solution s;
    vector<int> v1={-4,-1,0,3,10};
    vector<int> ans1=s.sortedSquares(v1);
    
    for (auto i:ans1) {
        cout << i << " ";
    }
    cout << endl;

    vector<int> v2={-7,-3,2,3,11};
    vector<int> ans2=s.sortedSquares(v2);
    
    for (auto i:ans2) {
        cout << i << " ";
    }
    cout << endl;

    return 0;
}