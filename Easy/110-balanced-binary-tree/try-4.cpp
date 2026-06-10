/*
 * Problem #110: Balanced Binary Tree
 * Difficulty: Easy
 * Submission: Try 4
 * status: Accepted
 * Language: cpp
 * Date: 6/10/2026, 9:33:59 PM
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
        if(lh == -1) return -1;

        int rh = maxDepth(root->right);
        if(rh == -1) return -1;

        if(abs(lh - rh) > 1) return -1;
        return 1 + max(lh, rh);
    }

    bool isBalanced(TreeNode* root) {
        if(!root) return true;
        


       return maxDepth(root) != -1;
    }
};
