// @before-stub-for-debug-begin
#include <vector>
#include <string>
#include "commoncppproblem162.h"

using namespace std;
// @before-stub-for-debug-end

/*
 * @lc app=leetcode id=162 lang=cpp
 *
 * [162] Find Peak Element
 */

//20220529
//20220530

#include <bits/stdc++.h>
using namespace std;

// @lc code=start
class Solution {
public:
    int findPeakElement(vector<int>& nums) {
        if (nums.size()==1) return 0;
        //agregando as regras para elemento 0 e ultimo
        nums.insert(nums.begin(),INT_MIN);
        nums.push_back(INT_MIN);

        int s=0, e=nums.size()-1;
        int mid;
        while (s<=e) {
            mid=s+(e-s)/2;
            if (mid > 0 && mid<nums.size()-1 && nums[mid]>nums[mid-1] && nums[mid]>nums[mid+1]) {
                return mid-1;
            }
            else if (mid > 0 && nums[mid] >= nums[mid-1]) {
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

