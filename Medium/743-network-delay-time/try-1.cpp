/*
 * Problem #743: Network Delay Time
 * Difficulty: Medium
 * Submission: Try 1
 * status: Accepted
 * Language: cpp
 * Date: 6/16/2025, 12:44:32 AM
 * Link: https://leetcode.com/problems/network-delay-time/
 */

class Solution {
public:
    int networkDelayTime(vector<vector<int>>& times, int n, int k) {
        vector<vector<pair<int, int>>> adj(n+1);
        for(int i = 0; i < times.size(); i++){
            int u = times[i][0];
            int v = times[i][1];
            int wt = times[i][2];
            adj[u].push_back({v, wt});
        }
        typedef pair<int, int> pii;
        priority_queue<pii, vector<pii>, greater<pii>> pq;
        vector<int> dist(n+1, 1e9);
        dist[k] = 0;
        pq.push({0, k});
        
        while(!pq.empty()){
            int node = pq.top().second;
            int dis = pq.top().first;
            
            pq.pop();
            
            for(auto it : adj[node]){
                int adjNode = it.first;
                int w = it.second;
                
                if(dis + w < dist[adjNode]){
                    dist[adjNode] = dis + w;
                    pq.push({dist[adjNode], adjNode});
                }
            }
            
        }
        int maxi = 0;
        for(int i = 1; i <= n; i++){
            maxi = max(maxi, dist[i]);
        }

        return (maxi == 1e9) ? -1 : maxi;
    }
};
