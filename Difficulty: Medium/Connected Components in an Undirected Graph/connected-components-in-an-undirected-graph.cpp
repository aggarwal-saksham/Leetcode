class Solution {
  public:
    void dfs(vector<vector<int>>& adj, vector<int> &vis, int node, vector<int> &component){
        component.push_back(node);
        vis[node] = 1;
                
        for(auto it : adj[node]){
            if(!vis[it]){
                dfs(adj, vis, it, component);
            }
        }
    }
    
    vector<vector<int>> getComponents(int n, vector<vector<int>>& edges) {
        // code here
        vector<vector<int>> adj(n);
        for(auto e : edges){
          adj[e[0]].push_back(e[1]);  
          adj[e[1]].push_back(e[0]);  
        }
        vector<int> vis(n, 0);

        vector<vector<int>> components;
        
        for(int i = 0; i < n; i++){
            if(!vis[i]) {
                vector<int> component;
                dfs(adj, vis, i, component);
                components.push_back(component);
            }
            
        }
        return components;
    }
};
