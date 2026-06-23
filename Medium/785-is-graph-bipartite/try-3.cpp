/*
 * Problem #785: Is Graph Bipartite?
 * Difficulty: Medium
 * Submission: Try 3
 * status: Accepted
 * Language: cpp
 * Date: 6/19/2026, 1:29:59 AM
 * Link: https://leetcode.com/problems/is-graph-bipartite/
 */

class Solution {
public:
    bool isBipartite(vector<vector<int>>& graph) {
        int n = graph.size();
        vector<int> color(n, -1);


        for(int i = 0; i < n; i++){
            if(color[i] != -1) continue;
            queue<pair<int, int>> q;
            q.push({i, 1});
            color[i] = 1;

            while(!q.empty()){
                auto [node, c] = q.front();
                q.pop();

                for(int nbr : graph[node]){
                    if(color[nbr] == -1){
                        color[nbr] = !c;
                        q.push({nbr, !c});
                    }

                    else if(color[nbr] == c) return false;
                }
            }

        }
        return true;
    }
};
