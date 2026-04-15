/*
 * Problem #98: Validate Binary Search Tree
 * Difficulty: Medium
 * Submission: Try 1
 * status: Accepted
 * Language: cpp
 * Date: 10/30/2024, 5:32:50 PM
 * Link: https://leetcode.com/problems/validate-binary-search-tree/
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
        TreeNode* temp = root;
        if(!temp) return ans;
        while(true){
            if(temp){
            st.push(temp);
            temp = temp->left;
            }

            else{
                if(st.empty()) break;
                temp = st.top();
                st.pop();
                ans.push_back(temp->val);
                temp = temp->right;

            }


        }
        return ans;
        
    }
    bool isValidBST(TreeNode* root) {
        vector<int> ans;
        ans =  inorderTraversal(root);
        for(int i = 1; i < ans.size(); i++){
            if(ans[i] <= ans[i-1]) return false;
        }
        return true;
    }
};
