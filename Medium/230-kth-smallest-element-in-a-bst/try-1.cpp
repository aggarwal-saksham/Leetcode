/*
 * Problem #230: Kth Smallest Element in a BST
 * Difficulty: Medium
 * Submission: Try 1
 * status: Accepted
 * Language: cpp
 * Date: 12/17/2024, 5:48:31 PM
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
        void inorder(TreeNode *root, vector<int> &arr)
        {
            if (!root) return;
            inorder(root->left, arr);
            arr.push_back(root->val);
            inorder(root->right, arr);
        }
        int kthSmallest(TreeNode *root, int k)
        {
            vector<int> arr;
            inorder(root, arr);
            //int n= arr.size();
            return arr[k - 1];
        }
};
