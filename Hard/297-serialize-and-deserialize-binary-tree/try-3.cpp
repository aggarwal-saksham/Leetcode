/*
 * Problem #297: Serialize and Deserialize Binary Tree
 * Difficulty: Hard
 * Submission: Try 3
 * status: Accepted
 * Language: cpp
 * Date: 6/13/2026, 2:08:31 AM
 * Link: https://leetcode.com/problems/serialize-and-deserialize-binary-tree/
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
class Codec {
public:

    // Encodes a tree to a single string.
    string serialize(TreeNode* root) {
        if(!root) return "N,";
        string data = "";
        queue<TreeNode*> q;

        q.push(root);
                
        while(!q.empty()){
            TreeNode* n = q.front();
            q.pop();

            if(n) data += to_string(n->val) + ",";
            else data += "N,";

            if(n){
                q.push(n->left);
                q.push(n->right);

            }
        }
        return data;
    }

    // Decodes your encoded data to tree.
    TreeNode* deserialize(string data) {
        if(data == "N,") return NULL;

        stringstream s(data);
        string str;

        getline(s, str, ',');
        TreeNode *root = new TreeNode(stoi(str));

        queue<TreeNode*> q;
        q.push(root);

        while(!q.empty()) {

            TreeNode *node = q.front();
            q.pop();

            getline(s, str, ',');

            if(str == "N") {
                node->left = NULL;
            }
            else {
                TreeNode* leftNode = new TreeNode(stoi(str));
                node->left = leftNode;
                q.push(leftNode);
            }

            getline(s, str, ',');

            if(str == "N") {
                node->right = NULL;
            }
            else {
                TreeNode* rightNode = new TreeNode(stoi(str));
                node->right = rightNode;
                q.push(rightNode);
            }
        }

        return root;
    }
};

// Your Codec object will be instantiated and called as such:
// Codec ser, deser;
// TreeNode* ans = deser.deserialize(ser.serialize(root));
