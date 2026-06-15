/*
 * Problem #450: Delete Node in a BST
 * Difficulty: Medium
 * Submission: Try 2
 * status: Accepted
 * Language: cpp
 * Date: 6/15/2026, 8:35:16 PM
 * Link: https://leetcode.com/problems/delete-node-in-a-bst/
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
    TreeNode* deleteNode(TreeNode* root, int key) {
        if(!root)
            return nullptr;

        if(key < root->val) {
            root->left = deleteNode(root->left, key);
        }
        else if(key > root->val) {
            root->right = deleteNode(root->right, key);
        }
        else {
            if(!root->left && !root->right) {
                delete root;
                return nullptr;
            }

            if(!root->left) {
                TreeNode* temp = root->right;
                delete root;
                return temp;
            }

            if(!root->right) {
                TreeNode* temp = root->left;
                delete root;
                return temp;
            }

            TreeNode* succ = root->right;

            while(succ->left)
                succ = succ->left;

            root->val = succ->val;
            root->right = deleteNode(root->right, succ->val);
        }

        return root;
    }
};
