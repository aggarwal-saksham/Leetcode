/*
 * Problem #124: Binary Tree Maximum Path Sum
 * Difficulty: Hard
 * Submission: Try 1
 * status: Accepted
 * Language: cpp
 * Date: 10/4/2024, 6:13:51 PM
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
    int maxPathDepth(TreeNode* node, int &maxi){
        if(!node) return 0;

        int left = max(0,maxPathDepth(node->left, maxi));
        int right = max(0,maxPathDepth(node->right, maxi));

        maxi = max(maxi, left + right + node->val);

        return max(left, right) + node->val;

        
    }
    int maxPathSum(TreeNode* root) {

        int maxi = INT_MIN;
        maxPathDepth(root,maxi);
        return maxi;
        
    }
};
