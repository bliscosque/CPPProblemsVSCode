// @before-stub-for-debug-begin
#include <bits/stdc++.h>
#include <string>

using namespace std;
// @before-stub-for-debug-end

/*
 * @lc app=leetcode id=102 lang=cpp
 *
 * [102] Binary Tree Level Order Traversal
 */
// #include <bits/stdc++.h>
// using namespace std;

//  struct TreeNode {
//      int val;
//      TreeNode *left;
//      TreeNode *right;
//      TreeNode() : val(0), left(nullptr), right(nullptr) {}
//      TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
//      TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
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
    vector<vector<int>> levelOrder(TreeNode* root) {
        queue<pair<TreeNode*, int>> q;
        vector<vector<int>> ans;
        TreeNode *tmp=root;
        if (tmp!=nullptr) q.push({tmp,0});
        int level=0; 
        while (!q.empty()) {
            pair<TreeNode*, int> pti=q.front();
            q.pop();

            tmp=pti.first;
            int level=pti.second;
            
            while (ans.size() <= level) {
                ans.push_back(vector<int>());
            }
            ans[level].push_back(tmp->val);
            if (tmp && tmp->left) {
                q.push({tmp->left,level+1});
            }
            if (tmp && tmp->right) {
                q.push({tmp->right,level+1});
            }
        }
        return ans;
    }
};
// @lc code=end

