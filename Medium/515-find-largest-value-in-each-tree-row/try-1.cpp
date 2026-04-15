/*
 * Problem #515: Find Largest Value in Each Tree Row
 * Difficulty: Medium
 * Submission: Try 1
 * status: Accepted
 * Language: cpp
 * Date: 12/25/2024, 5:07:08 PM
 * Link: https://leetcode.com/problems/find-largest-value-in-each-tree-row/
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

        vector<int> largestValues(TreeNode *root)
        {
            vector<int> ans;
            if (root == NULL) return ans;
            queue<TreeNode*> q;
            q.push(root);
            while (!q.empty())
            {
                int size = q.size();
                vector<int> level;
                for (int i = 0; i < size; i++)
                {
                    TreeNode *node = q.front();
                    q.pop();
                    if (node->left) q.push(node->left);
                    if (node->right) q.push(node->right);
                    level.push_back(node->val);
                }

                ans.push_back(*max_element(level.begin(), level.end()));
            }
            return ans;
        }
};
