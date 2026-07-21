/*
 * Problem #1315: Sum of Nodes with Even-Valued Grandparent
 * Difficulty: Medium
 * Submission: Try 1
 * status: Accepted
 * Language: cpp
 * Date: 7/21/2026, 10:01:17 PM
 * Link: https://leetcode.com/problems/sum-of-nodes-with-even-valued-grandparent/
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
    int ans = 0;
    int rec(TreeNode* root, int p, int gp){
        if(!root) return 0;
        if(gp % 2 == 0) ans += root->val;
        int l = rec(root->left, root->val, p);
        int r = rec(root->right, root->val, p);
        return 0;
    }
    int sumEvenGrandparent(TreeNode* root) {
        rec(root, -1, -1);
        return ans;
    }
};
