
class Solution {
  public:
    vector<int> leftView(Node *root) {
        // code here
        queue<Node*> q;
        vector<int> ans;
        if(!root) return ans; 
        q.push(root);
        while(!q.empty()){
            int x = q.size();
            Node* node = q.front();
            q.pop();
            ans.push_back(node->data);

            if(node->left) q.push(node->left);
            if(node->right) q.push(node->right);
            x--;
            while(x > 0){
                Node* node = q.front();
                q.pop();

                if(node->left) q.push(node->left);
                if(node->right) q.push(node->right);
                x--;
            }


        }
        return ans;
    }
};