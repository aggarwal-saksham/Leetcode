/*
 * Problem #145: Binary Tree Postorder Traversal
 * Difficulty: Easy
 * Submission: Try 4
 * status: Accepted
 * Language: cpp
 * Date: 6/9/2026, 7:16:00 PM
 * Link: https://leetcode.com/problems/binary-tree-postorder-traversal/
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
    vector<int> ans;
    void postorder(TreeNode* root){

        if(!root) return;
        postorder(root->left);
        postorder(root->right);
        ans.push_back(root->val);
        
    }
    vector<int> postorderTraversal(TreeNode* root) {
        postorder(root);
        return ans;
    }
};
