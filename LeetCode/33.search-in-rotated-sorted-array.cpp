// @before-stub-for-debug-begin
#include <vector>
#include <string>
#include "commoncppproblem33.h"

using namespace std;
// @before-stub-for-debug-end

/*
 * @lc app=leetcode id=33 lang=cpp
 *
 * [33] Search in Rotated Sorted Array
 */
//20220527
//20220528
#include <bits/stdc++.h>
using namespace std;

// @lc code=start
class Solution {
public:
    int search(vector<int>& nums, int target) {
        int s=0;
        int e=nums.size()-1;
        while (s<=e) {
            int mid=s+(e-s)/2;

            if (nums[mid]==target) return mid;

            if (nums[s]<=nums[mid]) { //parte da esquerda esta ordenada
                if (target>=nums[s] && target <=nums[mid]) {
                    e=mid-1;
                }
                else {
                    s=mid+1;
                }
            }
            else { //parte esquerda nao ordenada
                if (target>=nums[mid] && target <= nums[e]) { 
                    s=mid+1;
                }
                else {
                    e=mid-1;
                }
                
            }
        }
        return -1;
    }
};
// @lc code=end

