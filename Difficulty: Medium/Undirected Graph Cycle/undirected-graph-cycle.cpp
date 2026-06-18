class Solution {
  public:
    bool detect(vector<vector<int>> &adj,  vector<int> &vis, int node){
        queue<pair<int, int>> q;
        vis[node] = 1;
        q.push({node, -1});
        
        while(!q.empty()){
            auto[node, parent] = q.front();
            q.pop();
            
            for(auto &nbr : adj[node]){
                if(!vis[nbr]){
                    vis[nbr] = 1;
                    q.push({nbr, node});
                }
                else if(nbr != parent){
                    return true;
                }
            }
        }
        return false;
        
    }
    bool isCycle(int n, vector<vector<int>>& edges) {
        // Code here
        vector<vector<int>> adj(n);
        for(auto &e : edges){
            adj[e[0]].push_back(e[1]);
            adj[e[1]].push_back(e[0]);
        }
        
        vector<int> vis(n, 0);
        
        for(int i = 0; i < n; i++){
            if(!vis[i]){
                if(detect(adj, vis, i)) return true;
            }
        }
        return false;
    }
};