/*
 * @lc app=leetcode id=779 lang=cpp
 *
 * [779] K-th Symbol in Grammar
 */

//20220608
//3\n1
//0

// @lc code=start
class Solution {
public:
    int kthGrammar(int n, int k) {
        if (n==1) return 0;
        else {
            int nk=(k-1)/2+1; //já que começa no indice 1
            int ant=kthGrammar(n-1,nk);
            if (ant==0 ) { 
                if (k%2==1) return 0; // first position
                else return 1; //second position
            }
            else if (ant==1) {
                if (k%2==1) return 1; // first position
                else return 0; //second position
            }
        }
        return 0;
    }
};
// @lc code=end

