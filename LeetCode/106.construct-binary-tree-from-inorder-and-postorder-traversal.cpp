/*
 * @lc app=leetcode id=106 lang=cpp
 *
 * [106] Construct Binary Tree from Inorder and Postorder Traversal
 */

//20222405 - 1

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
    TreeNode* buildTree(vector<int>& inorder, vector<int>& postorder) {
        int val=postorder.back();
        postorder.pop_back();
        TreeNode* root=new TreeNode(val);

        auto f_root=find(inorder.begin(),inorder.end(),val);

        while (!postorder.empty()) {
            val=postorder.back();
            postorder.pop_back();

            auto f=find(inorder.begin(),inorder.end(),val);
            if (f>f_root) {
                root->right=new TreeNode(val);
            }
            else {
                root->left=new TreeNode(val);
            }
        }
    }
};
// @lc code=end

