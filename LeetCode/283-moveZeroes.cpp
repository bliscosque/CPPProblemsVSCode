#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    // void moveZeroes(vector<int>& nums) {
    //     int c_ptr=0;
    //     for (int i=0;i<nums.size();i++) {
    //         if (nums[i]!=0) {
    //             nums[c_ptr]=nums[i];
    //             c_ptr++;
    //         }
    //     }
    //     for (int i=c_ptr;i<nums.size();i++) {
    //         nums[i]=0;
    //     }
    // }
    
    //Using STL
    void moveZeroes(vector<int>& nums) {
        fill(remove(nums.begin(),nums.end(),0),end(nums),0);
    }
};

int main() {
    Solution s;
    vector<int> nums1={0,1,0,3,12};
    vector<int> nums2={0};

    s.moveZeroes(nums1);
    for (auto i:nums1) {
        cout << i << ",";
    }
    cout << endl;
    s.moveZeroes(nums2);
    for (auto i:nums2) {
        cout << i << ",";
    }
    cout << endl;
    
}