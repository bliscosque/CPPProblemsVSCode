#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int findMaxConsecutiveOnes(vector<int>& nums) {
        int cmax=0;
        int cnt=0;
        for (auto i:nums) {
            if (i==0) {
                cmax=max(cmax,cnt);
                cnt=0;
            }
            else cnt++;
        }
        return max(cmax,cnt);
    }
};

int main() {
    Solution s;
    vector<int> v1={1,1,0,1,1,1};
    cout << s.findMaxConsecutiveOnes(v1) << endl;
    
    vector<int> v2={1,0,1,1,0,1};
    cout << s.findMaxConsecutiveOnes(v2) << endl;
    
    return 0;
}