class Solution {
  public:
    void getLeaves(Node* root, vector<int>& v){
        if(!root) return;

        if(!root->left && !root->right){
            v.push_back(root->data);
            return;
        }

        getLeaves(root->left, v);
        getLeaves(root->right, v);
    }

    vector<int> boundaryTraversal(Node *root) {
        if(!root) return {};

        vector<int> ans;
        ans.push_back(root->data);

        Node* temp = root->left;

        while(temp){
            if(temp->left || temp->right)
                ans.push_back(temp->data);

            temp = temp->left ? temp->left : temp->right;
        }

        vector<int> leaves;
        getLeaves(root, leaves);

        if(root->left || root->right)
            ans.insert(ans.end(), leaves.begin(), leaves.end());

        vector<int> r;
        temp = root->right;

        while(temp){
            if(temp->left || temp->right)
                r.push_back(temp->data);

            temp = temp->right ? temp->right : temp->left;
        }

        reverse(r.begin(), r.end());
        ans.insert(ans.end(), r.begin(), r.end());

        return ans;
    }
};