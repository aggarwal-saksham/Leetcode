/*
 * Problem #99: Recover Binary Search Tree
 * Difficulty: Medium
 * Submission: Try 1
 * status: Accepted
 * Language: cpp
 * Date: 6/16/2026, 2:45:18 PM
 * Link: https://leetcode.com/problems/recover-binary-search-tree/
 */

/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left),
 * right(right) {}
 * };
 */
class Solution {
public:
    stack<TreeNode*> st;

    void pushleft(TreeNode* node) {
        while (node) {
            st.push(node);
            node = node->left;
        }
    }

    bool hasNext() { 
        return !st.empty();
    }

    TreeNode* next() {
        TreeNode* temp = st.top();
        st.pop();
        pushleft(temp->right);
        return temp;
    }
    void recoverTree(TreeNode* root) {
        pushleft(root);

        TreeNode *first = NULL, *middle = NULL, *last = NULL;

        TreeNode* prev = next();

        while (hasNext()) {
            TreeNode* curr = next();

            if (prev->val > curr->val) {
                if (!first) {
                    first = prev;
                    middle = curr;
                } else {
                    last = curr;
                }
            }

            prev = curr;
        }

        if (last)
            swap(first->val, last->val);
        else
            swap(first->val, middle->val);
    }
};
