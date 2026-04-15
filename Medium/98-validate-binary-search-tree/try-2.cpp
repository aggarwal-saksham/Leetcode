/*
 * Problem #98: Validate Binary Search Tree
 * Difficulty: Medium
 * Submission: Try 2
 * status: Accepted
 * Language: cpp
 * Date: 7/29/2025, 8:20:50 PM
 * Link: https://leetcode.com/problems/validate-binary-search-tree/
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
    bool helper(TreeNode* temp, long long l, long long h) {
        if (!temp)
            return true;
        if (temp->val >= h || temp->val <= l)
            return false;
        return (helper(temp->left, l, temp->val) &&
                helper(temp->right, temp->val, h));
    }
    bool isValidBST(TreeNode* root) { 
        return helper(root, LLONG_MIN, LLONG_MAX); 
    }
};
