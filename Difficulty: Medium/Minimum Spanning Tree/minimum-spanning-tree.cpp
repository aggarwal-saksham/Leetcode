class Solution {
  public:
    int spanningTree(int n, vector<vector<int>>& edges) {
        // code here
        vector<vector<pair<int, int>>> adj(n);
        for(auto &e : edges){
            adj[e[0]].push_back({e[1], e[2]});
            adj[e[1]].push_back({e[0], e[2]});
        }
        
        priority_queue<pair<int, int>, vector<pair<int, int>>,
        greater<>> pq;
        
        pq.push({0, 0});
        vector<int> vis(n, 0);
        int sum = 0;
        
        while(!pq.empty()){
            auto [wt, node] = pq.top();
            pq.pop();
            
            if(vis[node] == 1) continue;
            
            vis[node] = 1;
            sum += wt;
            
            for(auto it : adj[node]){
                auto[nbr, w] = it;
                
                if(!vis[nbr]){
                    pq.push({w, nbr});
                }
            }
        }
        return sum;
    }
};