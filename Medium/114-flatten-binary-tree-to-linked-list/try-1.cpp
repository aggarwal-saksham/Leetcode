/*
 * Problem #114: Flatten Binary Tree to Linked List
 * Difficulty: Medium
 * Submission: Try 1
 * status: Accepted
 * Language: cpp
 * Date: 6/13/2026, 1:49:42 PM
 * Link: https://leetcode.com/problems/flatten-binary-tree-to-linked-list/
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
        vector<int> ans;
        stack<TreeNode*> st;
        if(!root) return ans;

        st.push(root);
        while(!st.empty()){
            TreeNode* node = st.top();
            st.pop();

            ans.push_back(node->val);
            if(node->right) st.push(node->right);
            if(node->left) st.push(node->left);

        }
        return ans;
    }

    void flatten(TreeNode* root) {
       vector<int> preorder =  preorderTraversal(root);

       for(int i = 1; i < preorder.size(); i++){
        TreeNode* n = new TreeNode(preorder[i]);
        root->right = n;
        root->left = NULL;
        root= root->right; 
       }
       return;
    }
};
