/*
 * @lc app=leetcode id=9 lang=cpp
 *
 * [9] Palindrome Number
 */
#include <bits/stdc++.h>
using namespace std;

// @lc code=start
class Solution {
public:
    bool isPalindrome(int x) {
        if (x<0) return false;
        string s=to_string(x), s_rev;
        reverse_copy(begin(s), end(s), back_inserter(s_rev));
        return s==s_rev;
    }
};
// @lc code=end

