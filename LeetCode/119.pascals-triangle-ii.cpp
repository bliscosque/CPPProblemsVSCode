/*
 * @lc app=leetcode id=119 lang=cpp
 *
 * [119] Pascal's Triangle II
 */

// @lc code=start
class Solution {
public:
    vector<int> getRowRec(int rowIndexPend,vector<int> &vi) {
        if (rowIndexPend==0) return vi;
        int n=vi.size();
        int ant1=vi[0];
        for (int i=1;i<n;i++) {
            int ant2=vi[i];
            vi[i]=ant1+ant2;
            ant1=ant2;
        }
        vi.push_back(1);
        return getRowRec(rowIndexPend-1,vi);
    }
    vector<int> getRow(int rowIndex) {
        vector<int> vi = {1};
        return getRowRec(rowIndex,vi);
    }
};
// @lc code=end

