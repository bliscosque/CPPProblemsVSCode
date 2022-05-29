/*
 * @lc app=leetcode id=162 lang=cpp
 *
 * [162] Find Peak Element
 */

//20220529

#include <bits/stdc++.h>
using namespace std;

// @lc code=start
class Solution {
public:
    int findPeakElement(vector<int>& nums) {
        int s=0, e=nums.size()-1;
        int mid;
        while (s<=e) {
            mid=s+(e-s)/2;
            if (mid > 0 && mid<nums.size()-2 && nums[mid]>nums[mid-1] && nums[mid]>nums[mid+1]) {
                return mid;
            }
            else if (mid > 0 && nums[mid] > nums[mid-1]) {
                s=mid+1;
            }
            else {
                e=mid-1;
            }
        }
        return mid;
    }
};
// @lc code=end

