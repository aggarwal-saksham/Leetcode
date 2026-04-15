/*
 * Problem #144: Binary Tree Preorder Traversal
 * Difficulty: Easy
 * Submission: Try 3
 * status: Accepted
 * Language: cpp
 * Date: 7/29/2025, 7:50:06 PM
 * Link: https://leetcode.com/problems/binary-tree-preorder-traversal/
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
    vector<int> preorderTraversal(TreeNode* root) {
        //morris traversal

        
        vector<int> preorder;
        TreeNode* curr = root;
        while(curr){
            
            if(!curr->left){
                preorder.push_back(curr->val);
                curr = curr->right;
            }
            else{

                TreeNode* prev = curr->left;
                while(prev->right && prev->right != curr){
                    prev = prev->right;
                }

                if(!prev->right){
                    prev->right = curr;
                    preorder.push_back(curr->val);
                    curr = curr->left;
                }
                else{//prev->right == curr
                    prev->right = NULL;
                    curr = curr->right;
                }
            }
        }
        return preorder;
    }
};
