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

class Solution {
public:
    vector<int> preorderTraversal(TreeNode* root) {
       vector<int> vi;
       if (root==nullptr) {
           return {};
       } 
       else {
            vi.push_back(root->val);
            vector<int> l=preorderTraversal(root->left);
            vector<int> r=preorderTraversal(root->right);
            for (auto i:l) {
                vi.push_back(i);
            }
            for (auto i:r) {
                vi.push_back(i);
            }
            return vi;
       }
    }
};