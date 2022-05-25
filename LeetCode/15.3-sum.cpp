/*
 * @lc app=leetcode id=15 lang=cpp
 *
 * [15] 3Sum
 */

#include <bits/stdc++.h>
using namespace std;

// @lc code=start
class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {
        set<vector<int>> ans;
        sort(nums.begin(),nums.end());
        int n=nums.size();
        for (int i=0;i<n;i++) {
            int j=i+1; //next elem
            int k=n-1; //last elem
            while (j<k) {
                int sum=nums[i]+nums[j]+nums[k];
                if (sum==0) {
                    ans.insert({nums[i],nums[j],nums[k]});
                    j++;
                    k--;
                }
                else if (sum>0) k--;
                else j++;
            }
        }
        vector<vector<int>> ans2;
        for (auto vi:ans) {
            ans2.push_back(vi);
        }
        return ans2;
    }
};
// @lc code=end

