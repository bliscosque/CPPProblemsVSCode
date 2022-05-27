/*
 * @lc app=leetcode id=105 lang=cpp
 *
 * [105] Construct Binary Tree from Preorder and Inorder Traversal
 */

//20220527

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
    TreeNode* buildTree(vector<int>& preorder, int p1, int p2,vector<int>& inorder, int i1, int i2) {
        if (i1>i2 || p1>p2) {
            return nullptr;
        }
        int r=preorder[p1];
        TreeNode* root=new TreeNode(r);

        //busca no inoder o root anterior
        auto p=find(inorder.begin(),inorder.end(),r);
        int pos=p-inorder.begin();

        //recursao
        root->left=buildTree(preorder,p1,p1+pos-1,inorder,i1+1,i1+1+pos);
        root->right=buildTree(preorder,p1+pos+1,p2,inorder,i1+1+pos,i2);

        return root;
    }

    TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder) {
        int n=preorder.size();
        if (n==0) {
            return nullptr;
        }
        
        return buildTree(preorder,0,n-1,inorder,0,n-1);
    }
};
// @lc code=end

