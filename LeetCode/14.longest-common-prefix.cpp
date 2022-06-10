/*
 * @lc app=leetcode id=14 lang=cpp
 *
 * [14] Longest Common Prefix
 */

#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

// @lc code=start
class Solution {
public:
    string longestCommonPrefix(vector<string>& strs) {
        int n=strs.size();
        int min_size=INT_MAX;
        for (int i=0;i<n;i++) {
            int s=strs[i].size();
            min_size=min(min_size,s);
        }
        //cout << min_size << endl;
        for (int i=0;i<min_size;i++)
        {
            char ch=strs[0][i];
            for (int j=1;j<n;j++) {
                if (strs[j][i]!=ch) {
                    //cout << "dif: " << ch << strs[j][i] << endl;
                    return strs[0].substr(0,i);
                } 
            }
        }
        return strs[0].substr(0,min_size);
    }
};
// @lc code=end

