// @before-stub-for-debug-begin
#include <vector>
#include <string>
#include "commoncppproblem69.h"

using namespace std;
// @before-stub-for-debug-end

/*
 * @lc app=leetcode id=69 lang=cpp
 *
 * [69] Sqrt(x)
 */

#include <bits/stdc++.h>
// @lc code=start
class Solution {
public:
    int mySqrt(int x) {
       long long int x1=x;
       long long int s=0;
       long long int e=x;
       long long int mid;
       long long int max_enc=-1;
       while (s<=e) {
           mid=(s+e)/2;
           if (mid*mid==x1) {
               return mid;
           }
           else if (mid*mid>x1) {
               e=mid-1;
           }
           else {
               s=mid+1;
               if (max_enc<mid) max_enc=mid;
           }
       } 
       return max_enc;
    }
};
// @lc code=end

