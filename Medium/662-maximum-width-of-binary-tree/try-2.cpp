/*
 * Problem #662: Maximum Width of Binary Tree
 * Difficulty: Medium
 * Submission: Try 2
 * status: Accepted
 * Language: cpp
 * Date: 6/12/2026, 3:31:33 PM
 * Link: https://leetcode.com/problems/maximum-width-of-binary-tree/
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
    int widthOfBinaryTree(TreeNode* root) {
        queue<pair<TreeNode*, int>> q;
        int ans = -1e9;

        q.push({root, 0});
        while (!q.empty()) {
            int sz = q.size();
            int mini = q.front().second;

            int first = 0, last = 0;
            for (int i = 0; i < sz; i++) {
                auto [n, id] = q.front();
                q.pop();

                int normalised_id = id - mini;

                if (i == 0)
                    first = normalised_id;
                if (i == sz - 1)
                    last = normalised_id;

                if (n->left)
                    q.push({n->left, (long long)2 * normalised_id + 1});
                if (n->right)
                    q.push({n->right, (long long)2 * normalised_id + 2});
            }
            ans = max(ans, last - first + 1);
        }
        return ans;
    }
};
