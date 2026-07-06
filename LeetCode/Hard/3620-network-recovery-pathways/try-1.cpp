/*
 * Problem #3620: Network Recovery Pathways
 * Difficulty: Hard
 * Submission: Try 1
 * status: Accepted
 * Language: cpp
 * Date: 7/3/2026, 12:33:09 PM
 * Link: https://leetcode.com/problems/network-recovery-pathways/
 */

class Solution {
public:
    long long dijkstra(int n, vector<vector<pair<int, int>>> &adj, int mid) {
        
        vector<long long> dist(n, 1e18);
        typedef pair<long long, long long> pii;
        priority_queue<pii, vector<pii>, greater<>> pq;
        
        dist[0] = 0;
        pq.push({0, 0});
        
        while(!pq.empty()){
            auto [d, node] = pq.top();
            pq.pop();
            if (d != dist[node]) continue;
            for(auto it : adj[node]){
                int nbr = it.first;
                int wt = it.second;
                
                if(wt >= mid && d + wt < dist[nbr]){
                    dist[nbr] = d + wt;
                    pq.push({dist[nbr], nbr});
                }
            }
        }
        return dist[n - 1];
    }
    int findMaxPathScore(vector<vector<int>>& edges, vector<bool>& online, long long k) {
        int n = online.size();
        vector<vector<pair<int, int>>> adj(n);
        int l = INT_MAX, h = 0;
        for(auto &e : edges){
            if(!online[e[0]] || !online[e[1]]) continue;
            adj[e[0]].push_back({e[1], e[2]});
            l = min(l, e[2]);
            h = max(h, e[2]);
        }

        long long ans = -1LL;

        while(l <= h){
            int mid = h - (h - l) / 2;
            if(dijkstra(n, adj, mid) <= k){
                ans = mid;
               l = mid + 1;
            }
            else h = mid - 1;
        }
        return (int)ans;
    }
};
