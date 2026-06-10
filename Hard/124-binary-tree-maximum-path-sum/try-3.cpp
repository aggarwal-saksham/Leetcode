/*
 * Problem #124: Binary Tree Maximum Path Sum
 * Difficulty: Hard
 * Submission: Try 3
 * status: Accepted
 * Language: cpp
 * Date: 6/10/2026, 11:20:31 PM
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
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution {
public:
    int maxPath(TreeNode* root, int &pathSum) {
        if (!root)
            return 0;
        int l = max(0, maxPath(root->left, pathSum));
        int r = max(0, maxPath(root->right, pathSum));

        pathSum = max(pathSum, l + r + root->val);

        return root->val + max(l, r);
    }

    int maxPathSum(TreeNode* root) {
        int pathSum = INT_MIN;
        maxPath(root, pathSum);
        return pathSum;
    }
};
