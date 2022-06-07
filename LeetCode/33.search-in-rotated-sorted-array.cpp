/*
 * @lc app=leetcode id=33 lang=cpp
 *
 * [33] Search in Rotated Sorted Array
 */

#include <bits/stdc++.h>
using namespace std;

// @lc code=start
class Solution {
public:
    int search(vector<int>& nums, int target) {
        int s=0;
        int e=nums.size()-1;
        while (s<=e) {
            int m=s+(e-s)/2;
            if (nums[m]==target) return m;
            if (nums[m]>=nums[s]) { //primeira parte
                if (target > nums[m]) {
                    s=m+1;
                }
                else if (target < nums[m] && target >= nums[s]) {
                    e=m-1;
                }
                else {
                    s=m+1;
                }
            }
            else { //segunda parte
                if (target<nums[m]) {
                    e=m-1;
                }
                else if (target>nums[m] && target <nums[s]) {
                    s=m+1;
                }
                else {
                    e=m-1;
                }
            }
        }  
        return -1;  
    }
};
// @lc code=end

