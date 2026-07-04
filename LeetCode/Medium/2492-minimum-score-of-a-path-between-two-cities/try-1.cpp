/*
 * Problem #2492: Minimum Score of a Path Between Two Cities
 * Difficulty: Medium
 * Submission: Try 1
 * status: Accepted
 * Language: cpp
 * Date: 7/4/2026, 12:05:25 PM
 * Link: https://leetcode.com/problems/minimum-score-of-a-path-between-two-cities/
 */


class Solution {
public:
    int minScore(int n, vector<vector<int>>& edges) {
        vector<vector<pair<int, int>>> adj(n + 1);
        for(auto &e : edges){
            adj[e[0]].push_back({e[1], e[2]});
            adj[e[1]].push_back({e[0], e[2]});
        }

        vector<int> vis(n + 1, 0);
        queue<int> q;

        q.push(1);
        int mini = 1e9;

        while(!q.empty()){
            auto node = q.front();
            q.pop();

            vis[node] = 1;

            for(auto &it : adj[node]){
                auto [nbr, d] = it;
                if(d < mini) mini = d;
                if(!vis[nbr]) q.push(nbr);

            }

        }
        return mini;
    }
};
