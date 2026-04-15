/*
 * Problem #787: Cheapest Flights Within K Stops
 * Difficulty: Medium
 * Submission: Try 1
 * status: Accepted
 * Language: cpp
 * Date: 6/16/2025, 1:07:02 AM
 * Link: https://leetcode.com/problems/cheapest-flights-within-k-stops/
 */

class Solution {
public:
    int findCheapestPrice(int n, vector<vector<int>>& flights, int src, int dst, int k) {
        vector<vector<pair<int, int>>> adj(n);
        for(int i = 0; i < flights.size(); i++){
            int u = flights[i][0];
            int v = flights[i][1];
            int wt = flights[i][2];
            adj[u].push_back({v, wt});
            
        }

        typedef pair<int, pair<int, int>> pip;
        queue<pip> q;
        vector<int> dist(n, 1e9);
        dist[src] = 0;
        q.push({0, {src, 0}});
        
        while(!q.empty()){
            int stops = q.front().first;
            int node = q.front().second.first;
            int dis = q.front().second.second;
            
            q.pop();
            
            if(stops > k) break;
            for(auto it : adj[node]){
                int adjNode = it.first;
                int w = it.second;
                
                if(dis + w < dist[adjNode] && stops <= k){
                    dist[adjNode] = dis + w;
                    q.push({stops + 1, {adjNode, dist[adjNode]}});
                }
            }
            
        }
        return dist[dst] == 1e9 ? -1 : dist[dst];
        
    }
};
