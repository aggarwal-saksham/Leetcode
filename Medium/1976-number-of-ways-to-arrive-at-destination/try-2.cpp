/*
 * Problem #1976: Number of Ways to Arrive at Destination
 * Difficulty: Medium
 * Submission: Try 2
 * status: Accepted
 * Language: cpp
 * Date: 6/21/2026, 6:30:27 PM
 * Link: https://leetcode.com/problems/number-of-ways-to-arrive-at-destination/
 */

class Solution {
public:
    int countPaths(int n, vector<vector<int>>& roads) {
        int mod = 1e9 + 7;
        vector<vector<pair<int, int>>> adj(n);
        for(auto e : roads){
            adj[e[0]].push_back({e[1], e[2]});
            adj[e[1]].push_back({e[0], e[2]});
        }
        
        vector<long long> dist(n, 1e18), ways(n, 0);
        typedef pair<long long, int> pii;
        priority_queue<pii, vector<pii>, greater<>> pq;
        
        dist[0] = 0;
        ways[0] = 1;
        pq.push({0, 0});
        
        while(!pq.empty()){
            auto [d, node] = pq.top();
            pq.pop();
            
            for(auto it : adj[node]){
                int nbr = it.first;
                int wt = it.second;
                
                if(d + wt < dist[nbr]){
                    dist[nbr] = d + wt;
                    pq.push({dist[nbr], nbr});
                    ways[nbr] = ways[node];
                }
                else if(d + wt == dist[nbr]){
                    ways[nbr] = (ways[nbr] + ways[node]) % mod;
                }
            }
        }

        
        return ways[n - 1] % mod;
    }
};
