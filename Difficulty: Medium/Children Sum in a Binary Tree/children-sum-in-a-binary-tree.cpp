/*

class Node {
public:
    int data;
    Node* left;
    Node* right;

    Node(int data) {
        data = data;
        left = nullptr;
        right = nullptr;
    }
};

*/

class Solution {
    int check(Node* root){
        if(!root->left && !root->right) return root->data;
        
        int l = (root->left) ? check(root->left) : 0;
        int r = (root->right) ? check(root->right) : 0;
        
        if(l + r != root->data) return -1;
        
        if(l == -1 || r == -1) return -1;
        
        else return root->data;
    }
  public:
    bool isSumProperty(Node *root) {
        // code here
        return check(root) != -1;
    }
};