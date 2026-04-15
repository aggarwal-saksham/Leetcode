/*
 * Problem #1008: Construct Binary Search Tree from Preorder Traversal
 * Difficulty: Medium
 * Submission: Try 4
 * status: Accepted
 * Language: cpp
 * Date: 7/30/2025, 3:08:43 AM
 * Link: https://leetcode.com/problems/construct-binary-search-tree-from-preorder-traversal/
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

    TreeNode* helper(vector<int>& preorder, int &i, int h) {
        if(i == preorder.size() || preorder[i] > h) return NULL;
        TreeNode* newN = new TreeNode(preorder[i++]);
        newN->left = helper(preorder, i, newN->val);
        newN->right = helper(preorder, i, h);
        return newN;        
        
    }
    TreeNode* bstFromPreorder(vector<int>& preorder) {
        int i = 0;
        return helper(preorder, i, INT_MAX);
    }
};
