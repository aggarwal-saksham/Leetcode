/*
 * Problem #2583: Kth Largest Sum in a Binary Tree
 * Difficulty: Medium
 * Submission: Try 1
 * status: Accepted
 * Language: cpp
 * Date: 10/22/2024, 8:22:18 PM
 * Link: https://leetcode.com/problems/kth-largest-sum-in-a-binary-tree/
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
    long long kthLargestLevelSum(TreeNode* root, int k) {
        vector<long long> ans;
        queue<TreeNode*> q;
        q.push(root);
        while(!q.empty()){
            long long level = 0;
            int size = q.size();
            for(int i = 0; i < size; i++){
                TreeNode* node = q.front();
                q.pop();
                if(node->left) q.push(node->left);
                if(node->right) q.push(node->right);
                level += node->val;

            }
      
      
            ans.push_back(level);
        }
        sort(ans.begin(),ans.end());
        if(k <= ans.size()){
            return ans[ans.size() - k];
        }
        return -1;
    }
};
