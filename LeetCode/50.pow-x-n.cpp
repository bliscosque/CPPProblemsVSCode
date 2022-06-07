/*
 * @lc app=leetcode id=50 lang=cpp
 *
 * [50] Pow(x, n)
 */

// @lc code=start
class Solution {
public:
    double mP(double x, long long int n) {
        double ans=1.0;
        while (n>0) {
            if (n%2==1) {
                ans*=x;
            }
            x*=x;
            n/=2;
        }
        return ans;
    }
    double myPow(double x, int n) {
        if (x==0.0) return 0.0;
        if (n==0) return 1.0;
        if (n<0) {
            return 1.0/mP(x,abs(n));
        }
        return mP(x,n);
    }
};
// @lc code=end

