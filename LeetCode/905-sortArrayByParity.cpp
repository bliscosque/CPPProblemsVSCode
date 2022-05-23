#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    vector<int> sortArrayByParity(vector<int>& nums) {
        int n=nums.size();
        int l=0,r=0;
        while (l<n && r<n) {
            if (nums[l]%2==1) {
                if (r<l) r=l+1;
                while (r<n && nums[r]%2==1) {
                    r++;
                }
                if (r<n) {
                    swap(nums[r],nums[l]);
                }
            }
            else l++;
        }
        return nums;
    }
};

int main() {
    Solution s;
    vector<int> nums1={3,1,2,4};
    vector<int> nums2={0,1};

    s.sortArrayByParity(nums1);
    for (auto i:nums1) {
        cout << i << ",";
    }
    cout << endl;
    s.sortArrayByParity(nums2);
    for (auto i:nums2) {
        cout << i << ",";
    }
    cout << endl;
    
    return 0;
}