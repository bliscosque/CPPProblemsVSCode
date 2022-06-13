/*
 * @lc app=leetcode id=13 lang=cpp
 *
 * [13] Roman to Integer
 */

#include <string>
using namespace std;
// @lc code=start
class Solution {
public:
    int romanToInt(string s) {
        int ans=0;
        for (int i=0;i<s.size();i++) {
            char ch=s[i];
            if (ch=='M') ans+=1000;
            else if (ch=='D') ans+=500;
            else if (ch=='C') {
                if (i+1 < s.size() && s[i+1]=='D') {
                    i++;
                    ans+=400;
                }
                else if (i+1 < s.size() && s[i+1]=='M') {
                    i++;
                    ans+=900;
                }
                else ans+=100;
            }
            else if (ch=='L') {
                ans+=50;
            }
            else if (ch=='X') {
                if (i+1 < s.size() && s[i+1]=='L') {
                    i++;
                    ans+=40;
                }
                else if (i+1 < s.size() && s[i+1]=='C') {
                    i++;
                    ans+=90;
                }
                else ans+=10;

            }
            else if (ch=='V') {
                ans+=5;
            }
            else if (ch=='I') {
                if (i+1 < s.size() && s[i+1]=='V') {
                    i++;
                    ans+=4;
                }
                else if (i+1 < s.size() && s[i+1]=='X') {
                    i++;
                    ans+=9;
                }
                else ans+=1;
            }

        }
        return ans;
    }
};
// @lc code=end

