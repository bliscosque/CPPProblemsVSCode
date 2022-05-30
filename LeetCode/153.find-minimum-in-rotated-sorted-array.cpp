// @before-stub-for-debug-begin
#include <vector>
#include <string>
#include "commoncppproblem153.h"

using namespace std;
// @before-stub-for-debug-end

/*
 * @lc app=leetcode id=153 lasng=cpp
 *
 * [153] Find Minimum in Rotated Sorted Array
 */
#include <bits/stdc++.h>
using namespace std;

// @lc code=start
class Solution {
public:
    int findMin(vector<int>& nums) {
        int s=0;
        int e=nums.size()-1;
        int min=INT_MAX;
        int mid;
        while (s<=e) {
            mid=s+(e-s)/2;
            if (nums[mid] >= nums[s] && nums[mid] >= nums[e]) {
                min=std::min(min,nums[mid]);
                s=mid+1;
            }
            else if (nums[mid] > nums[s] && nums[mid] < nums[e]){
                min=std::min(min,nums[mid]);
                e=mid-1;
            }
            else { //mid < start
                min=std::min(min,nums[mid]);
                e=mid-1;
            }
        }
        return min;
    }
};
// @lc code=end

