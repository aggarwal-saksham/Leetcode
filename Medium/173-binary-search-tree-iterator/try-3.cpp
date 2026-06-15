/*
 * Problem #173: Binary Search Tree Iterator
 * Difficulty: Medium
 * Submission: Try 3
 * status: Accepted
 * Language: cpp
 * Date: 6/16/2026, 1:49:54 AM
 * Link: https://leetcode.com/problems/binary-search-tree-iterator/
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
class BSTIterator {
    void inorderTraversal(TreeNode* root, vector<int> &inorder) {
        
        stack<TreeNode*> st;
        if(!root) return ;
        TreeNode* node = root;
        while(true){
            if(node){
                st.push(node);
                node = node->left;
            }

            else{
                if(st.empty()) break;

                node = st.top();
                st.pop();

                inorder.push_back(node->val);

                node = node->right;
            }

        }
        return;
    }
public:
    vector<int> inorder;
    int i;
    BSTIterator(TreeNode* root) {
        inorderTraversal(root, inorder);
        i = -1;
    }
    
    int next() {
        i++;
        return inorder[i];
    }
    
    bool hasNext() {
        return (i + 1) < inorder.size();
    }
};

/**
 * Your BSTIterator object will be instantiated and called as such:
 * BSTIterator* obj = new BSTIterator(root);
 * int param_1 = obj->next();
 * bool param_2 = obj->hasNext();
 */
