/*
 * Problem #173: Binary Search Tree Iterator
 * Difficulty: Medium
 * Submission: Try 2
 * status: Accepted
 * Language: cpp
 * Date: 7/30/2025, 3:00:18 PM
 * Link: https://leetcode.com/problems/binary-search-tree-iterator/
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
class BSTIterator
{
    public:
    stack<TreeNode*> st;
    BSTIterator(TreeNode *root)
    {
        pushleft(root);
    }

    int next()
    {
        TreeNode *temp = st.top();
        st.pop();
        pushleft(temp->right);
        return temp->val;
    }

    bool hasNext()
    {
        return (!st.empty());
    }
    void pushleft(TreeNode *node)
    {
        while (node)
        {
            st.push(node);
            node = node->left;
        }
    }
};

/**
 *Your BSTIterator object will be instantiated and called as such:
 *BSTIterator* obj = new BSTIterator(root);
 *int param_1 = obj->next();
 *bool param_2 = obj->hasNext();
 */
