/*
 * Problem #101: Symmetric Tree
 * Difficulty: Easy
 * Submission: Try 1
 * status: Accepted
 * Language: cpp
 * Date: 12/17/2024, 6:19:42 PM
 * Link: https://leetcode.com/problems/symmetric-tree/
 */

/**
 *Definition for a binary tree node.
 *struct TreeNode {
 *   int val;
 *   TreeNode * left;
 *   TreeNode * right;
 *   TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *   TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *   TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 *};
 */
class Solution
{
    public:
        bool checkSymm(TreeNode *left, TreeNode* right)
        {
            if(!left && !right) return true;
            if(!left || !right) return false;
            if(left->val != right->val) return false;
            return (checkSymm(left->right,right->left) &&
                    checkSymm(left->left, right->right));

        }
    bool isSymmetric(TreeNode *root)
    {
        if (!root->left && !root->right)
            return true;
        // if (root->left->val == root->right->val)
        //     return true;
        // if ((root->left->val != root->right->val) ||
        //     (root->left && !root->right) ||
        //     (!root->left && root->right))
        //     return false;

       //	TreeNode* temp = root;

        return checkSymm(root->left, root->right);
    }
};
