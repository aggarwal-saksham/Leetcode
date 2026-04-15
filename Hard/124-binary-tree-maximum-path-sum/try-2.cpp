/*
 * Problem #124: Binary Tree Maximum Path Sum
 * Difficulty: Hard
 * Submission: Try 2
 * status: Accepted
 * Language: cpp
 * Date: 9/4/2025, 3:54:42 PM
 * Link: https://leetcode.com/problems/binary-tree-maximum-path-sum/
 */

/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left),
 * right(right) {}
 * };
 */
class Solution {
public:
    int maxi = INT_MIN;

    int maxPathDepth(TreeNode* node) {
        if (!node)
            return 0;

        int left = max(0, maxPathDepth(node->left));
        int right = max(0, maxPathDepth(node->right));

        maxi = max(maxi, left + right + node->val);

        return max(left, right) + node->val;
    }

    int maxPathSum(TreeNode* root) {
        maxPathDepth(root);
        return maxi;
    }
};
