class Solution {
  public:
    bool dfs(vector<vector<int>> &adj, vector<int> & vis, vector<int> &pathvis, int node){
        vis[node] = 1;
        pathvis[node] = 1;
        
        for(auto it : adj[node]){
            if(!vis[it]){
                if(dfs(adj, vis, pathvis, it)) return true;
            }
            
            else if(vis[it] && pathvis[it]) return true;
        }
        
        pathvis[node] = 0;
        return false;
    }
    bool isCyclic(int V, vector<vector<int>> &edges) {
        // code here
        vector<vector<int>> adj(V);
        for(int i = 0; i < edges.size(); i++){
            int u = edges[i][0];
            int v = edges[i][1];
            adj[u].push_back(v);
        }
        
        vector<int> vis(V, 0);
        vector<int> pathvis(V, 0);
        
        for(int i = 0; i < V; i++){
            if(!vis[i]){
                if(dfs(adj, vis, pathvis, i)) return true;
            }
        }
        return false;
    }
};