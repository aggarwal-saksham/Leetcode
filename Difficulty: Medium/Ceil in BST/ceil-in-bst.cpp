/*
Definition for Node
class Node {
  public:
    int data;
    Node* left;
    Node* right;

    Node(int data) {
        data = data;
        left = right = nullptr;
    }
};
*/

class Solution {
  public:
    int findCeil(Node* root, int x) {
        int ans = INT_MAX;
        // code here
        while(root){
            if(root->data == x) return root->data;
            else if(root->data > x) {
                ans = min(ans, root->data);
                root = root->left;
            }
            else root = root->right;
            
        }
        return ans == INT_MAX ? -1 : ans;
    }
};
