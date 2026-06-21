class Solution {
  public:
    vector<int> dijkstra(int n, vector<vector<int>> &edges, int src) {
        // Code here
        vector<vector<pair<int, int>>> adj(n);
        for(auto &e : edges){
            adj[e[0]].push_back({e[1], e[2]});
            adj[e[1]].push_back({e[0], e[2]});
        }
        
        vector<int> dist(n, 1e9);
        typedef pair<int, int> pii;
        priority_queue<pii, vector<pii>, greater<>> pq;
        
        dist[src] = 0;
        pq.push({0, src});
        
        while(!pq.empty()){
            auto [d, node] = pq.top();
            pq.pop();
            
            for(auto it : adj[node]){
                int nbr = it.first;
                int wt = it.second;
                
                if(d + wt < dist[nbr]){
                    dist[nbr] = d + wt;
                    pq.push({dist[nbr], nbr});
                }
            }
        }
        return dist;
    }
};