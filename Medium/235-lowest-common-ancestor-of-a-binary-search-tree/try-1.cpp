/*
 * Problem #235: Lowest Common Ancestor of a Binary Search Tree
 * Difficulty: Medium
 * Submission: Try 1
 * status: Accepted
 * Language: cpp
 * Date: 12/18/2024, 11:56:10 PM
 * Link: https://leetcode.com/problems/lowest-common-ancestor-of-a-binary-search-tree/
 */

/**
 *Definition for a binary tree node.
 *struct TreeNode {
 *    int val;
 *    TreeNode * left;
 *    TreeNode * right;
 *    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 *};
 */

class Solution
{
    public:
        bool path(TreeNode *root, vector<TreeNode*> &arr, TreeNode *target)
        {
            if (!root) return false;
            arr.push_back(root);
            if (root == target) return true;
            if (path(root->left, arr, target) || path(root->right, arr, target)) return true;
            arr.pop_back();
            return false;
        }
    vector<TreeNode*> path_sol(TreeNode *root, TreeNode *target)
    {
        vector<TreeNode*> ans;
        if (!root) return ans;
        path(root, ans, target);
        return ans;
    }
    TreeNode* lowestCommonAncestor(TreeNode *root, TreeNode *p, TreeNode *q)
    {
        vector<TreeNode*> p_path = path_sol(root, p);
        vector<TreeNode*> q_path = path_sol(root, q);
        int n = min(p_path.size(), q_path.size());
       	// int i = 0;
       	//cout<<p_path;
       	//cout<<q_path;
        TreeNode *lca = nullptr;

        for (int i = 0; i < n; i++)
        {
            if (p_path[i] == q_path[i])
            {
                lca = p_path[i];
            }
            else
            {
                break;
            }
        }
        return lca;
    }
};
