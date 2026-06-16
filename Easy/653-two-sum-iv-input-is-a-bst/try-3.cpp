/*
 * Problem #653: Two Sum IV - Input is a BST
 * Difficulty: Easy
 * Submission: Try 3
 * status: Accepted
 * Language: cpp
 * Date: 6/16/2026, 1:59:14 PM
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
    void pushleft(TreeNode *node, stack<TreeNode*> &st)
    {
        while (node)
        {
            st.push(node);
            node = node->left;
        }
    }
    void pushright(TreeNode *node, stack<TreeNode*> &st)
    {
        while (node)
        {
            st.push(node);
            node = node->right;
        }
    }
    TreeNode* findNextMin(stack<TreeNode*> &st){
        if(!st.empty()){
            TreeNode *temp = st.top();
            st.pop();
            pushleft(temp->right, st);
            return temp;
        }
        return NULL;
    }
    TreeNode* findNextMax(stack<TreeNode*> &st){
        if(!st.empty()){
            TreeNode *temp = st.top();
            st.pop();
            pushright(temp->left, st);
            return temp;
        }
        return NULL;
    }
    bool findTarget(TreeNode* root, int k) {
        stack<TreeNode*> st1;
        stack<TreeNode*> st2;
        pushleft(root, st1);
        pushright(root, st2);

        TreeNode* mn = findNextMin(st1);
        TreeNode* mx = findNextMax(st2);

        while (mn && mx && mn != mx){
            if(mn->val + mx->val == k) return true;
            else if(mn->val + mx->val < k) mn = findNextMin(st1);
            else mx = findNextMax(st2);
        }
        return false;
    }
};
