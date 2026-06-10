/*
 * Problem #104: Maximum Depth of Binary Tree
 * Difficulty: Easy
 * Submission: Try 4
 * status: Accepted
 * Language: cpp
 * Date: 6/10/2026, 1:38:52 PM
 * Link: https://leetcode.com/problems/maximum-depth-of-binary-tree/
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
    int maxH(TreeNode* root, int height){
        if(!root) return height;

        return max(maxH(root->left, height + 1), maxH(root->right, height + 1));
    }
public:
    int maxDepth(TreeNode* root) {
        if(!root) return 0;
        if(!root->left && !root->right) return 1;

        return 1 + max(maxH(root->left, 0), maxH(root->right, 0));
    }
};
