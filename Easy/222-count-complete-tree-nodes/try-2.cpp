/*
 * Problem #222: Count Complete Tree Nodes
 * Difficulty: Easy
 * Submission: Try 2
 * status: Accepted
 * Language: cpp
 * Date: 6/13/2026, 1:42:32 AM
 * Link: https://leetcode.com/problems/count-complete-tree-nodes/
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
    int leftHeight(TreeNode* temp){
        int h = 0;
        while(temp){
            temp = temp->left;
            h++;
        }

        return h;
    }
    int rightHeight(TreeNode* temp){
        int h = 0;
        while(temp){
            temp = temp->right;
            h++;
        }

        return h;
    }
    int countNodes(TreeNode* root) {
        if(!root) return 0;

        int lh = leftHeight(root);
        int rh = rightHeight(root);

        if(lh == rh) return pow(2, lh) - 1;

        return countNodes(root->left) + countNodes(root->right) + 1;
    }
};
