/*
 * @lc app=leetcode id=112 lang=cpp
 *
 * [112] Path Sum
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
    bool find=false;
    void hasPathSum(TreeNode* root, int targetSum, int partSum) {
        if (root->left==nullptr && root->right==nullptr) { //leaf node
            if (targetSum==partSum+root->val) find=true;
        }
        if (root->left) {
            hasPathSum(root->left,targetSum,partSum+root->val);
        }
        if (root->right) {
            hasPathSum(root->right,targetSum,partSum+root->val);
        }
    }

    bool hasPathSum(TreeNode* root, int targetSum) {
        find=false;
        if (root==nullptr) return false; 
        hasPathSum(root,targetSum,0);
        return find;
    }
};
// @lc code=end

