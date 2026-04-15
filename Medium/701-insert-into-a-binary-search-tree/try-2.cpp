/*
 * Problem #701: Insert into a Binary Search Tree
 * Difficulty: Medium
 * Submission: Try 2
 * status: Accepted
 * Language: cpp
 * Date: 7/29/2025, 7:54:45 PM
 * Link: https://leetcode.com/problems/insert-into-a-binary-search-tree/
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
    TreeNode* insertIntoBST(TreeNode* root, int val) {
        TreeNode* newN = new TreeNode(val);
        if(!root) return newN;
        TreeNode* temp = root;
        while(temp){
            if(temp->val < val){
                if(temp->right) temp = temp->right;
                else {
                    temp->right = newN;
                    break;
                }
            }
            else {
                if(temp->left) temp = temp->left;
                else{
                    temp->left = newN;
                    break;
                }
            }
        }

        return root;
    }
};
