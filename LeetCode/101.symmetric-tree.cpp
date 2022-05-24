/*
 * @lc app=leetcode id=101 lang=cpp
 *
 * [101] Symmetric Tree
 */
#include <bits/stdc++.h>
using namespace std;

 struct TreeNode {
     int val;
     TreeNode *left;
     TreeNode *right;
     TreeNode() : val(0), left(nullptr), right(nullptr) {}
     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 };

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
    bool isSymmetric(TreeNode*l, TreeNode*r) {
        queue<TreeNode*> ql,qr;
        ql.push(l);
        qr.push(r);
        while (!ql.empty() && !qr.empty()) {
            TreeNode* tmpl=ql.front();
            ql.pop();
            
            TreeNode* tmpr=qr.front();
            qr.pop();

            if (tmpr->val != tmpl->val) return false;
            if (tmpl->right && tmpr->left) {
                ql.push(tmpl->right);
                qr.push(tmpr->left);
            }
            if (tmpl->left && tmpr->right) {
                ql.push(tmpl->left);
                qr.push(tmpr->right);
            }
            if ((tmpl->right && !tmpr->left) || (!tmpl->right && tmpr->left)
                || (tmpl->left && !tmpr->right) || (!tmpl->left && tmpr->right)) {
                return false;
            }
        } 
        return true;
                
    }
    bool isSymmetric(TreeNode* root) {
        if (root==nullptr || (root->left==nullptr && root->right==nullptr)) return true;
        else if (root->left&&root->right) {
            return isSymmetric(root->left,root->right);
        }
        else return false;
    }
};
// @lc code=end

