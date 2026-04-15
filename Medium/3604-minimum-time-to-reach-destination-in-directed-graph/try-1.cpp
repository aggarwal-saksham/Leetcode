/*
 * Problem #3604: Minimum Time to Reach Destination in Directed Graph
 * Difficulty: Medium
 * Submission: Try 1
 * status: Accepted
 * Language: cpp
 * Date: 7/5/2025, 9:18:09 PM
 * Link: https://leetcode.com/problems/minimum-time-to-reach-destination-in-directed-graph/
 */

class Solution {
public:
    int minTime(int n, vector<vector<int>>& edges) {
        typedef pair<int, int> pii;
        
        vector<vector<pair<int, pii>>> adj(n);
        

        for (auto e : edges) {
            
            adj[e[0]].push_back({e[1], {e[2], e[3]}});
           
        }
        priority_queue<pii, vector<pii>, greater<pii>> pq;
        vector<int> time(n, INT_MAX);
        pq.push({0, 0});
        time[0] = 0;

        while (!pq.empty()) {
            auto it =  pq.top(); 
            int t = it.first;
            int u = it.second;
            pq.pop();
            if (t > time[u]) continue;
            if (u == n - 1) return t;

            if (t + 1 < time[u]) {
                time[u] = t + 1;
                pq.push({t + 1, u});
            }

            for (auto it : adj[u]) {
                int v = it.first;
                int s = it.second.first;
                int e = it.second.second;
                if (t >= s && t <= e && t + 1 < time[v]) {
                    time[v] = t + 1;
                    pq.push({t + 1, v});
                } else if (t < s && s + 1 < time[v]) {
                    time[v] = s + 1;
                    pq.push({s + 1, v});
                }
            }
        }

        return -1;

        
    }
};
