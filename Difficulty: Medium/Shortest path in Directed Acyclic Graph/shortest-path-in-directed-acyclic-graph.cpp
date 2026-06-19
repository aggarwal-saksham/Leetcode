class Solution {
  public:
     void dfs(int node, vector<vector<pair<int, int>>> &adj, vector<int> &vis, stack<int> &st){
        vis[node] = 1;
        
        for(auto it : adj[node]){
            int v = it.first;
            if(!vis[v]){
                dfs(v, adj, vis, st);
            }
        }
        
        st.push(node);
    }
    vector<int> shortestPath(int n, int E, vector<vector<int>>& edges) {
        // code here
        vector<vector<pair<int, int>>> adj(n);
        
        for(auto e : edges){
            adj[e[0]].push_back({e[1], e[2]});
        }
    
        vector<int> vis(n);
        stack<int> st;
        
        for(int i = 0; i < n; i++){
            if(!vis[i]){
                dfs(i, adj, vis, st);
            }
        }
        
        vector<int> dist(n, 1e9);
        dist[0] = 0;
        
        while(!st.empty()){
            int node = st.top();
            st.pop();
            
            for(auto nbr : adj[node]){
                int v = nbr.first; 
                int wt = nbr.second;
                if(wt + dist[node] < dist[v]){
                    dist[v] = wt + dist[node];
                }
            }
        }
        for(int i = 0; i <n; i++){
            if(dist[i] == 1e9) dist[i] = -1;
        }
        return dist;
    }
};
