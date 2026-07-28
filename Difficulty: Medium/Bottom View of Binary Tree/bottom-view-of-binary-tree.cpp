
class Solution {
  public:
    vector<int> bottomView(Node *root) {
        // code here
        vector<int> ans;
        queue<pair<Node*, int>> q;
        q.push({root, 0});
        map<int, int> level;
        level[0] = root->data;
        
        while(!q.empty()){
            int sz = q.size();
            while(sz--){
                auto[node, v] = q.front();
                q.pop();
                level[v] = node->data;
                if(node->left){
                    q.push({node->left, v - 1});
                }
                if(node->right){
                    q.push({node->right, v + 1});
                }
            }
        }
        for(auto it : level){
            ans.push_back(it.second);
        }
        return ans;
    }
};