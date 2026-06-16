/* Tree node structure  used in the program

struct Node {
    int data;
    Node *left;
    Node *right;

    Node(int val) {
        data = val;
        left = right = NULL;
    }
};*/

class Solution {
  public:
    int ans = 0;
    struct Info {
        int mn, mx, sz;
    };
    
    Info dfs(Node* root) {
        if (!root) return {INT_MAX, INT_MIN, 0};
    
        Info l = dfs(root->left);
        Info r = dfs(root->right);
    
        if (root->data > l.mx && root->data < r.mn) {
            int sz = l.sz + r.sz + 1;
            ans = max(ans, sz);
    
            return {
                min(root->data, l.mn),
                max(root->data, r.mx),
                sz
            };
        }
    
        return {INT_MIN, INT_MAX, 0};
    }
        /*You are required to complete this method */
        // Return the size of the largest sub-tree which is also a BST
        int largestBst(Node *root) {
            // Your code here
            dfs(root);
            return ans;
        }
    };