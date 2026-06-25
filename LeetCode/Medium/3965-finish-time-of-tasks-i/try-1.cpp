/*
 * Problem #3965: Finish Time of Tasks I
 * Difficulty: Medium
 * Submission: Try 1
 * status: Accepted
 * Language: cpp
 * Date: 6/24/2026, 1:45:14 PM
 * Link: https://leetcode.com/problems/finish-time-of-tasks-i/
 */

class Solution {
public:
    long long dfs(int node, vector<vector<int>>& adj, vector<int>& baseTime,
                  long long mini, long long maxi) {

        if(adj[node].empty()) return baseTime[node];

        for(auto nbr : adj[node]) {
            long long x = dfs(nbr, adj, baseTime, LLONG_MAX, LLONG_MIN);
            mini = min(mini, x);
            maxi = max(maxi, x);
        }

        return 2LL * maxi - mini + baseTime[node];
    }

    long long finishTime(int n, vector<vector<int>>& edges, vector<int>& baseTime) {

        vector<vector<int>> adj(n);

        for(auto &e : edges) {
            adj[e[0]].push_back(e[1]);
        }

        return dfs(0, adj, baseTime, LLONG_MAX, LLONG_MIN);
    }
};
