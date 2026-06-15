/*
 * Problem #701: Insert into a Binary Search Tree
 * Difficulty: Medium
 * Submission: Try 3
 * status: Accepted
 * Language: cpp
 * Date: 6/15/2026, 3:33:23 PM
 * Link: https://leetcode.com/problems/insert-into-a-binary-search-tree/
 */


class Solution {
public:
    TreeNode* insertIntoBST(TreeNode* root, int x) {
        TreeNode* newN = new TreeNode(x);
        if (!root) {
            return newN;
        }
        TreeNode* par = nullptr;
        TreeNode* temp = root;

        while (temp) {
            par = temp;

            if (temp->val > x) {
                temp = temp->left;
            } else {
                temp = temp->right;
            }
        }
        if (x < par->val)
            par->left = newN;
        else
            par->right = newN;
        return root;
    }
};
