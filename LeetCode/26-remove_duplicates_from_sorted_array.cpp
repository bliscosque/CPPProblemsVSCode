#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int removeDuplicates(vector<int>& nums) {
        int count=0;
        int n=nums.size();
        for (auto it=nums.begin();it!=nums.end();it++) {
            while ((it+1)!=nums.end() && *it==*(it+1)) {
                count++;
                nums.erase(it+1);
            }
        }        
        
        return n-count;
    }
};

int main() {
    Solution s;
    vector<int> nums={0,0,1,1,1,2,2,3,3,4};
    cout << s.removeDuplicates(nums) << endl;
    for (auto a:nums) {
        cout << a << " ";
    }
    cout << endl;
    return 0;
}