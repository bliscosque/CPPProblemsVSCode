#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    vector<int> findDisappearedNumbers(vector<int>& nums) {
        int n=nums.size();
        set<int> s(nums.begin(),nums.end());
        nums.clear();
        int i=1;
        for (int i=1;i<=n;i++) {
            if (s.find(i)==s.end()) {
                nums.push_back(i);
            }
        }
        return nums;
    }
};

int main() {
    Solution s;
    vector<int> nums1={4,3,2,7,8,2,3,1};
    vector<int> nums2={1,1};
    vector<int> ans1= s.findDisappearedNumbers(nums1);
    vector<int> ans2= s.findDisappearedNumbers(nums2);

    for (auto a: ans1) {
        cout << a <<",";
    }
    cout << endl;

    for (auto a: ans2) {
        cout << a <<",";
    }
    cout << endl;
    return 0;
}