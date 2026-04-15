/*
 * Problem #235: Lowest Common Ancestor of a Binary Search Tree
 * Difficulty: Medium
 * Submission: Try 3
 * status: Accepted
 * Language: cpp
 * Date: 7/29/2025, 8:21:47 PM
 * Link: https://leetcode.com/problems/lowest-common-ancestor-of-a-binary-search-tree/
 */

/**
 *Definition for a binary tree node.
 *struct TreeNode {
 *    int val;
 *    TreeNode * left;
 *    TreeNode * right;
 *    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 *};
 */

class Solution
{
    public:
        TreeNode* lowestCommonAncestor(TreeNode *root, TreeNode *p, TreeNode *q)
        {
            while (root)
            {
                if (p->val > root->val && q->val > root->val)
                {
                    root = root->right;
                }
                else if (p->val < root->val && q->val < root->val)
                {
                    root = root->left;
                }
                else
                    return root;
            }
            return root;
        }
};
