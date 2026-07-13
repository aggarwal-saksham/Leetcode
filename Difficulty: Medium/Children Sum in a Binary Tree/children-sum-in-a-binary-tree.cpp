
class Solution {
  public:
    int rec(Node *root){
        if(!root) return 0;
        if(!root->left && !root->right) return root->data;
        int left = rec(root->left);
        int right = rec(root->right);
        if(left == -1 || right == -1) return -1;
        if(left + right != root->data) return -1;
        return root->data;
    }
    bool isSumProperty(Node *root) {
        // code here
        return rec(root) != -1;
    }
};