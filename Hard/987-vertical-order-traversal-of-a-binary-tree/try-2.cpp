/*
 * Problem #987: Vertical Order Traversal of a Binary Tree
 * Difficulty: Hard
 * Submission: Try 2
 * status: Accepted
 * Language: cpp
 * Date: 7/21/2025, 1:18:39 AM
 * Link: https://leetcode.com/problems/vertical-order-traversal-of-a-binary-tree/
 */

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
    vector<vector<int>> verticalTraversal(TreeNode* root) {
        map<int, map<int, multiset<int>>> mpp;
        //vertical->horizontal->node val in asc order

        queue<pair<TreeNode*, pair<int, int>>> q;
        //node, vertical, horizontal

        q.push({root, {0, 0}});

        while(!q.empty()){
            int size = q.size();
            for (int i = 0; i < size; i++) {
                TreeNode* node = q.front().first;
                int vt = q.front().second.first;
                int hz = q.front().second.second;
                q.pop();

                if (node->left)
                    q.push({node->left, {vt - 1, hz + 1}});
                if (node->right)
                    q.push({node->right, {vt + 1, hz + 1}});
                mpp[vt][hz].insert(node->val);
            }
        }
        vector<vector<int>> ans;
        for(auto i : mpp){
            vector<int> level;
            for(auto j : i.second){
                for(auto k : j.second){
                    level.push_back(k);
                }
            }
            ans.push_back(level);
        }
        return ans;
    }
};
