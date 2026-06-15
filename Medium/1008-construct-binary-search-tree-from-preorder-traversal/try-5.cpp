/*
 * Problem #1008: Construct Binary Search Tree from Preorder Traversal
 * Difficulty: Medium
 * Submission: Try 5
 * status: Accepted
 * Language: cpp
 * Date: 6/16/2026, 1:04:54 AM
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
    TreeNode* builder(vector<int>& preorder, int &idx, int uprBound){
        if(idx == preorder.size() || preorder[idx] > uprBound) return NULL; 
        TreeNode* root = new TreeNode(preorder[idx++]);
        root->left = builder(preorder, idx, root->val);
        root->right = builder(preorder, idx, uprBound);
        return root;
    }
    TreeNode* bstFromPreorder(vector<int>& preorder) {
        int idx = 0;
        return builder(preorder, idx, INT_MAX);
    }
};
