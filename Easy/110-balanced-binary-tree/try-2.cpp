/*
 * Problem #110: Balanced Binary Tree
 * Difficulty: Easy
 * Submission: Try 2
 * status: Accepted
 * Language: cpp
 * Date: 7/18/2025, 2:35:51 PM
 * Link: https://leetcode.com/problems/balanced-binary-tree/
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
     int maxDepthDiff(TreeNode* root) {
        if(!root) return 0;

        int lh = maxDepthDiff(root->left);
        int rh = maxDepthDiff(root->right);
        if(lh == -1 || rh == -1) return -1;
        if(abs(lh-rh) > 1) return -1;

        return 1 + max(lh,rh);
        
    }
    bool isBalanced(TreeNode* root) {
    
        if(maxDepthDiff(root) == -1) return false;
        return true;
    }
};
