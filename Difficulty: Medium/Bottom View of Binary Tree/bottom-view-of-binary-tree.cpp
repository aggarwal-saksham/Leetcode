class Solution {
  public:
    vector<int> bottomView(Node *root) {
        
        if(!root) return {};
        
        queue<tuple<Node*, int, int>> q;
        map<int, map<int, vector<int>>> nodes;

        q.push({root, 0, 0});

        while(!q.empty()){
            auto [n, v, l] = q.front();
            q.pop();

            nodes[v][l].push_back(n->data);

            if(n->left) q.push({n->left, v - 1, l + 1});
            if(n->right) q.push({n->right, v + 1, l + 1});
        }

        vector<int> ans;

        for(auto it : nodes){
           auto it2 = it.second.rbegin();
            ans.push_back(it2->second.back());
        }

        return ans;
    }
};