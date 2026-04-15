/*
 * Problem #700: Search in a Binary Search Tree
 * Difficulty: Easy
 * Submission: Try 2
 * status: Accepted
 * Language: cpp
 * Date: 7/29/2025, 7:51:34 PM
 * Link: https://leetcode.com/problems/search-in-a-binary-search-tree/
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
    TreeNode* searchBST(TreeNode* root, int val) {

        while (root) {
            if (root->val < val)
                root = root->right;
            else if (root->val > val)
                root = root->left;
            else
                return root;
        }
        return NULL;
    }
};
