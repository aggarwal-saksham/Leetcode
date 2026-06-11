
class Solution {
  public:
    vector<vector<int>> ans;
    
    void dfs(Node* root, vector<int> path){
        path.push_back(root->data);
        
        if(!root->left && !root->right){
            ans.push_back(path);
            return;
        }
        
        if(root->left) dfs(root->left, path);
        if(root->right) dfs(root->right, path);
        
        
    }
    vector<vector<int>> Paths(Node* root) {
        vector<int> path;
        // code here
        dfs(root, path);
        return ans;
    }
};