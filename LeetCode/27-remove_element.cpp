#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int removeElement(vector<int>& nums, int val) {
        int count=0;
        int n=nums.size();
        for (auto it=nums.begin();it!=nums.end();it++) {
            if (*it==val) {
                count++;
                nums.erase(it);
                it--;
            }
        }        
        
        return n-count;
    }
};

int main() {
    Solution s;
    vector<int> nums={0,1,2,2,3,0,4,2};
    cout << s.removeElement(nums,2) << endl;
    for (auto a:nums) {
        cout << a << " ";
    }
    cout << endl;
    return 0;
}

/*
[0,1,2,2,3,0,4,2]
2
*/