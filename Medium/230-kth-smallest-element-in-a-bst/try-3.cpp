/*
 * Problem #230: Kth Smallest Element in a BST
 * Difficulty: Medium
 * Submission: Try 3
 * status: Accepted
 * Language: cpp
 * Date: 6/15/2026, 8:40:43 PM
 * Link: https://leetcode.com/problems/kth-smallest-element-in-a-bst/
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
        vector<int> ans;
        stack<TreeNode*> st;
        if(!root) return ans;
        TreeNode* node = root;
        while(true){
            if(node){
                st.push(node);
                node = node->left;
            }

            else{
                if(st.empty()) break;

                node = st.top();
                st.pop();

                ans.push_back(node->val);

                node = node->right;
            }

        }
        return ans;
    }
    int kthSmallest(TreeNode* root, int k) {
        vector<int> inorder = inorderTraversal(root);
        return inorder[k - 1];
    }
};
