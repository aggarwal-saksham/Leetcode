/*
 * Problem #297: Serialize and Deserialize Binary Tree
 * Difficulty: Hard
 * Submission: Try 2
 * status: Accepted
 * Language: cpp
 * Date: 7/27/2025, 5:48:05 PM
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
            return "";

        queue<TreeNode*> q;

        q.push(root);
        string data = "";
        while (!q.empty()) {
            TreeNode* node = q.front();
            q.pop();

            if (!node)
                data += 'null,';
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

        vector<string> tokens;
        string temp = "";
        for (char c : data) {
            if (c == ',') {
                tokens.push_back(temp);
                temp = "";
            } else {
                temp += c;
            }
        }
        tokens.push_back(temp);

        if (tokens[0] == "null" || tokens[0].empty())
            return NULL;

        TreeNode* root = new TreeNode(stoi(tokens[0]));
        queue<TreeNode*> q;
        q.push(root);

        int i = 1;
        while (!q.empty() && i < tokens.size()) {
            TreeNode* node = q.front();
            q.pop();

            if (i < tokens.size() && tokens[i] != "null" &&
                !tokens[i].empty()) {
                node->left = new TreeNode(stoi(tokens[i]));
                q.push(node->left);
            }
            i++;

            if (i < tokens.size() && tokens[i] != "null" &&
                !tokens[i].empty()) {
                node->right = new TreeNode(stoi(tokens[i]));
                q.push(node->right);
            }
            i++;
        }

        return root;
    }
};

// Your Codec object will be instantiated and called as such:
// Codec ser, deser;
// TreeNode* ans = deser.deserialize(ser.serialize(root));
