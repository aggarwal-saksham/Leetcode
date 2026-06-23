/*
 * Problem #743: Network Delay Time
 * Difficulty: Medium
 * Submission: Try 2
 * status: Accepted
 * Language: cpp
 * Date: 6/21/2026, 1:47:49 AM
 * Link: https://leetcode.com/problems/network-delay-time/
 */

class Solution {
public:
    int networkDelayTime(vector<vector<int>>& times, int n, int k) {
        vector<vector<pair<int, int>>> adj(n + 1);
        for(auto e : times){
            adj[e[0]].push_back({e[1], e[2]});
        }
        
         vector<int> dist(n + 1, 1e9);
        typedef pair<int, int> pii;
        priority_queue<pii, vector<pii>, greater<>> pq;
        
        dist[k] = 0;
        pq.push({0, k});
        
        while(!pq.empty()){
            auto [d, node] = pq.top();
            pq.pop();
            
            for(auto it : adj[node]){
                int nbr = it.first;
                int wt = it.second;
                
                if(dist[node] + wt < dist[nbr]){
                    dist[nbr] = dist[node] + wt;
                    pq.push({dist[nbr], nbr});
                }
            }
        }

        int ans = 0;
        for(int i = 1; i <= n; i++) {
            if(dist[i] == 1e9)
                return -1;

            ans = max(ans, dist[i]);
        }

        return ans;    
    }
};
