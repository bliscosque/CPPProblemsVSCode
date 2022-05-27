/*
 * @lc app=leetcode id=374 lang=cpp
 *
 * [374] Guess Number Higher or Lower
 */

#include <climits>
// @lc code=start
/** 
 * Forward declaration of guess API.
 * @param  num   your guess
 * @return 	     -1 if num is higher than the picked number
 *			      1 if num is lower than the picked number
 *               otherwise return 0
 * int guess(int num);
 */

class Solution {
public:
    int guessNumber(int n) {
        long long int s=1;
        long long int e=n;
        long long int mid;
        while (s<=e) {
            mid=(s+e)/2;
            long long int ret=guess(mid);
            if (ret==0) {
                return mid;
            }
            else if (ret==1) {
                s=mid+1;
            }
            else {
                e=mid-1;
            }
        }
        return n;
    }
};
// @lc code=end

