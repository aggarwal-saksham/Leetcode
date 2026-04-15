/*
 * Problem #110: Balanced Binary Tree
 * Difficulty: Easy
 * Submission: Try 1
 * status: Accepted
 * Language: cpp
 * Date: 10/3/2024, 11:11:55 PM
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
     int maxDepth(TreeNode* root) {
        if(!root) return 0;

        int lh = maxDepth(root->left);
        int rh = maxDepth(root->right);

        return 1 + max(lh,rh);
        
    }
    bool isBalanced(TreeNode* root) {
        if(!root) return true;

        int leftDepth = maxDepth(root->left);
        int rightDepth = maxDepth(root->right);

    
         if (abs(leftDepth - rightDepth) > 1) {
            return false;
            }
           return {isBalanced(root->left) && isBalanced(root->right)};


        
    }
};
