/*
 * Problem #653: Two Sum IV - Input is a BST
 * Difficulty: Easy
 * Submission: Try 2
 * status: Accepted
 * Language: cpp
 * Date: 7/31/2025, 12:39:41 AM
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
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left),
 * right(right) {}
 * };
 */
class Solution {
public:
    stack<TreeNode*> st1, st2;
    int next() {
        TreeNode* temp = st1.top();
        st1.pop();
        pushleft(temp->right);
        return temp->val;
    }
    int before() {
        TreeNode* temp = st2.top();
        st2.pop();
        pushright(temp->left);
        return temp->val;
    }
    void pushleft(TreeNode* node) {
        while (node) {
            st1.push(node);
            node = node->left;
        }
    }
    void pushright(TreeNode* node) {
        while (node) {
            st2.push(node);
            node = node->right;
        }
    }
    bool findTarget(TreeNode* root, int k) {
        if (!root)
            return false;

        pushleft(root);
        pushright(root);

        int i = next();
        int j = before();

        while (i < j) {
            if (i + j == k)
                return true;
            else if (i + j < k)
                i = next();
            else
                j = before();
        }

        return false;
    }
};
