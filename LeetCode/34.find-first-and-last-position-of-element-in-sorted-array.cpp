/*
 * @lc app=leetcode id=34 lang=cpp
 *
 * [34] Find First and Last Position of Element in Sorted Array
 */
#include <bits/stdc++.h>
using namespace std;

// @lc code=start
class Solution {
public:
    vector<int> searchRange(vector<int>& nums, int target) {
        auto lb=lower_bound(nums.begin(),nums.end(),target);
        if (lb==nums.end() || *lb!=target) return {-1, -1};
        auto ub=upper_bound(nums.begin(),nums.end(),target);
        int lbidx=lb-nums.begin();
        int ubidx=ub-nums.begin();
        return {lbidx,ubidx-1};
    }
};
// @lc code=end

