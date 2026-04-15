/*
 * Problem #145: Binary Tree Postorder Traversal
 * Difficulty: Easy
 * Submission: Try 1
 * status: Accepted
 * Language: cpp
 * Date: 10/2/2024, 10:37:17 PM
 * Link: https://leetcode.com/problems/binary-tree-postorder-traversal/
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
    void postorder(TreeNode* root, vector<int>& ans){
        TreeNode* temp = root;
        if(temp == NULL){
            return;
        }
        postorder(temp->left, ans);
        postorder(temp->right, ans);
        ans.push_back(temp->val);
    }
    vector<int> postorderTraversal(TreeNode* root) {
        vector<int> ans;
        postorder(root, ans);

        return ans;



        
    }
};
