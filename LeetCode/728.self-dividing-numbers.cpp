/*
 * @lc app=leetcode id=728 lang=cpp
 *
 * [728] Self Dividing Numbers
 */

// @lc code=start
class Solution {
public:
    vector<int> selfDividingNumbers(int left, int right) {
        vector<int> ans;
        for (int i=left;i<=right;i++) {
            //cout << "i: " << i << endl;
            int k=i;
            bool flag=true;
            while (k>0 && flag) {
                int dig=k%10;
                //cout << "dig: " << dig << endl;
                k=k/10;
                //cout << "k: " << k << endl;
                if (dig==0 || i%dig!=0) flag=false;
            }
            if (flag) 
                ans.push_back(i);
        }
        return ans;
    }
};
// @lc code=end

