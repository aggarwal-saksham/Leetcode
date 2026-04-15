/*
 * Problem #863: All Nodes Distance K in Binary Tree
 * Difficulty: Medium
 * Submission: Try 2
 * status: Accepted
 * Language: cpp
 * Date: 7/26/2025, 5:15:44 PM
 * Link: https://leetcode.com/problems/all-nodes-distance-k-in-binary-tree/
 */

class Solution {
public:
    void solve(TreeNode* node, TreeNode* parent, map<TreeNode*, TreeNode*>& mpp) {
        if (!node)
            return;

        if (parent)
            mpp[node] = parent;
        solve(node->left, node, mpp);
        solve(node->right, node, mpp);
    }

    vector<int> distanceK(TreeNode* root, TreeNode* target, int k) {

        vector<int> ans;
        if (k == 0)
            return {target->val};

        map<TreeNode*, TreeNode*> parent;
        map<TreeNode*, bool> visited;
        solve(root, NULL, parent);

        queue<TreeNode*> q;
        q.push(target);
        int dist = 0;
        while (!q.empty()) {
            dist++;
            int sz = q.size();
            for (int i = 0; i < sz; ++i) {
                TreeNode* temp = q.front();
                q.pop();
                visited[temp] = true;

                if (temp->left && !visited[temp->left]) {
                    q.push(temp->left);
                    if (dist == k)
                        ans.push_back(temp->left->val);
                }
                if (temp->right && !visited[temp->right]) {
                    q.push(temp->right);
                    if (dist == k)
                        ans.push_back(temp->right->val);
                }
                if (parent[temp] && !visited[parent[temp]]) {
                    q.push(parent[temp]);
                    if (dist == k)
                        ans.push_back(parent[temp]->val);
                }
            }
            if (dist == k)
                break;
        }
        return ans;
    }
};
