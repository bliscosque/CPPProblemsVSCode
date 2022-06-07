// @before-stub-for-debug-begin
#include <vector>
#include <string>
#include "commoncppproblem70.h"

using namespace std;
// @before-stub-for-debug-end

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

    int climbStairs(int n, vector<int> &dp) {
        if (n<0) return 0; //passou
        if (n==0) return 1; //chegou
        if (dp[n]!=-1) return dp[n];
        int ans=climbStairs(n-1,dp)+climbStairs(n-2,dp);
        return dp[n]=ans;
        
    }
    int climbStairs(int n) {
        vector<int> dp(50,-1);
        dp[0]=0;
        dp[1]=1;

        return climbStairs(n-1,dp)+climbStairs(n-2,dp);
    }
};
// @lc code=end

