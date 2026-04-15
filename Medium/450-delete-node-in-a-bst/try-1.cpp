/*
 * Problem #450: Delete Node in a BST
 * Difficulty: Medium
 * Submission: Try 1
 * status: Accepted
 * Language: cpp
 * Date: 12/17/2024, 2:28:52 AM
 * Link: https://leetcode.com/problems/delete-node-in-a-bst/
 */

/**
 *Definition for a binary tree node.
 *struct TreeNode {
 *    int val;
 *    TreeNode * left;
 *    TreeNode * right;
 *    TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *    TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left),
 *right(right) {}
 *};
 */
class Solution
{
    public:

        TreeNode* deleteNode(TreeNode *root, int key)
        {
            if (!root)
                return NULL;
           	// TreeNode* toDel = root;
            if (key < root->val)
            {
                root->left = deleteNode(root->left, key);
            }
            else if (key > root->val)
            {
                root->right = deleteNode(root->right, key);
            }
            else
            {

                if (root->right)
                {
                    TreeNode *r = root->right;
                    while (r->left)
                        r = r->left;
                    root->val = r->val;
                    //delete r;
                    root->right = deleteNode(root->right, r->val);
                }
                else if (root->left)
                {
                    TreeNode *l = root->left;
                    while (l->right)
                        l = l->right;
                    root->val = l->val;
                    //delete l;
                    root->left = deleteNode(root->left, l->val);
                }
                else
                {
                    delete root;
                    return NULL;
                }
            }
            return root;
        }
};
