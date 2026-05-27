/*
 * Problem #337: House Robber III
 * Difficulty: Medium
 * Submission: Try 1
 * status: Accepted
 * Language: cpp
 * Date: 5/13/2026, 11:40:00 PM
 * Link: https://leetcode.com/problems/house-robber-iii/
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
    int rob(TreeNode* root) {
        vector<int> options = travel(root);
        return max(options[0], options[1]);
    }

    vector<int> travel(TreeNode* root){
        if(root == NULL){
            return {0, 0};
        }

        auto left = travel(root->left);
        auto right = travel(root->right);

        vector<int> options(2, 0);

        options[0] = root->val + left[1] + right[1];
        options[1] = max(left[0], left[1]) + max(right[0], right[1]);

        return options;


    }
};
