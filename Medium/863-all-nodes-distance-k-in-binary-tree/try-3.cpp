/*
 * Problem #863: All Nodes Distance K in Binary Tree
 * Difficulty: Medium
 * Submission: Try 3
 * status: Accepted
 * Language: cpp
 * Date: 6/13/2026, 12:44:03 AM
 * Link: https://leetcode.com/problems/all-nodes-distance-k-in-binary-tree/
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
    void storeAncestors(TreeNode* root, unordered_map<TreeNode*,TreeNode*> &ancestor){
        queue<TreeNode*> q;
        q.push(root);

        while(!q.empty()){
            TreeNode* n = q.front();
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
    vector<int> distanceK(TreeNode* root, TreeNode* target, int k) {
        unordered_map<TreeNode*,TreeNode*> ancestor;
        storeAncestors(root, ancestor);

        unordered_map<TreeNode*, bool> vis;

        queue<TreeNode*> q;
        q.push(target);
        vis[target] = 1;

        int d = 0;

        while(!q.empty()){
            int sz = q.size();
            if(d == k) break;

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
            d++;
        }

        vector<int> ans;
        while(!q.empty()){
            ans.push_back(q.front()->val);
            q.pop();
        }

        return ans;
    }
};
