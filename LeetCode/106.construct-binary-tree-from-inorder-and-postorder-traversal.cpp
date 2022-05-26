// @before-stub-for-debug-begin
#include <vector>
#include <string>
#include "commoncppproblem106.h"

using namespace std;
// @before-stub-for-debug-end

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

    //i2 and p2 is 1 passed of last eleme
    TreeNode* buildTreeRec(vector<int>& inorder, int i1, int i2, vector<int>& postorder, int p1, int p2) {
        if (i1>=i2 || p1>=p2) {
            return nullptr;
        }
        int r=postorder[p2-1];
        TreeNode* root=new TreeNode(r);

        int i;
        for (i=i1;i<=i2;i++) {
            if (inorder[i]==r) break;
        }
        int n_elem_l=i-i1;

        root->left=buildTreeRec(inorder,i1,i1+n_elem_l,postorder,p1,p1+n_elem_l);
        root->right=buildTreeRec(inorder,i1+n_elem_l+1,i2,postorder,p1+n_elem_l,p2-1);

        return root;

    }
    TreeNode* buildTree(vector<int>& inorder, vector<int>& postorder) {
        int n=inorder.size();
        if (n==0) return nullptr;
        return buildTreeRec(inorder,0,n,postorder,0,n);
    }
};
// @lc code=end

