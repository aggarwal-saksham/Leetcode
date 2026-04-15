/*
 * Problem #1038: Binary Search Tree to Greater Sum Tree
 * Difficulty: Medium
 * Submission: Try 1
 * status: Accepted
 * Language: cpp
 * Date: 3/22/2026, 12:40:23 AM
 * Link: https://leetcode.com/problems/binary-search-tree-to-greater-sum-tree/
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
    void bstToGstHelper(TreeNode* root, int& nodeSum) {
        // If root is null, make no changes.
        if (!root) {
            return;
        }

        bstToGstHelper(root->right, nodeSum);
        nodeSum += root->val;
        // Update the value of root.
        root->val = nodeSum;
        bstToGstHelper(root->left, nodeSum);
    }
    
    TreeNode* bstToGst(TreeNode* root) {
        int nodeSum = 0;
        bstToGstHelper(root, nodeSum);
        return root;
    }
};
