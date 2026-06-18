class Solution {
  public:
    void dfs(vector<vector<int>> &adj, vector<int> &vis, stack<int> &st, int node){
        vis[node] = 1;
        
        for(auto it : adj[node]){
            if(!vis[it]){
                dfs(adj, vis, st, it);
            }
        }
        st.push(node);
    }
    
    vector<int> topoSort(int n, vector<vector<int>>& edges) {
        // code here
        vector<vector<int>> adj(n);
        for(int i = 0; i < edges.size(); i++){
            int u = edges[i][0];
            int v = edges[i][1];
            adj[u].push_back(v);
        }
        
        vector<int> vis(n, 0);
        stack<int> st;
        
        for(int i = 0; i < n; i++){
            if(!vis[i]){
                dfs(adj, vis, st, i);
            }
        }
        
        vector<int> ans;
        while(!st.empty()){
            ans.push_back(st.top());
            st.pop();
        }
        
        return ans;
        
    }
    
};