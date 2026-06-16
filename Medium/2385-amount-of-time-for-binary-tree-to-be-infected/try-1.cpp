/*
 * Problem #2385: Amount of Time for Binary Tree to Be Infected
 * Difficulty: Medium
 * Submission: Try 1
 * status: Accepted
 * Language: cpp
 * Date: 6/16/2026, 9:41:22 PM
 * Link: https://leetcode.com/problems/amount-of-time-for-binary-tree-to-be-infected/
 */

/**
 * Definition for a binary tree Treenode.
 * struct TreeTreeNode {
 *     int val;
 *     TreeTreeNode *left;
 *     TreeTreeNode *right;
 *     TreeTreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeTreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeTreeNode(int x, TreeTreeNode *left, TreeTreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution {
public:
    TreeNode* targetNode;
    
    void storeAncestors(TreeNode* root, unordered_map<TreeNode*,TreeNode*> &ancestor, int &target){
        queue<TreeNode*> q;
        q.push(root);

        while(!q.empty()){
            TreeNode* n = q.front();
            if(n->val == target) targetNode = n;
            q.pop();

            if(n->left){
                q.push(n->left);
                ancestor[n->left] = n;
            }
            if(n->right){
                q.push(n->right);
                ancestor[n->right] = n;
            }
        }
    }
    int amountOfTime(TreeNode* root, int start) {
        unordered_map<TreeNode*,TreeNode*> ancestor;
        storeAncestors(root, ancestor, start);        
        
        unordered_map<TreeNode*, bool> vis;

        queue<TreeNode*> q;
        q.push(targetNode);
        vis[targetNode] = 1;

        int time = 0;

        while(!q.empty()){
            int sz = q.size();

            for(int i = 0; i < sz; i++){
                TreeNode* curr = q.front();
                q.pop();

                if(curr->left && !vis[curr->left]){
                    q.push(curr->left);
                    vis[curr->left] = 1;
                }
                if(curr->right && !vis[curr->right]){
                    q.push(curr->right);
                    vis[curr->right] = 1;
                }
                if(ancestor[curr] && !vis[ancestor[curr]]){
                    q.push(ancestor[curr]);
                    vis[ancestor[curr]] = 1;
                }
            }
            time++;
        }
        
        return time - 1;
    }
};
