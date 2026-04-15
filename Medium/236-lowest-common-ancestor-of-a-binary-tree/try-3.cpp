/*
 * Problem #236: Lowest Common Ancestor of a Binary Tree
 * Difficulty: Medium
 * Submission: Try 3
 * status: Accepted
 * Language: cpp
 * Date: 7/24/2025, 3:07:25 PM
 * Link: https://leetcode.com/problems/lowest-common-ancestor-of-a-binary-tree/
 */

class Solution {
public:
    bool findPath(vector<TreeNode*>& path, TreeNode* temp, TreeNode* node) {
        path.push_back(temp);
        if (temp == node) {
            return true;
        }

        if (temp->left && findPath(path, temp->left, node)) {
            return true;
        }
        if (temp->right && findPath(path, temp->right, node)) {
            return true;
        }

        path.pop_back();
        return false;
    }

    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
        TreeNode* f = root;
        if (p == f || q == f) {
            return f;
        }

        vector<TreeNode*> pathP;
        findPath(pathP, f, p);
        vector<TreeNode*> pathQ;
        findPath(pathQ, f, q);

        int i = 0;
        while(i < pathP.size() && i < pathQ.size() && pathP[i] == pathQ[i]){
            i++;
        }

        return pathP[i - 1];
    }
};

