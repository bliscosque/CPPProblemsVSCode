/*
 * @lc app=leetcode id=94 lang=cpp
 *
 * [94] Binary Tree Inorder Traversal
 */

 struct TreeNode {
     int val;
     TreeNode *left;
     TreeNode *right;
     TreeNode() : val(0), left(nullptr), right(nullptr) {}
     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 };
 #include<bits/stdc++.h>
 using namespace std;

// @lc code=start


class Solution {
public:
    vector<int> inorderTraversal(TreeNode* root) {
       vector<int> vi;
       if (root==nullptr) {
           return {};
       } 
       else {
            vector<int> l=inorderTraversal(root->left);
            for (auto i:l) {
                vi.push_back(i);
            }

            vi.push_back(root->val);
            
            vector<int> r=inorderTraversal(root->right);
            for (auto i:r) {
                vi.push_back(i);
            }
            return vi;
       }
    }
};
// @lc code=end

