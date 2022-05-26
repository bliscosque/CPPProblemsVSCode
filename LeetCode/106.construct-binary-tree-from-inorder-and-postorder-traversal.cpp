/*
 * @lc app=leetcode id=106 lang=cpp
 *
 * [106] Construct Binary Tree from Inorder and Postorder Traversal
 */

//20220524 - 1
//20220525 - 2

// #include <bits/stdc++.h>
// using namespace std;

// struct TreeNode {
//     int val;
//     TreeNode *left;
//     TreeNode *right;
//     TreeNode() : val(0), left(nullptr), right(nullptr) {}
//     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
//     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
// };

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
    TreeNode* buildTreeRec(vector<int>& inorder, int i1, int i2, vector<int>& postorder, int p1, int p2) {
        int r=postorder[p2];
        TreeNode* root=new TreeNode(r);

        int i;
        for (i=i1;i<=i2;i++) {
            if (inorder[i]==p2) break;
        }
        int n_elem=i1-i;
        if (n_elem>=1) {
            root->left=buildTreeRec(inorder,i1,i-1,postorder,p1,p1+n_elem);
            root->right=buildTreeRec(inorder,i+1,i,postorder,p1+n_elem,p2);
        }
        return root;

    }
    TreeNode* buildTree(vector<int>& inorder, vector<int>& postorder) {
        int n=inorder.size();
        return buildTreeRec(inorder,0,n-1,postorder,0,n-1);
    }
};
// @lc code=end

