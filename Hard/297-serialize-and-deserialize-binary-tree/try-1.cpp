/*
 * Problem #297: Serialize and Deserialize Binary Tree
 * Difficulty: Hard
 * Submission: Try 1
 * status: Accepted
 * Language: cpp
 * Date: 7/27/2025, 2:33:47 AM
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
        if (!root)
            return "#,";

        queue<TreeNode*> q;

        q.push(root);
        string data = "";
        while (!q.empty()) {
            TreeNode* node = q.front();
            q.pop();

            if (!node)
                data += '#,';
            else
                data += to_string(node->val) + ',';

            if (node) {
                q.push(node->left);
                q.push(node->right);
            }
        }

        return data;
    }

    // Decodes your encoded data to tree.
    TreeNode* deserialize(string data) {
        if (data.empty())
            return NULL;

        stringstream s(data);
        string str;

        if (!getline(s, str, ',') || str == "#" || str.empty())
            return NULL;

        TreeNode* root = new TreeNode(stoi(str));
        queue<TreeNode*> q;
        q.push(root);

        while (!q.empty()) {
            TreeNode* node = q.front();
            q.pop();

            if (!getline(s, str, ','))
                break;
            if (!str.empty() && str != "#") {
                node->left = new TreeNode(stoi(str));
                q.push(node->left);
            }

            if (!getline(s, str, ','))
                break;
            if (!str.empty() && str != "#") {
                node->right = new TreeNode(stoi(str));
                q.push(node->right);
            }
        }

        return root;
    }
};

// Your Codec object will be instantiated and called as such:
// Codec ser, deser;
// TreeNode* ans = deser.deserialize(ser.serialize(root));
