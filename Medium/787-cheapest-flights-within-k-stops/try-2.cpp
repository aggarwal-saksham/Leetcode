/*
 * Problem #787: Cheapest Flights Within K Stops
 * Difficulty: Medium
 * Submission: Try 2
 * status: Accepted
 * Language: cpp
 * Date: 5/14/2026, 4:30:07 PM
 * Link: https://leetcode.com/problems/cheapest-flights-within-k-stops/
 */

class Solution {
public:
    int findCheapestPrice(int n, vector<vector<int>>& flights, int src, int dst, int k) {
        vector<int> dist(n, INT_MAX);
    dist[src] = 0;
    for (int i = 0; i <= k; i++) {
        vector<int> temp = dist;          // snapshot
        for (auto& f : flights) {
            int u=f[0], v=f[1], p=f[2];
            if (dist[u]!=INT_MAX && dist[u]+p < temp[v])
                temp[v] = dist[u]+p;
        }
        dist = temp;
    }
    return dist[dst]==INT_MAX ? -1 : dist[dst];

    }
};
