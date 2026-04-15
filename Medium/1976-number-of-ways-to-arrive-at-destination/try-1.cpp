/*
 * Problem #1976: Number of Ways to Arrive at Destination
 * Difficulty: Medium
 * Submission: Try 1
 * status: Accepted
 * Language: cpp
 * Date: 6/16/2025, 2:05:52 AM
 * Link: https://leetcode.com/problems/number-of-ways-to-arrive-at-destination/
 */

class Solution {
public:
    int countPaths(int n, vector<vector<int>>& roads) {
        int src = 0;
        vector<vector<pair<int, int>>> adj(n);
        for (int i = 0; i < roads.size(); i++) {
            int u = roads[i][0];
            int v = roads[i][1];
            int wt = roads[i][2];
            adj[u].push_back({v, wt});
            adj[v].push_back({u, wt});
        }
        typedef pair<long long, int> pli;
        priority_queue<pli, vector<pli>, greater<pli>> pq;
        vector<int> ways(n, 0);
        vector<long long> dist(n, LLONG_MAX);
        dist[src] = 0;
        ways[src] = 1;
        pq.push({dist[src], src});
        int mod = 1e9 + 7;
        while (!pq.empty()) {
            int node = pq.top().second;
            long long dis = pq.top().first;

            pq.pop();

            for (auto it : adj[node]) {
                int adjNode = it.first;
                int w = it.second;

                if (dis + w < dist[adjNode]) {
                    dist[adjNode] = dis + w;
                    pq.push({dist[adjNode], adjNode});
                    ways[adjNode] = ways[node];
                } else if (dis + w == dist[adjNode]) {

                    ways[adjNode] = (ways[adjNode] + ways[node]) % mod;
                }
            }
        }
        return ways[n - 1];
    }
};
