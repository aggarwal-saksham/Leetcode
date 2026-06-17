class Solution {
  public:
    int countConnected(int n, vector<vector<int>>& edges) {
        // code here
        vector<vector<int>> adj(n);
        for(auto e : edges){
          adj[e[0]].push_back(e[1]);  
          adj[e[1]].push_back(e[0]);  
        }
        vector<int> vis(n, 0);
        queue<int> q;
        
        int cnt = 0;
        for(int i = 0; i < n; i++){
            if(!vis[i]) cnt++;
            vis[i] = 1;
            q.push(i);
            
            while(!q.empty()){
                int node = q.front();
                q.pop();
                
                for(auto &nbr : adj[node]){
                    if(!vis[nbr]){
                        vis[nbr] = 1;
                        q.push(nbr);
                    }
                }
            }
            
        }
        return cnt;
    }
};