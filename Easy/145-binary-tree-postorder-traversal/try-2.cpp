/*
 * Problem #145: Binary Tree Postorder Traversal
 * Difficulty: Easy
 * Submission: Try 2
 * status: Accepted
 * Language: cpp
 * Date: 10/3/2024, 1:23:38 PM
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
    vector<int> postorderTraversal(TreeNode* root) {
        TreeNode* temp = root;
        vector<int> ans;
        if(!temp) return ans;
        stack<TreeNode*> st1;
        stack<TreeNode*> st2;
        st1.push(temp);
        while(!st1.empty()){
            temp = st1.top();
            st1.pop();
            st2.push(temp);
            if(temp->left) st1.push(temp->left);
            if(temp->right) st1.push(temp->right);
        }
        while(!st2.empty()){
            temp = st2.top();
            ans.push_back(temp->val);
            st2.pop();
        }
        return ans;
        
    }
}; 
