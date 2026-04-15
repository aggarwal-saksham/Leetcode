/*
 * Problem #1261: Find Elements in a Contaminated Binary Tree
 * Difficulty: Medium
 * Submission: Try 1
 * status: Accepted
 * Language: cpp
 * Date: 2/21/2025, 1:55:58 PM
 * Link: https://leetcode.com/problems/find-elements-in-a-contaminated-binary-tree/
 */

/**
 *Definition for a binary tree node.
 *struct TreeNode {
 *   int val;
 *   TreeNode * left;
 *   TreeNode * right;
 *   TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *   TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *   TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left),
 *right(right) {}
 *};
 */
class FindElements {
public:
    TreeNode* root;
    void recoverTree(TreeNode* node) {
        if (!node)
            return;
        int x = node->val;
        if (node->left) {
            node->left->val = 2 * x + 1;
            recoverTree(node->left);
        }
        if (node->right) {
            node->right->val = 2 * x + 2;
            recoverTree(node->right);
        }
    }
    FindElements(TreeNode* root_) {
        root = root_;
        root->val = 0;
        recoverTree(root);
    }

    bool findHelper(int target, TreeNode* root) {
        if (!root)
            return false;
        if (root->val == target)
            return true;
        return (findHelper(target, root->left) ||
                findHelper(target, root->right));
    }
    bool find(int target) { 
        return findHelper(target, root); 
    }
};

/**
 *Your FindElements object will be instantiated and called as such:
 *FindElements* obj = new FindElements(root);
 *bool param_1 = obj->find(target);
 */
