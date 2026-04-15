/*
 * Problem #662: Maximum Width of Binary Tree
 * Difficulty: Medium
 * Submission: Try 1
 * status: Accepted
 * Language: cpp
 * Date: 12/19/2024, 2:35:29 PM
 * Link: https://leetcode.com/problems/maximum-width-of-binary-tree/
 */

/**
 *Definition for a binary tree node.
 *struct TreeNode {
 *  int val;
 *  TreeNode * left;
 *  TreeNode * right;
 *  TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *  TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *  TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left),
 *right(right) {}
 *};
 */
class Solution
{
    public:
        int widthOfBinaryTree(TreeNode *root)
        {
            queue<pair<TreeNode*, int>> q;
            q.push({ root,0 });
            int maxWidth = 0;
            while (!q.empty())
            {
                int size = q.size();
                int mini = q.front().second;
                int first, last;
                for (int i = 0; i < size; i++)
                {
                    int currId = q.front().second - mini;
                    TreeNode *node = q.front().first;
                    q.pop();
                    if (i == 0) first = currId;
                    if (i == size - 1) last = currId;
                    if (node->left)
                    {
                        q.push({ node->left, (long long)2 * currId + 1 });
                    }
                    if (node->right)
                    {
                        q.push({ node->right, (long long)2 * currId + 2 });
                    }
                }
                maxWidth = max(maxWidth, last - first + 1);
            }
            return maxWidth;
        }
};
