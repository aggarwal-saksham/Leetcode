/*
 * Problem #787: Cheapest Flights Within K Stops
 * Difficulty: Medium
 * Submission: Try 3
 * status: Accepted
 * Language: cpp
 * Date: 6/21/2026, 2:10:20 AM
 * Link: https://leetcode.com/problems/cheapest-flights-within-k-stops/
 */

class Solution {
public:
    int findCheapestPrice(int n, vector<vector<int>>& flights, int src, int dst, int k) {
        vector<vector<pair<int, int>>> adj(n + 1);
        for(auto e : flights){
            adj[e[0]].push_back({e[1], e[2]});
        }

        queue<tuple<int, int, int>> q;
        vector<int> dist(n, 1e9);

        dist[src] = 0;
        q.push({0, src, 0});
        
        while(!q.empty()){
            auto[stops, node, d] = q.front();            
            q.pop();
            
            if(stops > k) break;
            for(auto it : adj[node]){
                int adjNode = it.first;
                int w = it.second;
                
                if(d + w < dist[adjNode] && stops <= k){
                    dist[adjNode] = d + w;
                    q.push({stops + 1, adjNode, dist[adjNode]});
                }
            }
            
        }
        return dist[dst] == 1e9 ? -1 : dist[dst];
        
    }
};
