/*
Definition for Node
class Node {
  public:
    int data;
    Node *left;
    Node *right;

    Node(int val) {
        data = val;
        left = right = nullptr;
    }
}; */

class Solution {
  public:
    int findMaxFork(Node* root, int x) {
        // code here
        int ans = -1;
        // code here
        while(root){
            if(root->data == x) return root->data;
            else if(root->data > x) {
                root = root->left;
            }
            else {
                ans = max(ans, root->data);
                root = root->right;
            }
            
        }
        return ans;
    }
};