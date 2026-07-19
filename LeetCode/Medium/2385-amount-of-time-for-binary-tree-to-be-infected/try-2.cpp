/*
 * Problem #2385: Amount of Time for Binary Tree to Be Infected
 * Difficulty: Medium
 * Submission: Try 2
 * status: Accepted
 * Language: cpp
 * Date: 7/18/2026, 9:19:50 PM
 * Link: https://leetcode.com/problems/amount-of-time-for-binary-tree-to-be-infected/
 */

class Solution {
public:
    void inorder(TreeNode* root, unordered_map<TreeNode*, TreeNode*>& parent, int start,
                 TreeNode* &startNode) {
        if (!root)
            return;
        inorder(root->left, parent, start, startNode);
        if (root->val == start)
            startNode = root;
        if (root->left)
            parent[root->left] = root;
        if (root->right)
            parent[root->right] = root;
        inorder(root->right, parent, start, startNode);
    }
    int amountOfTime(TreeNode* root, int start) {
        unordered_map<TreeNode*, TreeNode*> parent;
        TreeNode* startNode;
        inorder(root, parent, start, startNode);

        queue<TreeNode*> q;
        unordered_map<TreeNode*, bool> vis;
        q.push(startNode);
        vis[startNode] = 1;

        int mins = 0;

        while(!q.empty()){
            int sz = q.size();

            while(sz--){
                TreeNode* n = q.front();
                q.pop();
                if(n->left && !vis[n->left]){
                    vis[n->left] = 1;
                    q.push(n->left);
                } 
                if(n->right && !vis[n->right]){
                    vis[n->right] = 1;
                    q.push(n->right);
                } 
                if(parent.count(n) && !vis[parent[n]]){
                    vis[parent[n]] = 1;
                    q.push(parent[n]);
                }
            }
            if(!q.empty()) mins++;
        }
        return mins;
    }
};
