/* BST Node
class Node {
   public:
    int data;
    Node *left;
    Node *right;

    Node(int x){
        data = x;
        left = NULL;
        right = NULL;
    }
};
*/

class Solution {
  public:
    vector<Node*> findPreSuc(Node* root, int x) {
        // code here
        
        Node* temp = root;
        Node* ceilN = nullptr;
        Node* floorN = nullptr;     
        while(temp){
            if(temp->data > x) {
                ceilN = temp;
                temp = temp->left;
            }
            
            else temp = temp->right;
        }
        temp = root;
        while(temp){
            if(temp->data < x){
                floorN = temp;
                temp = temp->right;
            }
            else temp = temp->left;
        }
        return{floorN, ceilN};
    }
};