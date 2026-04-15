/*
 * Problem #653: Two Sum IV - Input is a BST
 * Difficulty: Easy
 * Submission: Try 1
 * status: Accepted
 * Language: cpp
 * Date: 7/30/2025, 3:21:07 AM
 * Link: https://leetcode.com/problems/two-sum-iv-input-is-a-bst/
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
     vector<int> inorderTraversal(TreeNode* root) {
        //morris traversal        
        vector<int> inorder;
        TreeNode* curr = root;
        while(curr){
            
            if(!curr->left){
                inorder.push_back(curr->val);
                curr = curr->right;
            }
            else{

                TreeNode* prev = curr->left;
                while(prev->right && prev->right != curr){
                    prev = prev->right;
                }

                if(!prev->right){
                    prev->right = curr;
                    curr = curr->left;
                }
                else{//prev->right == curr
                    prev->right = NULL;
                    inorder.push_back(curr->val);
                    curr = curr->right;
                }
            }
        }
        return inorder;
    }
    bool findTarget(TreeNode* root, int k) {
        vector<int> inorder = inorderTraversal(root);
        int l = 0, r = inorder.size() - 1;
        while(l < r){
            if(inorder[l] + inorder[r] == k) return true;
            else if (inorder[l] + inorder[r] < k){
                l++;
            }
            else r--;
        }
        return false;
    }
};
