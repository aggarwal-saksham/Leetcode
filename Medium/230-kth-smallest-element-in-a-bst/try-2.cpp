/*
 * Problem #230: Kth Smallest Element in a BST
 * Difficulty: Medium
 * Submission: Try 2
 * status: Accepted
 * Language: cpp
 * Date: 7/29/2025, 3:34:10 AM
 * Link: https://leetcode.com/problems/kth-smallest-element-in-a-bst/
 */

/**
 *Definition for a binary tree node.
 *struct TreeNode {
 *    int val;
 *    TreeNode * left;
 *    TreeNode * right;
 *    TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *    TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 *};
 */
class Solution
{
    public:
        void inorder(TreeNode *root, int& el, int& cnt, int k)
        {
            if (!root) return;
            inorder(root->left, el, cnt, k);
            cnt++;
            if(cnt == k) {
                el = root->val;
                return;
            }
            inorder(root->right, el, cnt, k);
        }
        int kthSmallest(TreeNode *root, int k)
        {
            int el = -1;
            int cnt = 0;
            inorder(root, el, cnt, k);
            //int n= arr.size();
            return el;
        }
};
