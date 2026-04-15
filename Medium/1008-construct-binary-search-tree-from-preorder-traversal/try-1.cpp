/*
 * Problem #1008: Construct Binary Search Tree from Preorder Traversal
 * Difficulty: Medium
 * Submission: Try 1
 * status: Accepted
 * Language: cpp
 * Date: 7/30/2025, 2:24:59 AM
 * Link: https://leetcode.com/problems/construct-binary-search-tree-from-preorder-traversal/
 */

/**
 *Definition for a binary tree node.
 *struct TreeNode {
 *   int val;
 *   TreeNode * left;
 *   TreeNode * right;
 *   TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *   TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *   TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left),
 *right(right) {}
 *};
 */
class Solution {
public:
    TreeNode* bstFromPreorder(vector<int>& preorder) {
        TreeNode* root = new TreeNode(preorder[0]);
        for (int i = 1; i < preorder.size(); i++) {
            TreeNode* temp = root;
            int p = preorder[i];
            TreeNode* newN = new TreeNode(p);
            while (true) {
                if (p < temp->val) {
                    if (temp->left)

                        temp = temp->left;

                    else {
                        temp->left = newN;
                        break;
                    }
                } 
                else {
                    if (temp->right)
                        temp = temp->right;
                    else {
                        temp->right = newN;
                        break;
                    }
                }
            }
        }
        return root;
    }
};
