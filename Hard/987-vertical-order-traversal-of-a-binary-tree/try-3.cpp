/*
 * Problem #987: Vertical Order Traversal of a Binary Tree
 * Difficulty: Hard
 * Submission: Try 3
 * status: Accepted
 * Language: cpp
 * Date: 6/11/2026, 6:23:59 PM
 * Link: https://leetcode.com/problems/vertical-order-traversal-of-a-binary-tree/
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
    vector<vector<int>> verticalTraversal(TreeNode* root) {
        queue<tuple<TreeNode*, int, int>> q;
        map<int, map<int, multiset<int>>> nodes;

        q.push({root, 0, 0});
        while(!q.empty()){
            auto [n, v, l] = q.front();
            q.pop();

            nodes[v][l].insert(n->val);

            if(n->left) q.push({n->left, v - 1, l + 1});
            if(n->right) q.push({n->right, v + 1, l + 1});
        }

        vector<vector<int>> ans;
        for(auto it : nodes){
            vector<int> vertical;
            for(auto it2 : it.second){
                vertical.insert(vertical.end(), it2.second.begin(), it2.second.end());
            }
            ans.push_back(vertical);
        }
        return ans;
    }
};
