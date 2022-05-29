/*
 * @lc app=leetcode id=278 lang=cpp
 *
 * [278] First Bad Version
 */

#include <bits/stdc++.h>
using namespace std;

// @lc code=start
// The API isBadVersion is defined for you.
// bool isBadVersion(int version);

class Solution {
public:
    int firstBadVersion(int n) {
        int s=1, e=n;
        int mid;
        int firstfound=n;
        while (s<=e) {
            mid=s+(e-s)/2;
            if (isBadVersion(mid)) {
                e=mid-1;
                firstfound=mid;
            }
            else {
                s=mid+1;
            }
        }
        return firstfound;
    }
};
// @lc code=end

