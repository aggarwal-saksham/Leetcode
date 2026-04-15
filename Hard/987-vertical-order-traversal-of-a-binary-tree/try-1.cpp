/*
 * Problem #987: Vertical Order Traversal of a Binary Tree
 * Difficulty: Hard
 * Submission: Try 1
 * status: Accepted
 * Language: cpp
 * Date: 10/28/2024, 9:08:02 PM
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
        map<int,map<int,multiset<int>>> nodes;
        queue<pair<TreeNode*,pair<int, int>>> q;
        q.push({root,{0,0}});
        while(!q.empty()){
            auto p = q.front();
            q.pop();
            TreeNode* node = p.first;
            int x = p.second.first;
            int y = p.second.second;
            nodes[x][y].insert(node->val);
            if(node->left){
                q.push({node->left,{x-1, y+1}});
            }
            if(node->right){
                q.push({node->right,{x+1, y+1}});
            }
        }
        vector<vector<int>> ans;
        for(auto p : nodes){
            vector<int> col;
            for(auto s : p.second){
                for(auto it : s.second){
                    col.push_back(it);
                }
            }
            ans.push_back(col);
        }
        return ans;
    }
};
