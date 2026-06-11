
class Solution {
  public:
     
    
    vector<int> topView(Node *root) {
        // code here
        queue<tuple<Node*, int>> q;
        map<int, int> mpp;
        
        q.push({root, 0});
        
        while(!q.empty()){
            auto[n, v] = q.front();
            q.pop();
            
            if(!mpp.count(v)) mpp[v] = n->data;
            
            if(n->left) q.push({n->left, v - 1});
            if(n->right) q.push({n->right, v + 1});
        }
        vector<int> ans;
        for(auto it : mpp){
            ans.push_back(it.second);
        }
        return ans;
        
    }
};