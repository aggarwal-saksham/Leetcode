/*
 * Problem #199: Binary Tree Right Side View
 * Difficulty: Medium
 * Submission: Try 2
 * status: Accepted
 * Language: cpp
 * Date: 6/11/2026, 5:37:08 PM
 * Link: https://leetcode.com/problems/binary-tree-right-side-view/
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
    vector<int> rightSideView(TreeNode* root) {
        queue<TreeNode*> q;
        vector<int> ans;
        if(!root) return ans; 
        q.push(root);
        while(!q.empty()){
            int x = q.size();
            while(x > 1){
                TreeNode* node = q.front();
                q.pop();

                if(node->left) q.push(node->left);
                if(node->right) q.push(node->right);
                x--;
            }
            TreeNode* node = q.front();
            q.pop();
            ans.push_back(node->val);

            if(node->left) q.push(node->left);
            if(node->right) q.push(node->right);


        }
        return ans;
    }
};
