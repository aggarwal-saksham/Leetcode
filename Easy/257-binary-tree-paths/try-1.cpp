/*
 * Problem #257: Binary Tree Paths
 * Difficulty: Easy
 * Submission: Try 1
 * status: Accepted
 * Language: cpp
 * Date: 7/25/2025, 3:58:38 PM
 * Link: https://leetcode.com/problems/binary-tree-paths/
 */

/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution {
public:
    void findPath(TreeNode* temp, vector<string> &ans, string &path){
        int len = path.length();
        path += to_string(temp->val) + "->";
        if(!temp->left && !temp->right){
            path = path.substr(0, path.length() - 2);
            ans.push_back(path);
        }
        else{
            if(temp->left){
                findPath(temp->left, ans, path);
            }
            if(temp->right){
                findPath(temp->right, ans, path);
            }

        }
        
       path.resize(len);
    }

    vector<string> binaryTreePaths(TreeNode* root) {
        vector<string> ans;
        string path = "";
        findPath(root, ans, path);
        return ans;
    }
};
