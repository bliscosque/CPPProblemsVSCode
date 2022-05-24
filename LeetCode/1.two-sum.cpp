/*
 * @lc app=leetcode id=1 lang=cpp
 *
 * [1] Two Sum
 */

#include <bits/stdc++.h>
#include <unordered_set>
using namespace std;

// @lc code=start
class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        unordered_map<int,int> us; //val,pos
        int n=nums.size();
        for (int i=0;i<n;i++) {
            if (us.empty()) {
                us[nums[i]]=i;
            }
            else {
                int sumSearch=target-nums[i];
                if (us.find(sumSearch)!=us.end()) {
                    return {us[sumSearch],i};
                }
                else {
                    us[nums[i]]=i;
                }
            }
         }
         return {};
    }
};
// @lc code=end

