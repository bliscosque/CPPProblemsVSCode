/*
 * @lc app=leetcode id=95 lang=cpp
 *
 * [95] Unique Binary Search Trees II
 */

//20220610

// @lc code=start
/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution {
public:
    vector<TreeNode*> generateTrees(int n) {
        for (int i=1;i<=n;i++) {
            TreeNode* root=new TreeNode(i);
            for (int l=1;l<i;l++) {
                generateTrees(root->left,l);
            }
            for (int r=i+1;r<=n;r++) {
                generateTrees(root->right,r);
            }
        }
    }
};
// @lc code=end

