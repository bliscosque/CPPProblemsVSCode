#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int thirdMax(vector<int>& nums) {
        set<int> s;
        for (auto a:nums) {
            s.insert(a);
        }
        if (s.size() >=3) {
            auto a=s.end();
            a--;
            a--;
            a--;
            return *a;
        }
        else {
            auto a=s.end();
            a--;
            return *a;
        }
    }
};

int main() {
    Solution s;
    vector<int> nums1={3,2,1};
    vector<int> nums2={1,2};
    vector<int> nums3={2,2,3,1};
    cout << s.thirdMax(nums1) << endl;
    cout << s.thirdMax(nums2) << endl;
    cout << s.thirdMax(nums3) << endl;
    cout << endl;
    return 0;
}