/*
 * Problem #1584: Min Cost to Connect All Points
 * Difficulty: Medium
 * Submission: Try 2
 * status: Accepted
 * Language: cpp
 * Date: 6/23/2026, 5:04:57 PM
 * Link: https://leetcode.com/problems/min-cost-to-connect-all-points/
 */

class Solution {
public:
    int minCostConnectPoints(vector<vector<int>>& points) {
        int n = points.size();
        vector<vector<int>> edges;

        for (int i = 0; i < n; i++) {
            for (int j = i + 1; j < n; j++) {
                int dist = abs(points[i][0] - points[j][0]) +
                           abs(points[i][1] - points[j][1]);
                edges.push_back({i, j, dist});
            }
        }

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
