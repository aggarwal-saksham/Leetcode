/*
 * Problem #105: Construct Binary Tree from Preorder and Inorder Traversal
 * Difficulty: Medium
 * Submission: Try 1
 * status: Accepted
 * Language: cpp
 * Date: 2/8/2025, 9:23:01 PM
 * Link: https://leetcode.com/problems/construct-binary-tree-from-preorder-and-inorder-traversal/
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
        TreeNode* buildTree(vector<int> &preorder, vector<int> &inorder)
        {
            unordered_map<int, int> inMap;
            for (int i = 0; i < inorder.size(); i++)
            {
                inMap[inorder[i]] = i;
            }
            TreeNode *root = buildTreehelp(preorder, 0, preorder.size() - 1, inorder, 0, inorder.size() - 1, inMap);

            return root;
        }
    TreeNode* buildTreehelp(vector<int> &preorder, int preStart, int preEnd,
        vector<int> &inorder, int inStart, int inEnd, unordered_map<int, int> &inMap)
    {
       	
        if (preStart > preEnd || inStart > inEnd)
        {
            return NULL;
        }

       
        TreeNode *root = new TreeNode(preorder[preStart]);

       	
        int inRoot = inMap[root->val];

        int numsLeft = inRoot - inStart;

       	
        root->left = buildTreehelp(preorder, preStart + 1, preStart + numsLeft,
            inorder, inStart, inRoot - 1, inMap);

       	
        root->right = buildTreehelp(preorder, preStart + numsLeft + 1, preEnd,
            inorder, inRoot + 1, inEnd, inMap);

       	
        return root;
    }
};
