/*
 * Problem #236: Lowest Common Ancestor of a Binary Tree
 * Difficulty: Medium
 * Submission: Try 4
 * status: Accepted
 * Language: cpp
 * Date: 6/12/2026, 2:14:43 PM
 * Link: https://leetcode.com/problems/lowest-common-ancestor-of-a-binary-tree/
 */

/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Solution {
public:
    bool getPath(TreeNode* root, vector<TreeNode*> &path, TreeNode* target){
    
        if (!root) return false;
        path.push_back(root);

        if (root == target) return true;

        if (getPath(root->left, path, target) || getPath(root->right, path, target)) return true;

        path.pop_back();
        return false;
    }
    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
        if(!root || root == p || root == q) return root;

        vector<TreeNode*> pathP;
        getPath(root, pathP, p);

        vector<TreeNode*> pathQ;
        getPath(root, pathQ, q);

        int i = 0;
        int j = 0;

        while(i <= pathP.size() - 1 && j <= pathQ.size() - 1 && pathP[i] == pathQ[j]){
            i++;
            j++;
        }

        return pathP[i - 1];


    }
};
