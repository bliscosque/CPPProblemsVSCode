/*
 * @lc app=leetcode id=70 lang=cpp
 *
 * [70] Climbing Stairs
 */

//20220506

// @lc code=start
class Solution {
public:
    int ans=0;
    void climbStairs(int n, int s) {
        if (s>n) return;
        if (s==n) {
            ans++;
            return;
        }
        climbStairs(n,s+1);
        climbStairs(n,s+2);
    }
    int climbStairs(int n) {
        if (n<=1) return n;
        ans=0;
        climbStairs(n,0);
        return ans;
    }
};
// @lc code=end

