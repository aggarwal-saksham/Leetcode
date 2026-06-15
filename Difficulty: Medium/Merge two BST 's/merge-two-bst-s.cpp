/*
class Node {
  public:
    int data;
    Node *left;
    Node *right;

    Node(int data) {
        data = data;
        left = right = NULL;
    }
};
*/

class Solution {
  public:
    void inorderTraversal(Node* root, vector<int> &inorder) {
        
        stack<Node*> st;
        if(!root) return ;
        Node* node = root;
        while(true){
            if(node){
                st.push(node);
                node = node->left;
            }

            else{
                if(st.empty()) break;

                node = st.top();
                st.pop();

                inorder.push_back(node->data);

                node = node->right;
            }

        }
        return;
    }
    vector<int> merge(Node *root1, Node *root2) {
        // code here
        vector<int> v1, v2, ans;
        inorderTraversal(root1, v1);
        inorderTraversal(root2, v2);
        
        
        int i = 0, j = 0;
        while(i < v1.size() && j < v2.size()){
            if(v1[i] < v2[j]){
                ans.push_back(v1[i]);
                i++;
            }
            else{
                ans.push_back(v2[j]);
                j++;
            }
        }
        while(i < v1.size()){
            ans.push_back(v1[i]);
            i++;
        }
        while(j < v2.size()){
            ans.push_back(v2[j]);
            j++;
        }
        return ans;
    }
};