/*
 * Problem #101: Symmetric Tree
 * Difficulty: Easy
 * Submission: Try 2
 * status: Accepted
 * Language: cpp
 * Date: 6/11/2026, 12:37:44 AM
 * Link: https://leetcode.com/problems/symmetric-tree/
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
    bool isMirrorTree(TreeNode* p, TreeNode* q) {
        if(!p && !q) return true;
        if((!p || !q) || p->val != q->val) return false;

        return isMirrorTree(p->left, q->right) && isMirrorTree(p->right, q->left);
    }
    bool isSymmetric(TreeNode* root) {
        if(!root) return true;
        return isMirrorTree(root->left, root->right);
        
    }
};
